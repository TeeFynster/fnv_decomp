
// @fnv 0x00a76540
bool NiPixelFormat::operator==(const NiPixelFormat& other) const throw()
{
    if (other.m_eFormat != m_eFormat ||
        other.m_uiObjectFlags != m_uiObjectFlags ||
        other.m_eTiling != m_eTiling ||
        other.m_ucBitsPerPixel != m_ucBitsPerPixel)
        return false;
    if (other.m_uiRendererHint != m_uiRendererHint &&
        m_uiRendererHint != 0xffffffff &&
        other.m_uiRendererHint != 0xffffffff)
        return false;

    for (int i = 0; i < NUM_COMPS; ++i)
    {
        if (other.m_akComponents[i].m_eComponent != m_akComponents[i].m_eComponent ||
            other.m_akComponents[i].m_eRepresentation != m_akComponents[i].m_eRepresentation ||
            other.m_akComponents[i].m_ucBits != m_akComponents[i].m_ucBits ||
            other.m_akComponents[i].m_bSigned != m_akComponents[i].m_bSigned)
            return false;
    }
    return true;
}

// @fnv 0x00a765c0
bool NiPixelFormat::operator!=(const NiPixelFormat& other) const
{
    if (other.m_eFormat != m_eFormat ||
        other.m_uiObjectFlags != m_uiObjectFlags ||
        other.m_eTiling != m_eTiling ||
        other.m_ucBitsPerPixel != m_ucBitsPerPixel)
        return true;
    if (other.m_uiRendererHint != m_uiRendererHint &&
        m_uiRendererHint != 0xffffffff &&
        other.m_uiRendererHint != 0xffffffff)
        return true;

    for (int i = 0; i < NUM_COMPS; ++i)
    {
        if (other.m_akComponents[i].m_eComponent != m_akComponents[i].m_eComponent ||
            other.m_akComponents[i].m_eRepresentation != m_akComponents[i].m_eRepresentation ||
            other.m_akComponents[i].m_ucBits != m_akComponents[i].m_ucBits ||
            other.m_akComponents[i].m_bSigned != m_akComponents[i].m_bSigned)
            return true;
    }
    return false;
}

// @fnv 0x00a62230
unsigned char NiPixelFormat::GetPixelBitData(Component component) const
{
    unsigned char bits = 0;
    for (unsigned int i = 0; i < NUM_COMPS; ++i)
    {
        if (m_akComponents[i].m_eComponent == component)
        {
            if (m_uiObjectFlags & 1)
                return bits;
            bits += m_akComponents[i].m_ucBits;
            return m_ucBitsPerPixel - bits;
        }
        bits += m_akComponents[i].m_ucBits;
    }
    return 0;
}
