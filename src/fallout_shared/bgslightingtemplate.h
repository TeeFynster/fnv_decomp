// Unit-local TESFile return-type shim for the lighting template loader.
#ifndef FNV_BGSLIGHTINGTEMPLATE_UNIT_H
#define FNV_BGSLIGHTINGTEMPLATE_UNIT_H

#include "layout_support.h"
#include "../../include/TESForm.h"
#include "TESFile.h"

// The 2008 BGSLightingTemplate.cpp saw a 32-bit TESFile::GetTESForm: the Load
// form check compares the call result with cmp eax,imm and no movzx, which is
// unreproducible through the closure's unsigned char declaration (any use of
// a uchar call result in a 32-bit compare extends it). The shim below recovers
// the original static type; it binds the real GetTESForm target.
struct TESFileFormInt : public TESFile
{
    int GetTESForm();
};
#endif
