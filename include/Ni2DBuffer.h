#pragma once

#include "NiObject.h"
#include "NiRefObject.h"

class NiPixelFormat;

class Ni2DBuffer : public NiObject
{
public:
    enum MultiSamplePreference
    {
        MULTISAMPLE_NONE,
        MULTISAMPLE_2,
        MULTISAMPLE_4,
        MULTISAMPLE_8
    };

    // Gamebryo's renderer-specific data of a 2D buffer (the DX9 renderer derives
    // NiDX92DBufferData from it). Its own vftable is never emitted; its virtuals are
    // read off the subclasses' vftables (NiDX92DBufferData 0x010eeed4 and kin).
    class RendererData : public NiRefObject
    {
    public:
        RendererData() throw();
        virtual ~RendererData();
        // Slot 2: 0x00e7cd40 (returns 0) in every DX9 buffer-data vftable; the name
        // is not known.
        virtual void* vf02();

        void DecRefCount();
        unsigned int GetWidth() const
        {
            return m_pkBuffer->GetWidth();
        }
        unsigned int GetHeight() const
        {
            return m_pkBuffer->GetHeight();
        }
        MultiSamplePreference GetMSAAPref() const
        {
            return m_eMSAAPref;
        }

        Ni2DBuffer* m_pkBuffer;                 // 0x08
        const NiPixelFormat* m_pkPixelFormat;   // 0x0C
        MultiSamplePreference m_eMSAAPref;      // 0x10
    };

    Ni2DBuffer() throw();
    virtual ~Ni2DBuffer();

    virtual bool CopyRectTo(Ni2DBuffer* pkDest, void* pkSrcRect, unsigned int uiDestX, unsigned int uiDestY);
    virtual bool CopySurface(Ni2DBuffer* pkDest, void* pkSrcRect, void* pkDestRect, int ePref);
    virtual bool CreateRendererData(const NiPixelFormat&, unsigned int);

    const NiRTTI* GetType() const;
    unsigned int GetWidth() const
    {
        return m_uiImageWidth;
    }
    unsigned int GetHeight() const
    {
        return m_uiImageHeight;
    }
    bool IsKindOfType(const NiRTTI* target) const;
    bool CreateRendererData(const NiPixelFormat&, MultiSamplePreference);
    // 0x00a8f140, out of line: replaces m_pRendererData, keeping the reference count.
    void SetRendererData(RendererData* pkRendererData);
    static Ni2DBuffer* Create(unsigned int width, unsigned int height);
    // 0x00a8f2c0: a new buffer of the given size that holds pkData.
    static Ni2DBuffer* Create(unsigned int uiWidth, unsigned int uiHeight, RendererData* pkData);

    unsigned int m_uiImageWidth;
    unsigned int m_uiImageHeight;
    void* m_pRendererData;
};
