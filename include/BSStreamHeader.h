#pragma once

// The NIF file header Bethesda's streams read after the Gamebryo header: the exporter's author and the two export-info
// strings (process and export script), 196 bytes.
struct BSStreamHeader
{
    unsigned int m_uiVersion;    // +0x00
    char m_acAuthor[64];         // +0x04
    char m_acProcessScript[64];  // +0x44
    char m_acExportScript[64];   // +0x84
};
