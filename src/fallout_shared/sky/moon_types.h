// fallout_shared/sky/moon_types.h: declares SkyObject, Moon
#ifndef FNV_MOON_PRIVATE_TYPES_H
#define FNV_MOON_PRIVATE_TYPES_H

#include <stddef.h>
#define MOON_ASSERT_I(x, y) typedef char moon_assert_##y[(x) ? 1 : -1]
#define MOON_ASSERT_II(x, y) MOON_ASSERT_I(x, y)
#define MOON_ASSERT(x) MOON_ASSERT_II(x, __LINE__)
// BSStringT, NiPoint3, AutoMemContext/MEM_CONTEXT come from canonical headers (explicit ../../../include/ path: src/fallout_shared shadows it).
// NiPointer stays a unit-local superset (same layout): out-of-line ctor(T*)/dtor/operator=/T*/->/==/!= on NiNode/NiTriShape,
// which have no canonical header yet (the canonical NiPointer bodies need a complete T).
#include "../../../include/layout_support.h"
#include "../../../include/NiPoint3.h"
#include "../../../include/AutoMemContext.h"
class NiNode;
class NiTriShape;
class Sky;
#pragma pack(push, 4)
template <class T> class NiPointer
{
  public:
    NiPointer(T* object);
    ~NiPointer();
    NiPointer& operator=(T* object);
    operator T*() const;
    T* operator->() const;
    bool operator==(T* object) const;
    bool operator!=(T* object) const;
    T* m_pObject;
};
#pragma pack(pop)
class SkyObject
{
  public:
    SkyObject();
    virtual ~SkyObject();
    virtual NiNode* GetRoot() const;
    virtual void Initialize(NiNode* root);
    virtual void Update(Sky* sky, float elapsed);
    NiPointer<NiNode> m_pRootNode;
};
class Moon : public SkyObject
{
  public:
    enum UpdateStatus
    {
        US_NOT_REQUIRED = 0,
        US_WHEN_CULLED = 1,
        US_INITIALIZE = 2
    };
    Moon(const char* name, float fadeStart, float fadeEnd, float shadowEarlyFade, float speed, float zOffset,
         unsigned int size);
    virtual ~Moon();
    virtual void Initialize(NiNode* root, const char* name);
    virtual void Update(Sky* sky, float elapsed);
    static bool IsMoonVisible(const Sky* sky);
    float GetMoonVisibility();
    float GetMoonShadowVisibility();
    NiPointer<NiNode> m_pMoonNode;
    NiPointer<NiNode> m_pMoonShadowNode;
    NiPointer<NiTriShape> m_pMoonShape;
    NiPointer<NiTriShape> m_pMoonShadowShape;
    BSStringT<char> m_kMoonTexturePaths[8];
    float m_fFadeStartAngle;
    float m_fFadeEndAngle;
    float m_fFadeAngleRange;
    float fSpeed;
    float m_fGlyphVerticalOffset;
    unsigned int iSize;
    UpdateStatus m_eUpdateStatus;
    float fPos;
    float m_fValue;
};
MOON_ASSERT(sizeof(NiPointer<NiNode>) == 4);
MOON_ASSERT(sizeof(BSStringT<char>) == 8);
MOON_ASSERT(sizeof(SkyObject) == 8);
MOON_ASSERT(sizeof(Moon) == 0x7c);
MOON_ASSERT(offsetof(Moon, m_pMoonNode) == 0x8);
MOON_ASSERT(offsetof(Moon, m_pMoonShadowNode) == 0xc);
MOON_ASSERT(offsetof(Moon, m_pMoonShape) == 0x10);
MOON_ASSERT(offsetof(Moon, m_pMoonShadowShape) == 0x14);
MOON_ASSERT(offsetof(Moon, m_kMoonTexturePaths) == 0x18);
MOON_ASSERT(offsetof(Moon, m_fFadeStartAngle) == 0x58);
MOON_ASSERT(offsetof(Moon, m_fFadeEndAngle) == 0x5c);
MOON_ASSERT(offsetof(Moon, m_fFadeAngleRange) == 0x60);
MOON_ASSERT(offsetof(Moon, fSpeed) == 0x64);
MOON_ASSERT(offsetof(Moon, m_fGlyphVerticalOffset) == 0x68);
MOON_ASSERT(offsetof(Moon, iSize) == 0x6c);
MOON_ASSERT(offsetof(Moon, m_eUpdateStatus) == 0x70);
MOON_ASSERT(offsetof(Moon, fPos) == 0x74);
MOON_ASSERT(offsetof(Moon, m_fValue) == 0x78);
#endif
