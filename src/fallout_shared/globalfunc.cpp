#include "../../include/SettingT.h"
#include "../../include/PathingGraphNode.h"
// fallout_shared/globalfunc.cpp: BipedNodeNames, NiAVObject, ActorMover, PathingGraphNode and more (110 functions)

#include "../../include/NiPointer.h"
#include "../../include/TESDataHandler.h"
#include "../../include/bhkWorld.h"
#include "../../include/ActorMover.h"
#include "../../include/BSFadeNode.h"
#include "../../include/BSSysInfoSystemUtility.h"
#include "../../include/EffectSetting.h"
#include "../../include/NiBound.h"
#include "../../include/NiControllerManager.h"
#include "../../include/NiLines.h"
#include "../../include/NiTexture.h"
#include "../../include/NiColorA.h"
#include "../../include/TES.h"
#include "../../include/TESRecipe.h"
#include "../../include/TESTopicInfoData.h"
#include "../../include/bhkMouseSpringAction.h"
#include "../../include/bhkSerializable.h"
#include "../../include/bhkUnaryAction.h"
#include "../../include/NiPoint3.h"
// In-class bodies of the former Point stand-in.
inline NiPoint3 NiPoint3::operator-() const
{
    return NiPoint3(-x, -y, -z);
}
__forceinline NiPoint3 NiPoint3::operator*(float scalar) const
{
    return NiPoint3(scalar * x, scalar * y, scalar * z);
}
__forceinline NiPoint3 NiPoint3::operator/(float scalar) const
{
    float inverse = 1.0f / scalar;
    return NiPoint3(x * inverse, y * inverse, z * inverse);
}
inline bool NiPoint3::operator==(const NiPoint3& other) const
{
    return other.x == x && other.y == y && other.z == z;
}
// In-class bodies of the former NiPoint3_ext stand-in.
inline NiPoint3::NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
{}
inline NiPoint3 NiPoint3::operator-(const NiPoint3& kRhs) const
{
    return NiPoint3(x - kRhs.x, y - kRhs.y, z - kRhs.z);
}
inline NiPoint3 NiPoint3::operator+(const NiPoint3& kRhs) const
{
    return NiPoint3(x + kRhs.x, y + kRhs.y, z + kRhs.z);
}
inline float NiPoint3::operator*(const NiPoint3& point) const
{
    return x * point.x + y * point.y + z * point.z;
}
inline NiPoint3 operator*(float scalar, const NiPoint3& point)
{
    return NiPoint3(scalar * point.x, scalar * point.y, scalar * point.z);
}
#include "../../include/BSShaderProperty.h"
#include "../../include/BSShaderNoLightingProperty.h"
#include "../../include/BSXFlags.h"
#include "../../include/FOPipboyManager.h"
#include "../../include/MobileObject.h"
#include "../../include/NiObject.h"
#include "../../include/NiPoint3.h"
#include "../../include/NiShadeProperty.h"
#include "../../include/NiShader.h"
#include "../../include/NiPoint3.h"
#include "../../include/TESObjectREFR.h"
#include "../../include/bhkCollisionObject.h"
#include "../../include/bhkRefObject.h"
#include "../../include/NiNode.h"
#include "../../include/NiGeometry.h"
#include "../../include/NiPlane.h"
#include "../../include/NiObjectNET.h"
#include "../../include/NiAVObject.h"
#include "../../include/NiMultiTargetTransformController.h"
#include "../../include/NiTimeController.h"
#include "../../include/NiRTTI.h"
#include "../../include/NiControllerSequence.h"
#include "../../include/NiTextKeyExtraData.h"
#include "../../include/SETTING_VALUE.h"
#include "../../include/NiMemObject.h"
#include "../../include/NiTransform.h"
#include "../../include/NiMatrix3.h"
#include "../../include/NiGeometryData.h"
#include "../../include/NiFrustumPlanes.h"
#include "../../include/NiPick.h"

#include "../../include/TESCombatStyle.h"

#include "../../include/hkpMotion.h"

// Unit-specific declarations; shared base classes come from include/.

// Keep original out-of-line calls, including NiPoint3 copy assignment.
#pragma inline_depth(0)

class BSShaderPPLightingProperty;

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

class BipedNodeNames
{
  public:
    static void InitializeMultiBounds();
};
extern NiFixedString* DAT_011c61a4;
extern NiFixedString* DAT_011c61a8;
extern NiFixedString* DAT_011c61ac;
extern NiFixedString* DAT_011c61b0;
extern NiFixedString* DAT_011c61b4;
extern NiFixedString* DAT_011c61b8;
extern NiFixedString* DAT_011c61bc;
extern NiFixedString* DAT_011c61c0;
extern NiFixedString* DAT_011c61c4;
extern NiFixedString* DAT_011c61c8;
extern NiFixedString* DAT_011c61cc;
extern NiFixedString* DAT_011c61d0;
extern NiFixedString* DAT_011c61d4;
extern NiFixedString* DAT_011c61d8;
extern NiFixedString* DAT_011c61dc;
extern NiFixedString* DAT_011c61e0;
extern NiFixedString* DAT_011c61e4;
extern NiFixedString* DAT_011c61e8;
extern NiFixedString* DAT_011c61ec;
extern NiFixedString* DAT_011c61f0;
extern NiFixedString* DAT_011c61f4;
extern NiFixedString* DAT_011c61f8;
extern NiFixedString* DAT_011c61fc;
extern NiFixedString* DAT_011c6200;
extern NiFixedString* DAT_011c6204;
extern NiFixedString* DAT_011c6208;
extern NiFixedString* DAT_011c620c;
extern NiFixedString* DAT_011c6210;
extern NiFixedString* DAT_011c6214;
extern NiFixedString* DAT_011c6218;
extern NiFixedString* DAT_011c621c;
extern NiFixedString* DAT_011c6220;
extern NiFixedString* DAT_011c6224;
extern NiFixedString* DAT_011c6228;
extern NiFixedString* DAT_011c622c;
extern NiFixedString* DAT_011c6230;
extern NiFixedString* DAT_011c6234;
extern NiFixedString* DAT_011c6238;
extern NiFixedString* DAT_011c623c;
extern NiFixedString* DAT_011c6240;
extern NiFixedString* DAT_011c6244;
extern NiFixedString* DAT_011c6248;
extern NiFixedString* DAT_011c624c;
extern NiFixedString* DAT_011c6250;
extern NiFixedString* DAT_011c6254;
extern NiFixedString* DAT_011c6258;
extern NiFixedString* DAT_011c625c;
extern NiFixedString* DAT_011c6260;
extern NiFixedString* DAT_011c6264;
extern NiFixedString* DAT_011c6268;
extern NiFixedString* DAT_011c626c;
extern NiFixedString* DAT_011c6270;
extern NiFixedString* DAT_011c6274;
extern NiFixedString* DAT_011c6278;
#include "../../include/LANGUAGE.h"
int GetIsControllerConnected_();
LANGUAGE GetConfiguredLanguage();
const char* LocateString(const char*, const char*);
template <class T> unsigned int BSStringLength(const T*);
int strcat_s(char*, unsigned int, const char*);
extern "C" int memcpy_s(void*, unsigned int, const void*, unsigned int);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma intrinsic(memcpy)
extern "C" unsigned int strlen(const char*);
extern const char* DAT_01189038[4];
extern const char* DAT_01188f84[5];

class NiSourceTexture;

extern TES* g_TES;
extern NiRTTI DAT_011f444c;
bool NiObject_IsKindOf(const NiRTTI*, NiAVObject*);

class TESTopic;
template <class T> class BSSimpleList;

extern NiNode* DAT_011c6328;
extern NiAVObjectPalette* DAT_011c6324;
extern NiRTTI DAT_011f36ac;
const NiFixedString& BSXFlags_Tag();
const NiFixedString& get_g_EditorMarker();
const NiFixedString& get_g_EditorMarker0();
const NiFixedString& get_g_EditorMarker1();
const NiFixedString& get_g_EditorMarker2();
int BSstricmp(const char*, const char*);
extern "C" int _strnicmp(const char*, const char*, unsigned int);

extern NiRTTI DAT_012024e0;
int BSSM_ShaderPropertyIsLighting(NiProperty*);
class TESObjectLIGH;

extern "C" float logf(float);
struct CollisionObjectCountContext
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    int iCount;
    void* pUserData;
    void* pAuxiliaryData;
    unsigned int uiFilterFlags;
};
void GetCollisionObjectByIndex(NiCollisionObject*, CollisionObjectCountContext*);
void bhkWorld_DoObjectRec(NiAVObject*, CollisionObjectCountContext*,
                  void (*)(NiCollisionObject*, CollisionObjectCountContext*));



class INISettingCollection;
using ::SettingT;
extern SettingT<INISettingCollection> DAT_011d5a30;
extern bool DAT_012677a3;

// @fnv 0x004b7920
void BipedNodeNames::InitializeMultiBounds()
{
    DAT_011c61a4 = new NiFixedString("Bip01");
    DAT_011c61a8 = new NiFixedString("Bip");
    DAT_011c61ac = new NiFixedString("Bip01 Head");
    DAT_011c61b0 = new NiFixedString("Bip01 Neck");
    DAT_011c61b4 = new NiFixedString("Bip01 Spine");
    DAT_011c61b8 = new NiFixedString("Bip01 Spine1");
    DAT_011c61bc = new NiFixedString("magicNode");
    DAT_011c61c0 = new NiFixedString("SpecialIdle_Cast");
    DAT_011c61c4 = new NiFixedString("SpecialIdle_AreaEffect");
    DAT_011c61c8 = new NiFixedString("AttachSound");
    DAT_011c61cc = new NiFixedString("Sound Marker");
    DAT_011c61d0 = new NiFixedString("Skinned Decal Node");
    DAT_011c61d4 = new NiFixedString("Decal Node");
    DAT_011c61d8 = new NiFixedString("ModelSwapNode");
    DAT_011c61dc = new NiFixedString("Open");
    DAT_011c61e0 = new NiFixedString("Close");
    DAT_011c61e4 = new NiFixedString("DVPG");
    DAT_011c61e8 = new NiFixedString("Prn");
    DAT_011c61ec = new NiFixedString("Weapon");
    DAT_011c61f0 = new NiFixedString("EditorMarker");
    DAT_011c61f4 = new NiFixedString("EditorMarker:0");
    DAT_011c61f8 = new NiFixedString("EditorMarker:1");
    DAT_011c61fc = new NiFixedString("EditorMarker:2");
    DAT_011c6200 = new NiFixedString("ArrowQuiver");
    DAT_011c6204 = new NiFixedString("MarkerSource");
    DAT_011c6208 = new NiFixedString("MarkerTarget");
    DAT_011c620c = new NiFixedString("AttachLight");
    DAT_011c6210 = new NiFixedString("skin");
    DAT_011c6214 = new NiFixedString("FaceGenEars");
    DAT_011c6218 = new NiFixedString("Unequip");
    DAT_011c621c = new NiFixedString("LaserSight");
    DAT_011c6220 = new NiFixedString("AimSight");
    DAT_011c6224 = new NiFixedString("Grass");
    DAT_011c6228 = new NiFixedString("Decal");
    DAT_011c622c = new NiFixedString("Permanent Decal");
    DAT_011c6230 = new NiFixedString("grabLeft");
    DAT_011c6234 = new NiFixedString("grabRight");
    DAT_011c6238 = new NiFixedString("Arrow:0");
    DAT_011c623c = new NiFixedString("ArrowBone");
    DAT_011c6240 = new NiFixedString("BSFaceGenNiNodeBiped");
    DAT_011c6244 = new NiFixedString("BSFaceGenNiNodeSkinned");
    DAT_011c6248 = new NiFixedString("HeadAnims:0");
    DAT_011c624c = new NiFixedString("EntryPoint");
    DAT_011c6250 = new NiFixedString("Bip01 L UpperArm");
    DAT_011c6254 = new NiFixedString("Bip01 L Forearm");
    DAT_011c6258 = new NiFixedString("Bip01 R UpperArm");
    DAT_011c625c = new NiFixedString("Bip01 Yaw");
    DAT_011c6260 = new NiFixedString("Bip01 Pitch");
    DAT_011c6264 = new NiFixedString("Bip01 Looking");
    DAT_011c6268 = new NiFixedString("Talking");
    DAT_011c626c = new NiFixedString("Camera1st");
    DAT_011c6270 = new NiFixedString("Camera3rd");
    DAT_011c6274 = new NiFixedString("HeadMeshForExport_FaceGenAndMorphs:0");
    DAT_011c6278 = new NiFixedString("PinnedLimb");
}

// @fnv 0x004b7240
bool ConvertLocalizedString(const char* input, char* output, unsigned int capacity)
{
    if (!input || !output || !capacity)
        return false;
    const char* current;
    bool changed = false;
    output[0] = 0;
    unsigned int written = 0;
    int targetPlatform = GetIsControllerConnected_();
    LANGUAGE language = GetConfiguredLanguage();
    current = input;
    for (int i = 0; i < 4; ++i)
    {
        char separator = 0;
        const char* found = LocateString(current, DAT_01189038[i]);
        while (found)
        {
            unsigned int tagLength = BSStringLength(DAT_01189038[i]);
            if (found[tagLength] == '\\' || found[tagLength] == '/')
            {
                separator = found[tagLength];
                break;
            }
            else
                found = LocateString(found + tagLength, DAT_01189038[i]);
        }
        if (found)
        {
            unsigned int prefix = found - current;
            if (prefix)
            {
                memcpy_s(output + written, capacity - written, current, prefix);
                written += prefix;
                output[written] = 0;
            }
            strcat_s(output, capacity, DAT_01189038[targetPlatform]);
            written += strlen(DAT_01189038[targetPlatform]);
            output[written] = separator;
            ++written;
            output[written] = 0;
            found += strlen(DAT_01189038[i]);
            ++found;
            current = found;
            changed = true;
            break;
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        char separator = 0;
        const char* found = LocateString(current, DAT_01188f84[i]);
        while (found)
        {
            unsigned int tagLength = BSStringLength(DAT_01188f84[i]);
            if (found[tagLength] == '\\' || found[tagLength] == '/')
            {
                separator = found[tagLength];
                break;
            }
            else
                found = LocateString(found + tagLength, DAT_01188f84[i]);
        }
        if (found)
        {
            unsigned int prefix = found - current;
            if (prefix)
            {
                memcpy_s(output + written, capacity - written, current, prefix);
                written += prefix;
                output[written] = 0;
            }
            strcat_s(output, capacity, DAT_01188f84[language]);
            written += strlen(DAT_01188f84[language]);
            output[written] = separator;
            ++written;
            output[written] = 0;
            found += strlen(DAT_01188f84[i]);
            ++found;
            current = found;
            changed = true;
            break;
        }
    }
    strcat_s(output, capacity, current);
    return changed;
}

// @fnv 0x004b7660
bool UpdateObjectVisibility(NiAVObject* object)
{
    bool changed = false;
    if (object)
    {
        NiProperty* property = object->GetProperty(3);
        NiProperty* textures = (property == 0 ? 0
                                              : (reinterpret_cast<NiTimeController*>(property)->FUN_00441110() >= 8 &&
                                                 reinterpret_cast<NiTimeController*>(property)->FUN_00441110() <= 12))
                                   ? property
                                   : 0;
        if (textures)
        {
            // These texture operations use the original virtual slots; the shared
            // BSShaderPPLightingProperty declarations are nonvirtual.
            unsigned int count = reinterpret_cast<unsigned short (__thiscall*)(NiProperty*)>(
                (*reinterpret_cast<void***>(textures))[0xe8 / 4])(textures);
            for (unsigned int i = 0; i < count; ++i)
            {
                for (int type = 0; type < 6; ++type)
                {
                    NiTexture* texture = reinterpret_cast<NiTexture* (__thiscall*)(NiProperty*, int, unsigned int)>(
                        (*reinterpret_cast<void***>(textures))[0xf4 / 4])(textures, type, i);
                    if (texture && NiObject_IsKindOf(&DAT_011f444c, reinterpret_cast<NiAVObject*>(texture)))
                    {
                        bool swapped;
                        NiTexture* source = texture;
                        NiFixedString path(source->GetPath());
                        {
                            char replacement[260];
                            replacement[0] = 0;
                            swapped = ConvertLocalizedString(
                                reinterpret_cast<const char*>(reinterpret_cast<BSFadeNode*>(&path)->FUN_0043b1b0()),
                                replacement, 260);
                            if (swapped && replacement[0])
                            {
                                NiPointer<NiTexture> newTexture(0);
                                g_TES->CreateTextureImage(static_cast<const char*>(replacement),
                                                          reinterpret_cast<NiPointer<NiSourceTexture>&>(newTexture),
                                                          false, false);
                                if (newTexture)
                                {
                                    reinterpret_cast<void (__thiscall*)(NiProperty*, int, unsigned int, NiTexture*)>(
                                        (*reinterpret_cast<void***>(textures))[0xf0 / 4])(
                                        textures, type, i, static_cast<NiTexture*>(newTexture));
                                    changed = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        NiNode* node = object->IsSceneNode();
        if (node)
        {
            unsigned int count = node->GetNumChildren();
            for (unsigned int i = 0; i < count; ++i)
                if (UpdateObjectVisibility(node->GetAt(i)))
                    changed = true;
        }
    }
    return changed;
}

// @fnv 0x004b5d10
bool RemoveInvalidChildNodes(NiNode* apNode)
{
    bool removed = false;
    if (!apNode)
        return removed;
    if (!DAT_011c6328)
    {
        NiExtraData* pExtraData = apNode->GetExtraData(BSXFlags_Tag());
        if (pExtraData)
        {
            NiExtraData* flags = pExtraData;
            if (flags->BSXFlags_IsEditorMarker())
            {
                DAT_011c6328 = apNode;
                NiTimeController* controller = apNode->GetController(&DAT_011f36ac);
                {
                    NiControllerManager* controllerManager = reinterpret_cast<NiControllerManager*>(controller);
                    if (controllerManager)
                        DAT_011c6324 = controllerManager->GetStringAtOffset();
                }
            }
        }
    }
    if (!DAT_011c6328)
        return removed;
    if (reinterpret_cast<const char*>(
            reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(apNode)->GetLinkToList())
                ->FUN_0043b1b0()) &&
        !BSstricmp(reinterpret_cast<const char*>(
                          reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(apNode)->GetLinkToList())
                              ->FUN_0043b1b0()),
                      "EditorMarker"))
    {
        if (DAT_011c6324)
        {
            reinterpret_cast<void* (__thiscall*)(NiAVObjectPalette*, const NiFixedString&, int)>(
                (*reinterpret_cast<void***>(DAT_011c6324))[0x90 / 4])(DAT_011c6324, get_g_EditorMarker(), 0);
            reinterpret_cast<void* (__thiscall*)(NiAVObjectPalette*, const NiFixedString&, int)>(
                (*reinterpret_cast<void***>(DAT_011c6324))[0x90 / 4])(DAT_011c6324, get_g_EditorMarker0(), 0);
            reinterpret_cast<void* (__thiscall*)(NiAVObjectPalette*, const NiFixedString&, int)>(
                (*reinterpret_cast<void***>(DAT_011c6324))[0x90 / 4])(DAT_011c6324, get_g_EditorMarker1(), 0);
            reinterpret_cast<void* (__thiscall*)(NiAVObjectPalette*, const NiFixedString&, int)>(
                (*reinterpret_cast<void***>(DAT_011c6324))[0x90 / 4])(DAT_011c6324, get_g_EditorMarker2(), 0);
        }
        if (apNode->GetParent())
            apNode->GetParent()->RemoveObject(apNode);
        if (DAT_011c6328 == apNode)
        {
            DAT_011c6328 = 0;
            DAT_011c6324 = 0;
        }
        return true;
    }
    for (unsigned int i = 0; i < apNode->GetNumChildren(); ++i)
    {
        NiAVObject* child = apNode->GetAt(i);
        if (child)
        {
            NiNode* node = child->IsSceneNode();
            if (node)
            {
                removed = RemoveInvalidChildNodes(node);
                if (removed)
                {
                    if (DAT_011c6328 == apNode)
                    {
                        DAT_011c6328 = 0;
                        DAT_011c6324 = 0;
                    }
                    return removed;
                }
            }
        }
    }
    if (DAT_011c6328 == apNode)
    {
        DAT_011c6328 = 0;
        DAT_011c6324 = 0;
    }
    return removed;
}

// @fnv 0x004b5b20
bool HandleUnparentedObjectNode(NiNode* object)
{
    if (!object)
        return false;
    for (unsigned int i = 0; i < object->GetNumChildren(); ++i)
    {
        NiAVObject* child = object->GetAt(i);
        if (child)
        {
            const char* name = reinterpret_cast<const char*>(
                reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(child)->GetLinkToList())
                    ->FUN_0043b1b0());
            if (name)
            {
                if (!BSstricmp(name, "Scb"))
                {
                    object->RemoveNthObject(i);
                    return true;
                }
                else if (!_strnicmp(name, "FadeNode ", 9))
                    return HandleUnparentedObjectNode(child->IsSceneNode());
            }
        }
    }
    return false;
}

// @fnv 0x004b6dc0
void SetObjectFormID(NiAVObject* object, unsigned int referenceID)
{
    if (!object)
        return;
    if (object->IsGeometry())
    {
        NiProperty* property = object->GetProperty(3);
        NiProperty* lighting = BSSM_ShaderPropertyIsLighting(property) ? property : 0;
        if (lighting)
            reinterpret_cast<EffectSetting*>(lighting)->SetLight(reinterpret_cast<TESObjectLIGH*>(referenceID));
    }
    else
    {
        NiNode* node = object->IsSceneNode();
        if (node)
            for (unsigned int i = 0; i < node->GetNumChildren(); ++i)
                SetObjectFormID(node->GetAt(i), referenceID);
    }
}

// @fnv 0x004b5c80
bool IsObjectNetValid(NiObjectNET* object)
{
    if (!object)
        return false;
    if (NiObject_IsKindOf(&DAT_012024e0, reinterpret_cast<NiAVObject*>(object)))
        return true;
    NiNode* node = object->IsSceneNode();
    if (node)
        for (unsigned int i = 0; i < node->GetNumChildren(); ++i)
        {
            NiAVObject* child = node->GetAt(i);
            if (IsObjectNetValid(child))
                return true;
        }
    return false;
}

// Computes an angle from vector.x and vector.y using logf of their ratio, adding pi when y is negative and using pi/2 or 3pi/2 when y is zero.
// @fnv 0x004b1550
float GetAngleFromVector(const NiPoint3& vector)
{
    float angle = 0.0f;
    if (vector.y != 0.0)
    {
        float ratio = vector.x / vector.y;
        angle = logf(ratio);
        if (vector.y < 0.0)
            angle += 3.1415927410125732;
    }
    else
    {
        if (vector.x > 0.0)
            angle = 1.5707963705062866f;
        else
            angle = 4.71238899230957f;
    }
    return angle;
}

// Traverses the NiAVObject tree with filter flags set from the skip arguments and returns the accumulated collision object count.
// @fnv 0x004b66d0
int CountCollisionObjects(NiAVObject* object, bool skipPhantoms, bool skipBlendObjects, bool skipUnknown)
{
    CollisionObjectCountContext context;
    context.uiTraversalFlags = 0x12;
    context.bRecurse = true;
    context.iCount = 0;
    context.uiFilterFlags = 0;
    if (skipPhantoms)
        context.uiFilterFlags |= 1;
    if (skipBlendObjects)
        context.uiFilterFlags |= 2;
    if (skipUnknown)
        context.uiFilterFlags |= 4;
    bhkWorld_DoObjectRec(object, &context, GetCollisionObjectByIndex);
    return context.iCount;
}

// Returns true when m_spWorldBound is set and its FUN_0084d030 result is non-zero.
// @fnv 0x004b2960
int NiAVObject::IsVisualObject()
{
    return m_kWorldBound && reinterpret_cast<NiBound*>(m_kWorldBound)->FUN_0084d030() != 0.0;
}

// If a look-at target exists, copies the stored look-at point into point and returns true; otherwise returns false.
// @fnv 0x009de270
bool ActorMover::GetLookAtTargetPosition(NiPoint3& point)
{
    if (HasLookAtTarget())
    {
        point = m_kLookAtTargetPosition;
        return true;
    }
    return false;
}

// @fnv 0x006ca0c0
bool PathingGraphNode::IsTransitionNode()
{
    return (iFlags & 4) == 4;
}

// @fnv 0x004b7220
LANGUAGE GetConfiguredLanguage()
{
    LANGUAGE language = static_cast<LANGUAGE>(BSSysInfoSystemUtility::GetRandomGenerator());
    return language;
}

// @fnv 0x00430830
RecipeCraftingInfo* TESRecipe::GetData()
{
    return reinterpret_cast<RecipeCraftingInfo*>(&kData);
}

// @fnv 0x00605d20
bool IsSettingEnabled()
{
    return *reinterpret_cast<const bool*>(DAT_011d5a30.Bool());
}

// @fnv 0x00888960
bool bhkWorld::QPickCountOverride()
{
    return DAT_012677a3;
}

double __cdecl FUN_00ec9010(double);

// @fnv 0x004b1460
// src: XBOX_PDB 0x004b1460
float atanf(float _X)
{
    return static_cast<float>(FUN_00ec9010(_X));
}

double __cdecl FUN_00ec9130(double, double);

// @fnv 0x004b1520
// src: XBOX_PDB 0x004b1520
float __cdecl fmodf(float _X, float _Y)
{
    return (float)FUN_00ec9130((double)_X, (double)_Y);
}

extern const NiPoint3 NiPoint3_ZERO;
bool __cdecl PickObjectsInRadius(NiPick*, int, int, float, int);

// @fnv 0x004b2780
// src: XBOX_PDB 0x004b2780
bool __cdecl PickDistance(NiPick* pPicker, int p2, int p3, float p4, int p5, bool p6)
{
    bool bResult = false;
    if (pPicker != 0 && p5 != 0 && p4 != 0.0)
    {
        if (p6)
        {
            pPicker->SetTarget_00705fc0(static_cast<void*>(0));
            pPicker->PerformPick(NiPoint3_ZERO, NiPoint3_ZERO, false);
        }
        bResult = PickObjectsInRadius(pPicker, p2, p3, p4, p5);
    }
    return bResult;
}

// Maps value from the range [y1,y2] onto [x1,x2] by linear interpolation and returns the result.
// @fnv 0x004b3ab0
float LinearInterpolate(float x1, float x2, float y1, float y2, float value)
{
    return x1 + (value - y1) / (y2 - y1) * (x2 - x1);
}

// M * v: each output coordinate is one matrix row dotted with v (x, y, z terms in that order)
#define M3_ROW_DOT_V(i) m_pEntry[i][0] * kV.x + m_pEntry[i][1] * kV.y + m_pEntry[i][2] * kV.z
// @fnv 0x004b4500
NiPoint3 NiMatrix3::operator*(const NiPoint3& kV) const
{
    return NiPoint3(M3_ROW_DOT_V(0), M3_ROW_DOT_V(1), M3_ROW_DOT_V(2));
}
#undef M3_ROW_DOT_V

// @fnv 0x004b4cf0
void* NiFrustumPlanes::GetPlane(unsigned int ePlane)
{
    return reinterpret_cast<char*>(this) + (ePlane * 16);
}

struct hkQuaternion;
struct hkVector4;
struct FourDimensionalVector
{
    hkQuaternion* ToHK(hkQuaternion*);
    hkVector4* ToHK(hkVector4*);
    void set(float, float, float, float);
    void setZero4();
    void setAll3(float);
    void mul4(float);
    FourDimensionalVector* NI2HKNS(void*);
    FourDimensionalVector* FromHK(void*);
    float fX;
    float fY;
    float fZ;
    float fW;
};
struct FUN_004b4e50_shell : public FourDimensionalVector
{
    FourDimensionalVector* SetFromScaledVector3(void*);
};

extern float runtimeInitializationFloat2127;

// @fnv 0x004b4e50
FourDimensionalVector* FUN_004b4e50_shell::SetFromScaledVector3(void* arSrc)
{
    fX = runtimeInitializationFloat2127 * ((const float*)arSrc)[0];
    fY = runtimeInitializationFloat2127 * ((const float*)arSrc)[1];
    fZ = runtimeInitializationFloat2127 * ((const float*)arSrc)[2];
    fW = 0.0f;
    return this;
}

int __fastcall hkpMotion_getTransform(void* pThis);

// @fnv 0x004b4f00
// src: XBOX_PDB 0x004b4f00
int __fastcall hkpRigidBody_getTransform(TESDataHandler* apDataHandler)
{
    return hkpMotion_getTransform(apDataHandler->GetBGSRagdollList());
}

class hkQuaternion;
class hkVector4;
namespace fnv_004b4ff0 {
struct FourDimensionalVector
{
    hkQuaternion* ToHK(hkQuaternion*);
    hkVector4* ToHK(hkVector4*);
    void set(float, float, float, float);
    void setZero4();
    void setAll3(float);
    void mul4(float);
    FourDimensionalVector* NI2HKNS(void*);
    FourDimensionalVector* FromHK(void*);
    float fX;
    float fY;
    float fZ;
    float fW;
};
struct FUN_004b4ff0_shell : public FourDimensionalVector
{
    void bhkVector4_set(float, float, float, float);
};

// @fnv 0x004b4ff0
// src: XBOX_PDB 0x004b4ff0
void FUN_004b4ff0_shell::bhkVector4_set(float afX, float afY, float afZ, float afW)
{
    fX = afX;
    fY = afY;
    fZ = afZ;
    fW = afW;
}
}  // namespace fnv_004b4ff0

struct PhysicsSimulationContext;
struct hkMatrix3;
struct hkMotionState;
struct hkMultiThreadCheck;
struct hkReferencedObject;
struct hkStatisticsCollector;
struct hkTransform;
struct hkVector4;
struct hkaiObjectData;
struct hkdBreakableBody;
struct hkpAction;
struct hkpBreakableBody;
struct hkpCollidable;
struct hkpConstraintInstance;
struct hkpContactListener;
struct hkpDynamicsContactMgr;
struct hkpEntity;
struct hkpEntityActivationListener;
struct hkpEntityListener;
struct hkpLinkedCollidable;
struct hkpMaterial;
struct hkpMaxSizeMotion;
struct hkpRigidBody;
struct WorldPhysicsSettings;
struct hkpSimulationIsland;
struct hkpWorld;
struct blob1
{
    char b[1];
};
struct blob8
{
    char b[8];
};

hkpRigidBody* __fastcall Bipedanim_GetReferenceFlagsOrZero(void*);
float __fastcall hkpRigidBody_getMass(hkpRigidBody*);

// @fnv 0x004b5400
// src: XBOX_PDB 0x004b5400
float __fastcall bhkRigidBody_GetMass(void* pThis)
{
    hkpRigidBody* pb = Bipedanim_GetReferenceFlagsOrZero(pThis);
    return pb ? hkpRigidBody_getMass(pb) : 0.0f;
}

bool __cdecl LengthCheck_004b5470(const NiPoint3& aPt, float afCompLength);

// @fnv 0x004b5440
// src: XBOX_PDB 0x004b5440
bool __cdecl LengthCheck(const NiPoint3& aPt1, const NiPoint3& aPt2, float afCompLength)
{
    return LengthCheck_004b5470(aPt1 - aPt2, afCompLength);
}

float __cdecl asinf_004b5530(float);

// @fnv 0x004b5510
// src: XBOX_PDB 0x004b5510
float __cdecl asin_004b5510(float _X)
{
    return asinf_004b5530(_X);
}

double __cdecl FUN_00ec9610(double);

// @fnv 0x004b5530
// src: XBOX_PDB 0x004b5530
float asinf_004b5530(float value)
{
    return static_cast<float>(FUN_00ec9610(value));
}

float __cdecl atan2f(float, float);

// @fnv 0x004b5570
// src: COMMUNITY 0x004b5570
float __cdecl atan2_004b5570(float _Y, float _X)
{
    return atan2f(_Y, _X);
}

int __fastcall hkpCollidable_getType(const void* collidable);
void* __cdecl hkGetWorldObject_004b59c0(const void* collidable);

// Returns the result of FUN_004b59c0 when FUN_004b5980 reports 2 for collidable, otherwise returns 0.
// @fnv 0x004b5950
// src: XBOX_PDB 0x004b5950
void* __cdecl hkpGetPhantom(const void* collidable)
{
    if (hkpCollidable_getType(collidable) == 2)
    {
        return hkGetWorldObject_004b59c0(collidable);
    }
    return 0;
}

// @fnv 0x004b59d0
// src: XBOX_PDB 0x004b59d0
const void* __fastcall hkpCollidable_getOwner(const char* apBase)
{
    return apBase + apBase[0x10];
}

int __fastcall hkpCollidable_getType(const void* collidable);
void* __cdecl hkGetWorldObject_004b59c0(const void* collidable);

// Returns the result of FUN_004b59c0 when FUN_004b5980 reports 1 for collidable, otherwise returns 0.
// @fnv 0x004b59f0
// src: XBOX_PDB 0x004b59f0
void* __cdecl hkpGetRigidBody(const void* collidable)
{
    if (hkpCollidable_getType(collidable) == 1)
    {
        return hkGetWorldObject_004b59c0(collidable);
    }
    return 0;
}

extern char const* const g_012683d0_arg1;
void* __cdecl DynamicCastByRTTI(const void*, NiAVObject*);

// @fnv 0x004b5ad0
// src: COMMUNITY 0x004b5ad0
void* __cdecl bhkUtilFunctions_IsbhkPCollisionObject(NiAVObject* apPhantom)
{
    NiAVObject* pc = NiShader::DynamicCast(apPhantom);
    return DynamicCastByRTTI(&g_012683d0_arg1, pc);
}

// @fnv 0x004b5fa0
// src: COMMUNITY 0x004b5fa0
bool __fastcall BSXFlags_IsEditorMarker(const BSXFlags* pThis)
{
    return pThis->GetFlags(0x20) != 0;
}

// Computes the plane distance to this sphere and returns 2 if fully behind, 1 if fully in front, or 0 if straddling.
// @fnv 0x004b6100
int NiBound::WhichSide(void* plane)
{
    float fDistance = static_cast<NiPlane*>(plane)->Distance(*reinterpret_cast<const NiPoint3*>(this));
    if (fDistance <= -m_fRadius)
        return 2;
    else if (fDistance >= m_fRadius)
        return 1;
    else
        return 0;
}

// @fnv 0x004b6160
float NiPlane::Distance(const NiPoint3& aPoint) const
{
    return reinterpret_cast<const NiPoint3*>(this)->Dot(aPoint) - c;
}

// Returns the dot product of this NiPoint3 with the NiPoint3 pointed to by pt.
// @fnv 0x004b6190
float NiPoint3::Dot(void* apPoint)
{
    return x * static_cast<const NiPoint3*>(apPoint)->x + y * static_cast<const NiPoint3*>(apPoint)->y +
           z * static_cast<const NiPoint3*>(apPoint)->z;
}

int __cdecl BSstrcmp(const char*, const char*);
extern NiRTTI DAT_011f9140;
extern NiRTTI g_0126817c;

// Skips incrementing the counter at data+0xc when the object matches the RTTI checks or is an Arrow; otherwise increments it.
// @fnv 0x004b6740
// src: COMMUNITY 0x004b6740
void __cdecl GetCollisionObjectByIndex(NiAVObject* apObject, char* data)
{
    if ((*(unsigned int*)(data + 0x18) & 1) && NiObject_IsKindOf(&g_0126817c, apObject))
        return;
    if ((*(unsigned int*)(data + 0x18) & 2) &&
        NiObject_IsKindOf(&DAT_011f9140, (NiAVObject*)((TESObjectREFR*)apObject)->GetFlags()))
        return;
    if ((*(unsigned int*)(data + 0x18) & 2) && ((TESObjectREFR*)apObject)->GetFlags() &&
        ((BSFadeNode*)((TESTopicInfoData*)((TESObjectREFR*)apObject)->GetFlags())->GetLinkToList())
            ->FUN_0043b1b0() &&
        !BSstrcmp(
            (const char*)((BSFadeNode*)((TESTopicInfoData*)((TESObjectREFR*)apObject)->GetFlags())->GetLinkToList())
                ->FUN_0043b1b0(),
            "Arrow"))
        return;
    *(int*)(data + 0xc) += 1;
}

extern "C" const char* __fastcall GetBSStringData(const BSStringT<char>*);

// @fnv 0x004b6e70
const char* __fastcall GetStringAtOffset13C(const char* pThis)
{
    return GetBSStringData(reinterpret_cast<const BSStringT<char>*>(pThis + 0x13c));
}

bool __cdecl InterfaceManager_Has360Controller(void);

// Returns 1 if FUN_004b71d0() returns true, otherwise returns 0.
// @fnv 0x004b71a0
// src: COMMUNITY 0x004b71a0
int GetIsControllerConnected_()
{
    int result = 0;
    if (InterfaceManager_Has360Controller())
        result = 1;
    return result;
}

extern bool DAT_011d8a84;
extern MobileObject g_011d8c4c;
void* __cdecl InterfaceManager_GetSingleton(void);

// Returns true when DAT_011d8a84 is set and, after calling FUN_004b7210, g_011d8c4c reports its char controller flag.
// @fnv 0x004b71d0
// src: XBOX_PDB 0x004b71d0
bool __cdecl InterfaceManager_Has360Controller()
{
    return DAT_011d8a84 && (InterfaceManager_GetSingleton(), g_011d8c4c.GetCharControllerFlag());
}

// @fnv 0x0063f790
void NiBound::SetRadius(float afRadius)
{
    m_fRadius = afRadius;
}

struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};

// @fnv 0x004b1e80
// src: COMMUNITY 0x004b1e80
bool TES_LineVsRect(const tagRECT* aTestRect, const NiPoint3* aStartPt, const NiPoint3* aEndPt,
                  NiPoint3* aOutputIntersectPt)
{
    bool bIntersect = false;

    if (aTestRect->left >= aTestRect->right)
        return false;
    if (aTestRect->bottom >= aTestRect->top)
        return false;
    if (aStartPt->x < aTestRect->left && aEndPt->x < aTestRect->left)
        return false;
    if (aStartPt->y < aTestRect->bottom && aEndPt->y < aTestRect->bottom)
        return false;
    if (aStartPt->x > aTestRect->right && aEndPt->x > aTestRect->right)
        return false;
    if (aStartPt->y > aTestRect->top && aEndPt->y > aTestRect->top)
        return false;
    if (aStartPt->x > aTestRect->left && aStartPt->x < aTestRect->right && aStartPt->y > aTestRect->bottom &&
        aStartPt->y < aTestRect->top && aEndPt->x > aTestRect->left && aEndPt->x < aTestRect->right &&
        aEndPt->y > aTestRect->bottom && aEndPt->y < aTestRect->top)
        return false;

    if (aEndPt->x == aStartPt->x || aEndPt->y == aStartPt->y)
    {
        if (aEndPt->x == aStartPt->x && aEndPt->y == aStartPt->y)
        {
            if (aStartPt->x <= aTestRect->right && aStartPt->x >= aTestRect->left && aStartPt->y <= aTestRect->top &&
                aStartPt->y >= aTestRect->bottom)
            {
                bIntersect = true;
                *aOutputIntersectPt = *aStartPt;
            }
        }
        else if (aEndPt->x == aStartPt->x)
        {
            if (aStartPt->x <= aTestRect->right && aStartPt->x >= aTestRect->left)
            {
                bIntersect = true;
                if (aStartPt->y > aEndPt->y)
                    *aOutputIntersectPt = NiPoint3(aStartPt->x, aTestRect->top, 0.0f);
                else
                    *aOutputIntersectPt = NiPoint3(aStartPt->x, aTestRect->bottom, 0.0f);
            }
        }
        else if (aEndPt->y == aStartPt->y)
        {
            if (aStartPt->y <= aTestRect->top && aStartPt->y >= aTestRect->bottom)
            {
                bIntersect = true;
                if (aStartPt->x > aEndPt->x)
                    *aOutputIntersectPt = NiPoint3(aTestRect->right, aStartPt->y, 0.0f);
                else
                    *aOutputIntersectPt = NiPoint3(aTestRect->left, aStartPt->y, 0.0f);
            }
        }
    }
    else
    {
        int intersectsFound = 0;
        NiPoint3 intersect1(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F);
        NiPoint3 intersect2(3.402823466e+38F, 3.402823466e+38F, 3.402823466e+38F);
        float slope = (aEndPt->y - aStartPt->y) / (aEndPt->x - aStartPt->x);
        float intercept = aEndPt->y - aEndPt->x * slope;

        if (intersectsFound < 2)
        {
            float YatBorder = aTestRect->left * slope + intercept;
            if (YatBorder <= aTestRect->top && YatBorder >= aTestRect->bottom)
            {
                if (intersectsFound == 0)
                    intersect1 = NiPoint3(aTestRect->left, YatBorder, 0.0f);
                else
                    intersect2 = NiPoint3(aTestRect->left, YatBorder, 0.0f);
                intersectsFound++;
            }
        }
        if (intersectsFound < 2)
        {
            float XatBorder = (aTestRect->top - intercept) / slope;
            if (XatBorder <= aTestRect->right && XatBorder >= aTestRect->left)
            {
                if (intersectsFound == 0)
                    intersect1 = NiPoint3(XatBorder, aTestRect->top, 0.0f);
                else
                    intersect2 = NiPoint3(XatBorder, aTestRect->top, 0.0f);
                intersectsFound++;
            }
        }
        if (intersectsFound < 2)
        {
            float YatBorder = aTestRect->right * slope + intercept;
            if (YatBorder <= aTestRect->top && YatBorder >= aTestRect->bottom)
            {
                if (intersectsFound == 0)
                    intersect1 = NiPoint3(aTestRect->right, YatBorder, 0.0f);
                else
                    intersect2 = NiPoint3(aTestRect->right, YatBorder, 0.0f);
                intersectsFound++;
            }
        }
        if (intersectsFound < 2)
        {
            float XatBorder = (aTestRect->bottom - intercept) / slope;
            if (XatBorder <= aTestRect->right && XatBorder >= aTestRect->left)
            {
                if (intersectsFound == 0)
                    intersect1 = NiPoint3(XatBorder, aTestRect->bottom, 0.0f);
                else
                    intersect2 = NiPoint3(XatBorder, aTestRect->bottom, 0.0f);
                intersectsFound++;
            }
        }

        if (intersectsFound)
        {
            bIntersect = true;
            if (intersectsFound == 2)
            {
                if (aStartPt->x > aTestRect->left && aStartPt->x < aTestRect->right &&
                    aStartPt->y > aTestRect->bottom && aStartPt->y < aTestRect->top)
                {
                    NiPoint3 linevect = *aEndPt - *aStartPt;
                    NiPoint3 intersect1vect = intersect1 - *aStartPt;
                    linevect.z = 0.0f;
                    intersect1vect.z = 0.0f;
                    linevect.ComputeMagnitude();
                    intersect1vect.ComputeMagnitude();
                    if ((linevect + intersect1vect).Length() > 1.0)
                        *aOutputIntersectPt = intersect1;
                    else
                        *aOutputIntersectPt = intersect2;
                }
                else if ((intersect1 - *aStartPt).Length() < (intersect2 - *aStartPt).Length())
                {
                    *aOutputIntersectPt = intersect1;
                }
                else
                {
                    *aOutputIntersectPt = intersect2;
                }
            }
            else
            {
                *aOutputIntersectPt = intersect1;
            }
        }
    }
    return bIntersect;
}

// Calls Initialize, installs the vtable pointer at offset 0 and zeroes the int at offset 0xc.
// @fnv 0x004b5120
bhkSerializable::bhkSerializable()
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0xc) = 0;
}

struct FUN_004b51a0_shell
{
    void* FUN_004b51a0(unsigned int flags);
};

struct FUN_00c87970_shell
{
    void __thiscall FUN_00c87970();
};

void __cdecl __Dummy_00b6fef0(void* obj, unsigned int size);

// @fnv 0x004b51a0
void* FUN_004b51a0_shell::FUN_004b51a0(unsigned int flags)
{
    ((FUN_00c87970_shell*)this)->FUN_00c87970();
    if (flags & 1)
        __Dummy_00b6fef0(this, 0x10);
    return this;
}

extern const char* const g_0126812c_arg1;

struct FUN_004b51d0_shell
{
    const char* const* __thiscall GetRTTI();
};

// @fnv 0x004b51d0
const char* const* __thiscall FUN_004b51d0_shell::GetRTTI()
{
    return &g_0126812c_arg1;
}

extern const NiRTTI g_0126812c;

struct FUN_004b5210_shell
{
    const NiRTTI* GetRTTI() const;
};

// @fnv 0x004b5210
const NiRTTI* FUN_004b5210_shell::GetRTTI() const
{
    return &g_0126812c;
}

// @fnv 0x004b59a0
int __fastcall GetCharAtOffset4(int param_1)
{
    return (int)*(char*)(param_1 + 4);
}

// @fnv 0x004b5f60
// src: COMMUNITY 0x004b5f60
const NiFixedString& get_g_EditorMarker()
{
    return *DAT_011c61f0;
}

// @fnv 0x004b5f70
// src: COMMUNITY 0x004b5f70
const NiFixedString& get_g_EditorMarker0()
{
    return *DAT_011c61f4;
}

// @fnv 0x004b5f80
// src: COMMUNITY 0x004b5f80
const NiFixedString& get_g_EditorMarker1()
{
    return *DAT_011c61f8;
}

// @fnv 0x004b5f90
// src: COMMUNITY 0x004b5f90
const NiFixedString& get_g_EditorMarker2()
{
    return *DAT_011c61fc;
}

struct bhkWorldObject;

int __fastcall GetReferenceFlags(void*);

// Gets the collision object's world object and, if it exists and GetReferenceFlags returns nonzero, increments the fourth int of arg.
// @fnv 0x004b6b20
// src: COMMUNITY 0x004b6b20
void __cdecl GetHavokWorldObjectCount(bhkCollisionObject* apCollisionObject, void* apData)
{
    bhkWorldObject* result = apCollisionObject->bhkNiCollisionObject_GetWorldObject();
    if (result && GetReferenceFlags(result))
        ((int*)apData)[3]++;
}

namespace fnv_004b6bc0 {

int __fastcall GetReferenceFlags(bhkWorldObject*);

// @fnv 0x004b6bc0
// src: COMMUNITY 0x004b6bc0
void GetHavokWorldObjectIndex(bhkCollisionObject* apCollisionObject, void* dest)
{
    bhkWorldObject* w = apCollisionObject->bhkNiCollisionObject_GetWorldObject();
    if (w)
    {
        int r = GetReferenceFlags(w);
        if (r)
        {
            if (r == ((int*)dest)[4])
            {
                ((int*)dest)[5] = ((int*)dest)[3];
            }
            ((int*)dest)[3] = ((int*)dest)[3] + 1;
        }
    }
}
}  // namespace fnv_004b6bc0

namespace fnv_004b6c70 {

int __fastcall GetReferenceFlags(int* obj);

// @fnv 0x004b6c70
// src: COMMUNITY 0x004b6c70
void __cdecl GetHavokWorldObjectByIndex(bhkCollisionObject* apCollisionObject, int* arg2)
{
    int* obj = reinterpret_cast<int*>(apCollisionObject->bhkNiCollisionObject_GetWorldObject());
    if (obj)
    {
        int result = GetReferenceFlags(obj);
        if (result)
        {
            if (arg2[3] == arg2[5])
            {
                arg2[4] = result;
            }
            arg2[3] = arg2[3] + 1;
        }
    }
    arg2[3] = arg2[3] + 1;
}
}  // namespace fnv_004b6c70

namespace fnv_004b7210 {
struct UIRoot;
extern UIRoot* DAT_011d8a80;

// @fnv 0x004b7210
// src: COMMUNITY 0x004b7210
UIRoot* InterfaceManager_GetSingleton()
{
    return DAT_011d8a80;
}
}  // namespace fnv_004b7210

namespace fnv_004b50f0 {

extern int DAT_01268154;

struct FUN_004b50f0 : bhkSerializable
{
    FUN_004b50f0();
};

// Sets m_p to the address of DAT_0102016c and increments DAT_01268154.
// @fnv 0x004b50f0
FUN_004b50f0::FUN_004b50f0()
{
    ++DAT_01268154;
}
}  // namespace fnv_004b50f0

extern char const* const g_01268100_arg1;

struct FUN_004b5150_shell
{
    char const* const* __thiscall bhkSerializable_GetRTTI();
};

// @fnv 0x004b5150
// src: COMMUNITY 0x004b5150
char const* const* __thiscall FUN_004b5150_shell::bhkSerializable_GetRTTI()
{
    return &g_01268100_arg1;
}

extern void _delete(void* ptr, unsigned int size);

// Calls Destroy on this, then frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x004b5160
void* bhkSerializable::FUN_004b5160(unsigned int flags)
{
    this->Destroy();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

extern const char* const g_0126811c_arg1;

struct FUN_004b5190_shell
{
    const char* const* bhkAction_GetRTTI();
};

// @fnv 0x004b5190
// src: COMMUNITY 0x004b5190
const char* const* FUN_004b5190_shell::bhkAction_GetRTTI()
{
    return &g_0126811c_arg1;
}

extern void __cdecl _delete(void* ptr, unsigned int size);

// The shared base lacks this deleting-destructor entry.
struct UnaryActionDeletingDestructor : bhkUnaryAction
{
    void* __thiscall FUN_004b51e0(unsigned int flags);
};

// @fnv 0x004b51e0
void* __thiscall UnaryActionDeletingDestructor::FUN_004b51e0(unsigned int flags)
{
    this->FUN_00c86720();
    if (flags & 1)
        _delete(this, 16);
    return this;
}

int __fastcall GetCharAtOffset4(int);

// @fnv 0x004b5980
// src: XBOX_PDB 0x004b5980
int __fastcall hkpCollidable_getType(int param_1)
{
    return GetCharAtOffset4(param_1 + 0x14);
}

void const* __fastcall hkpCollidable_getOwner(char const*);

// @fnv 0x004b59c0
// src: XBOX_PDB 0x004b59c0
void const* __cdecl hkGetWorldObject_004b59c0(char const* arg)
{
    return hkpCollidable_getOwner(arg);
}

namespace fnv_004b4d10 {

struct UnaryActionSettings
{
    float f00;
    float f04;
    float f08;
    float f0C;
    bhkUnaryAction* ApplyToAction(bhkUnaryAction*);
};
// Calls Set on the given bhkUnaryAction with this object's four floats and returns the action.
// @fnv 0x004b4d10
bhkUnaryAction* UnaryActionSettings::ApplyToAction(bhkUnaryAction* apAction)
{
    apAction->Set(f00, f04, f08, f0C);
    return apAction;
}
}  // namespace fnv_004b4d10

namespace fnv_004b4ec0 {
struct FUN_004b4ee0_shell
{
    void hkpMotion_getPosition();
};
// @fnv 0x004b4ec0
// src: XBOX_PDB 0x004b4ec0
void __fastcall hkpRigidBody_getPosition(TESDataHandler* dataHandler)
{
    ((FUN_004b4ee0_shell*)dataHandler->GetBGSRagdollList())->hkpMotion_getPosition();
}
}  // namespace fnv_004b4ec0

extern "C" void __cdecl _ref_006815c0();
struct FUN_004b4f20_shell
{
    void __thiscall hkpMotion_getTransform();
};
// @fnv 0x004b4f20
// src: XBOX_PDB 0x004b4f20
void __thiscall FUN_004b4f20_shell::hkpMotion_getTransform()
{
    ((void(__thiscall*)(void*))_ref_006815c0)((char*)this + 0x10);
}

extern float DAT_0101b2d0;
extern float const g_011cc6cc_arg1;
struct Base537
{
    char _d[0x10];
    void hkUnaryActionCinfo_hkUnaryActionCinfo();
};
struct Mem4fa0
{
    char _d[0x10];
    void bhkVector4_bhkVector4();
};
struct FUN_004b4f40 : Base537
{
    Mem4fa0 m10;
    Mem4fa0 m20;
    float f30;
    float f34;
    float f38;
    float f3c;
    FUN_004b4f40();
};
// Calls base and member initializers, then sets f30 to 0.5, f34 to 0.3, f38 to DAT_0101b2d0 and f3c to g_011cc6cc_arg1.
// @fnv 0x004b4f40
FUN_004b4f40::FUN_004b4f40()
{
    hkUnaryActionCinfo_hkUnaryActionCinfo();
    m10.bhkVector4_bhkVector4();
    m20.bhkVector4_bhkVector4();
    f30 = 0.5f;
    f34 = 0.3f;
    f38 = DAT_0101b2d0;
    f3c = g_011cc6cc_arg1;
}

struct FUN_004b4fa0_shell
{
    void* __fastcall bhkVector4_bhkVector4();
};

void* __fastcall bhkVector4_setZero4(void*);

// @fnv 0x004b4fa0
// src: XBOX_PDB 0x004b4fa0
void* __fastcall FUN_004b4fa0_shell::bhkVector4_bhkVector4()
{
    bhkVector4_setZero4(this);
    return this;
}

struct S_004b4fc0
{
    void bhkVector4_set(float, float, float, float);
    void bhkVector4_setZero4();
};
// Calls FUN_004b4ff0 with four zero float arguments.
// @fnv 0x004b4fc0
// src: XBOX_PDB 0x004b4fc0
void S_004b4fc0::bhkVector4_setZero4()
{
    bhkVector4_set(0.0f, 0.0f, 0.0f, 0.0f);
}

extern int DAT_0102009c;
extern int DAT_01268118;
struct Fake004b50c0
{
    void FUN_004b50f0();
    Fake004b50c0* InitializeFields_004b50c0();
};
// @fnv 0x004b50c0
// src: GUESS 0x004b50c0 (confidence: low)
Fake004b50c0* Fake004b50c0::InitializeFields_004b50c0()
{
    FUN_004b50f0();
    *(int*)this = (int)&DAT_0102009c;
    DAT_01268118++;
    return this;
}

void __cdecl _delete(void*, unsigned int);
// Calls FUN_00c86cb0, frees this with _delete when flags has bit 0 set, and returns this.
// @fnv 0x004b5230
void* __thiscall bhkMouseSpringAction::FUN_004b5230(unsigned int flags)
{
    this->FUN_00c86cb0();
    if (flags & 1)
        _delete(this, 0x10);
    return this;
}

namespace fnv_004b5260 {

// @fnv 0x004b5260
// src: XBOX_PDB 0x004b5260
NiAVObject* FindFirstCollisionObject(NiAVObject* object)
{
    NiAVObject* result = 0;
    if (object)
    {
        result = reinterpret_cast<NiAVObject*>(bhkCollisionObject::GetFromNiAVObject(object));
        if (!result)
        {
            NiNode* node = object->IsSceneNode();
            if (node)
            {
                unsigned int count = node->GetNumChildren();
                for (unsigned int i = 0; i < count; ++i)
                {
                    result = FindFirstCollisionObject(node->GetAt(i));
                    if (result)
                        break;
                }
            }
        }
    }
    return result;
}
}  // namespace fnv_004b5260

// @fnv 0x004b5470
// src: XBOX_PDB 0x004b5470
int LengthCheck_004b5470(TESCombatStyle* apCombatStyle, float afValue)
{
    float f1;
    float f2;
    f1 = apCombatStyle->UpdateCombatStyle();
    f2 = afValue * afValue;
    if (f1 < f2)
        return -1;
    else
    {
        if (f1 > f2)
            return 1;
    }
    return 0;
}

extern float runtimeInitializationFloat825;
float __cdecl asin_004b5510(float);
// @fnv 0x004b54c0
// src: XBOX_PDB 0x004b54c0
float __cdecl NiASin_004b54c0(float afValue)
{
    if (afValue > -1.0)
    {
        if (afValue < 1.0)
        {
            return asin_004b5510(afValue);
        }
        else
        {
            return runtimeInitializationFloat825;
        }
    }
    else
    {
        return -runtimeInitializationFloat825;
    }
}

extern NiRTTI g_011f3728;
// Returns true if object or any descendant NiNode child has a controller matching g_011f3728; recurses through children.
// @fnv 0x004b5bf0
// src: XBOX_PDB 0x004b5bf0
bool HasMorpherController(NiAVObject* object)
{
    if (!object)
        return false;
    if (object->GetController(&g_011f3728))
        return true;
    NiNode* node = object->IsSceneNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->GetNumChildren(); ++i)
        {
            NiAVObject* child = node->GetAt(i);
            if (HasMorpherController(child))
                return true;
        }
    }
    return false;
}

class NiCamera;
bool __cdecl IsBoundVisible(NiBound*, NiCamera*);
// Returns false if apObject is null, otherwise tests the object's bound against apCamera via IsBoundVisible.
// @fnv 0x004b5fc0
// src: XBOX_PDB 0x004b5fc0
bool __cdecl NodeInFrustum(NiAVObject* apObject, NiCamera* apCamera)
{
    if (apObject)
    {
        return IsBoundVisible(const_cast<NiBound*>(&apObject->NiAVObject_GetWorldBound()), apCamera);
        goto done;
    }
    return false;
done:;
}

namespace CollisionObjectCount {
struct IntegerAndByteRecord
{
    int _00;
    unsigned char _04;
    int _08;
    int _0C;
    int _10;
    int _14;
    int _18;
};
}
void __cdecl GetHavokWorldObjectCount(NiCollisionObject*, CollisionObjectCountContext*);
// @fnv 0x004b6ae0
// src: COMMUNITY 0x004b6ae0
int GetHavokWorldObjectCountInSceneGraph(NiAVObject* apRoot)
{
    CollisionObjectCount::IntegerAndByteRecord recData;
    recData._08 = 18;
    recData._04 = 1;
    recData._0C = 0;
    bhkWorld_DoObjectRec(apRoot, reinterpret_cast<CollisionObjectCountContext*>(&recData), GetHavokWorldObjectCount);
    return recData._0C;
}

class hkpWorldObject;
namespace fnv_004b6c20 {
namespace CollisionObjectCount {
struct IntegerAndByteRecord
{
    int _0;
    bool _4;
    char _5;
    char _6;
    char _7;
    int _8;
    int _12;
    hkpWorldObject* _16;
    int _20;
    int _24;
};
}
void __cdecl GetHavokWorldObjectByIndex(NiCollisionObject*, CollisionObjectCountContext*);
// @fnv 0x004b6c20
hkpWorldObject* FindCollisionObjectByIndex(NiAVObject* apRoot, int aiIndex)
{
    CollisionObjectCount::IntegerAndByteRecord recData;
    recData._8 = 0x12;
    recData._4 = 1;
    recData._12 = 0;
    recData._16 = 0;
    recData._20 = aiIndex;
    bhkWorld_DoObjectRec(apRoot, (CollisionObjectCountContext*)&recData, GetHavokWorldObjectByIndex);
    return recData._16;
}
}  // namespace fnv_004b6c20

struct S004e88d0
{
    float m0;
    float m4;
    S004e88d0& Add(S004e88d0*);
};
// Adds the two floats of p into this object's m0 and m4 and returns *this.
// @fnv 0x004e88d0
S004e88d0& S004e88d0::Add(S004e88d0* apOther)
{
    m0 += apOther->m0;
    m4 += apOther->m4;
    return *this;
}

struct Flt
{
    operator unsigned int() const;
};

struct FUN_004b70d0_shell
{
    char pad[0x3c];
    Flt m_flt;
    unsigned int NiSourceTexture_GetSrcPixelData();
};

// @fnv 0x004b70d0
// src: COMMUNITY 0x004b70d0
unsigned int FUN_004b70d0_shell::NiSourceTexture_GetSrcPixelData()
{
    return m_flt.operator unsigned int();
}

struct Sub004B
{
    char pad[16];
    void bhkVector4_bhkVector4();
    void bhkVector4_set(float, float, float, float);
};
struct Sub0056
{
    char pad[16];
    void hkConvexShapeCinfo_hkConvexShapeCinfo();
};
struct Owner0066d650
{
    Sub0056 f0;
    Sub004B f10;
    Sub004B f20;
    Owner0066d650* Reset();
};
// @fnv 0x0066d650
Owner0066d650* Owner0066d650::Reset()
{
    f0.hkConvexShapeCinfo_hkConvexShapeCinfo();
    f10.bhkVector4_bhkVector4();
    f20.bhkVector4_bhkVector4();
    f20.bhkVector4_set(1.0f, 0.0f, 0.0f, 0.0f);
    return this;
}

namespace fnv_004b2800 {
bool __fastcall GetByteAtOffset17(const char*);
NiPoint3* __fastcall _ref_006815c0(NiBound*);

// @fnv 0x004b2800
bool PickObjectsInRadius(NiPick* pick, const NiPoint3& origin, const NiPoint3& dir, float radius, NiAVObject* object)
{
    bool result = false;
    if (pick && object && (!GetByteAtOffset17((const char*)pick) || !object->GetAppCulled_00456610()))
    {
        if (!object->IsVisualObject())
            return false;
        // Preserve the original trivial bound copy without calling its shared copy constructor.
        unsigned int boundStorage[sizeof(NiBound) / sizeof(unsigned int)];
        memcpy(boundStorage, &object->NiAVObject_GetWorldBound(), sizeof(NiBound));
        NiPoint3 kDiff = *_ref_006815c0(reinterpret_cast<NiBound*>(boundStorage)) - origin;
        if (kDiff.Length() < reinterpret_cast<NiBound*>(boundStorage)->FUN_0084d030() + radius)
        {
            NiNode* node = object->IsSceneNode();
            if (node)
            {
                int count = node->GetNumChildren();
                for (int i = 0; i < count; i++)
                {
                    NiAVObject* child = node->GetAt(i);
                    if (PickObjectsInRadius(pick, origin, dir, radius, child))
                        result = true;
                }
            }
            else
            {
                pick->SetTarget_00705fc0(static_cast<void*>(object));
                if (pick->PerformPick(origin, dir, true))
                    result = true;
            }
        }
    }
    return result;
}
}  // namespace fnv_004b2800

struct BSShaderAccumulator;
struct BSShaderTextureSet;
struct BSTextureSet;
struct NiAdditionalGeometryData;
struct CloningProcess;
struct NiStream;
struct NiTriBasedGeom;
struct ShadowSceneLight;
struct blob16
{
    char b[16];
};

int __cdecl NiShadeProperty_GetType();
BSShaderPPLightingProperty* __cdecl FindAcceptedForm(NiNode*);
// Scans the node's children in reverse for a BSShaderPPLightingProperty, returning it if found, otherwise falling back to FindAcceptedForm.
// @fnv 0x004b5710
BSShaderPPLightingProperty* __cdecl FindPPLightingProperty(NiNode* apNode)
{
    if (!apNode->GetNumChildren())
        return 0;
    unsigned int n = apNode->GetNumChildren() - 1;
    while (true)
    {
        NiAVObject* pobj = apNode->GetAt(n);
        if (pobj)
        {
            NiNode* pnode = pobj->IsSceneNode();
            if (pnode)
            {
                NiAVObject* pchild = pnode->NiNode_GetAtChecked(0u);
                if (pchild)
                {
                    NiShadeProperty* pproperty = (NiShadeProperty*)pchild->GetProperty(NiShadeProperty_GetType());
                    if (pproperty)
                    {
                        BSShaderPPLightingProperty* plightingProperty =
                            (BSShaderPPLightingProperty*)((pproperty == 0
                                                               ? 0
                                                               : (((NiTimeController*)pproperty)->FUN_00441110() >= 8 &&
                                                                  ((NiTimeController*)pproperty)->FUN_00441110() <= 12))
                                                              ? pproperty
                                                              : 0);
                        if (plightingProperty)
                            return plightingProperty;
                    }
                }
            }
        }
        if (n == 0)
            break;
        n--;
    }
    return FindAcceptedForm(apNode);
}

extern double _gModifierZero;
extern double DAT_0101ff58;

// @fnv 0x004b15e0
// src: XBOX_PDB 0x004b15e0
float __cdecl GetAngleDelta(float startAngle, float targetAngle, float* pfOutDir)
{
    float angleDelta = targetAngle - startAngle;
    *pfOutDir = 0.0f;
    if (angleDelta != _gModifierZero)
    {
        *pfOutDir = 1.0f;
        if (angleDelta < _gModifierZero)
        {
            if (angleDelta > DAT_0101ff58)
                *pfOutDir = -1.0f;
            else
                angleDelta += 6.2831855f;
        }
        else if (angleDelta > (double)3.1415927f)
        {
            *pfOutDir = -1.0f;
            angleDelta = 6.2831855f - angleDelta;
        }
    }
    return angleDelta;
}

extern const NiRTTI DAT_011f4428;
// @fnv 0x004b70f0
// src: COMMUNITY 0x004b70f0
void BSUtils_SetPhaseRecurse(NiNode* apNode, float afPhase)
{
    if (!apNode)
        return;
    NiTimeController* pcont = static_cast<const NiObjectNET*>(apNode)->GetControllers();
    while (pcont)
    {
        pcont->SetSequenceTime(afPhase);
        pcont = pcont->GetNext();
    }
    unsigned int n = 0;
    for (; n < apNode->GetNumChildren(); ++n)
    {
        NiAVObject* pobj = apNode->GetAt(n);
        if (pobj && NiObject_IsKindOf(&DAT_011f4428, pobj))
            BSUtils_SetPhaseRecurse((NiNode*)pobj, afPhase);
    }
}

struct NiCamera;

bool IsBoundVisible(NiBound*, NiCamera*);

// @fnv 0x004b61d0
// src: XBOX_PDB 0x004b61d0
bool PointInFrustum(NiPoint3 location, NiCamera* camera, float radius)
{
    if (!camera)
        return false;
    NiBound sphere;
    sphere.SetGridPosition(&location);
    sphere.SetRadius(radius);
    return IsBoundVisible(&sphere, camera);
}

extern const char* const g_0120043c_arg1;
struct _UseSaveGameBlocks;
_UseSaveGameBlocks* _UseSaveGameBlocks(const char* const*, void*);
struct PropHelper
{
    void AssignRefObj(unsigned int);
};
void UnTintScenegraph(NiAVObject*);
// @fnv 0x004b6630
// src: XBOX_PDB 0x004b6630
void UnTintScenegraph(NiAVObject* object)
{
    PropHelper* result = (PropHelper*)_UseSaveGameBlocks(&g_0120043c_arg1, object->GetProperty(3));
    if (result)
        result->AssignRefObj(0);
    NiNode* node = object->IsSceneNode();
    if (node)
    {
        unsigned int i = 0;
        for (; i < node->GetNumChildren(); ++i)
        {
            if (node->GetAt(i))
                UnTintScenegraph(node->GetAt(i));
        }
    }
}

// @fnv 0x004b4ea0
// src: XBOX_PDB 0x004b4ea0
float TESDataHandler::hkpRigidBody_getMass()
{
    return reinterpret_cast<hkpMotion*>(GetBGSRagdollList())->GetMassValue();
}

struct FUN_004b5020_shell
{
    int vftable;
    void _ref_006815c0();
    FUN_004b5020_shell* hkActionCinfo_hkActionCinfo();
};

// @fnv 0x004b5020
// src: XBOX_PDB 0x004b5020
FUN_004b5020_shell* FUN_004b5020_shell::hkActionCinfo_hkActionCinfo()
{
    _ref_006815c0();
    vftable = 0;
    return this;
}

namespace fnv_004b68a0 {
int __cdecl BSstrcmp(char const*, char const*);

extern void const* const DAT_011f9140;
extern NiRTTI g_0126817c;

// Exe 0x004b68a0: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct GlobalfuncOffset08View
{
    unsigned int GetFlags();
};

struct FUN_004b68a0_data
{
    void* field_00;
    void* field_04;
    void* field_08;
    int field_0c;
    GlobalfuncOffset08View* field_10;
    int field_14;
    unsigned int field_18;
};

// Checks RTTI and fade-node conditions on object, resets field_14 when object matches field_10, then increments field_0c.
// @fnv 0x004b68a0
// src: COMMUNITY 0x004b68a0
void GetCollisionObjectIndex(GlobalfuncOffset08View* object, FUN_004b68a0_data* data)
{
    if ((data->field_18 & 1) && NiObject_IsKindOf(&g_0126817c, reinterpret_cast<NiAVObject*>(object)))
        return;

    if ((data->field_18 & 2) &&
        NiObject_IsKindOf(reinterpret_cast<const NiRTTI*>(&DAT_011f9140), reinterpret_cast<NiAVObject*>(object->GetFlags())))
        return;

    if ((data->field_18 & 2) && object->GetFlags() &&
        reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(object->GetFlags())->GetLinkToList())
            ->FUN_0043b1b0())
    {
        if (!BSstrcmp(reinterpret_cast<char const*>(
                              reinterpret_cast<BSFadeNode*>(
                                  reinterpret_cast<TESTopicInfoData*>(object->GetFlags())->GetLinkToList())
                                  ->FUN_0043b1b0()),
                          "Arrow"))
            return;
    }

    if (object == data->field_10)
        data->field_14 = data->field_0c;

    data->field_0c++;
}
}  // namespace fnv_004b68a0

// Exe 0x004b6a00: local storage view; GetFlags binds the folded DWORD-at-+8 accessor 0x0044ddc0.
struct GlobalfuncOffset08View
{
    unsigned int GetFlags();
};

struct FUN_004b6a00_data
{
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    NiAVObject* field_10;
    int field_14;
    unsigned int field_18;
};

extern NiRTTI DAT_011f9140;
extern NiRTTI g_0126817c;

int __cdecl BSstrcmp(char const*, char const*);

// Checks object against data flags and RTTI, stores it in field_10 when field_0c equals field_14, then increments field_0c.
// @fnv 0x004b6a00
void __cdecl ProcessObjectMatch(NiAVObject* object, FUN_004b6a00_data* data)
{
    if (data->field_18 & 1)
    {
        if (NiObject_IsKindOf(&g_0126817c, object))
            return;
    }

    if (data->field_18 & 2)
    {
        if (NiObject_IsKindOf(&DAT_011f9140, reinterpret_cast<NiAVObject*>(reinterpret_cast<GlobalfuncOffset08View*>(object)->GetFlags())))
            return;
    }

    if (data->field_18 & 2)
    {
        if (reinterpret_cast<GlobalfuncOffset08View*>(object)->GetFlags())
        {
            if (reinterpret_cast<BSFadeNode*>(
                    reinterpret_cast<TESTopicInfoData*>(reinterpret_cast<GlobalfuncOffset08View*>(object)->GetFlags())
                        ->GetLinkToList())
                    ->FUN_0043b1b0())
            {
                if (!BSstrcmp(static_cast<char const*>(
                                      reinterpret_cast<BSFadeNode*>(reinterpret_cast<TESTopicInfoData*>(
                                                                        reinterpret_cast<GlobalfuncOffset08View*>(object)->GetFlags())
                                                                        ->GetLinkToList())
                                          ->FUN_0043b1b0()),
                                  "Arrow"))
                    return;
            }
        }
    }

    if (data->field_0c == data->field_14)
        data->field_10 = object;

    data->field_0c++;
}

namespace fnv_004b6e90 {

void AttachLightingPropertyRecursive(NiAVObject* object);

// Recursively attaches a new BSShaderNoLightingProperty to geometry objects lacking property 3, descending through NiNode children.
// @fnv 0x004b6e90
void AttachLightingPropertyRecursive(NiAVObject* object)
{
    if (object->IsGeometry() && !object->GetProperty(3))
    {
        BSShaderNoLightingProperty* lightingProperty = new BSShaderNoLightingProperty();
        object->AttachProperty(lightingProperty);
    }

    NiNode* node = object->IsSceneNode();
    if (node)
    {
        for (unsigned int index = 0; index < node->GetNumChildren(); ++index)
        {
            NiAVObject* child = node->GetAt(index);
            if (child)
                AttachLightingPropertyRecursive(child);
        }
    }
}
}  // namespace fnv_004b6e90

// @fnv 0x004b5b00
NiBlendTransformInterpolator* NiMultiTargetTransformController::GetBlendInterpolator(unsigned short index)
{
    return m_pkBlendInterpolators + index;
}

extern NiRTTI DAT_011f36ac;

NiObject* NiDynamicCast(const NiRTTI*, NiObject*);

class TimedTextEntry
{
  public:
    int unk00;
    int unk04;
    NiFixedString* GetName();
    float GetValue();
};

template <class T> unsigned int BSStringLength(const T*);
extern "C" int _strnicmp(const char*, const char*, unsigned int);

// Looks up the named sequence on obj's controller manager and returns the value of the first entry whose name starts with prefix, else 0.
// @fnv 0x004b6220
float GetAnimValueByPrefix(NiObjectNET* obj, const char* name, const char* prefix)
{
    if (!obj)
        return 0.0f;
    NiControllerManager* mgr = (NiControllerManager*)NiDynamicCast(&DAT_011f36ac, obj->GetControllers());
    if (mgr)
    {
        NiControllerSequence* seq3 = mgr->NiControllerManager_GetSequenceByName(NiFixedString(name));
        if (seq3)
        {
            NiTextKeyExtraData* data8 = seq3->GetName_00700300();
            unsigned int aCount;
            TimedTextEntry* entries3 = data8->GetKeys_00495f30(&aCount);
            unsigned int len = BSStringLength(prefix);
            if (len > 0)
            {
                for (unsigned int i4 = 0; i4 < aCount; i4++)
                {
                    const char* s4 = *entries3[i4].GetName();
                    if (s4 && !_strnicmp(s4, prefix, len))
                        return entries3[i4].GetValue();
                }
            }
        }
    }
    return 0.0f;
}

struct S_004b6810_Filter
{
    int m_00;
    bool m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
};

typedef int(__cdecl* PFN_004b68a0)(S_004b6810_Filter*);
int __cdecl GetCollisionObjectIndex(S_004b6810_Filter*);
int __cdecl bhkWorld_DoObjectRec(void*, S_004b6810_Filter*, PFN_004b68a0);

// Builds a filter struct from the flags and a2, runs FUN_00c68900 over a1, and returns the filter's m_14 result or -1.
// @fnv 0x004b6810
int __cdecl FilterByFlags(void* a1, int iValue, bool abSkipPhantoms, bool abSkipBlend, bool abSkipUnknown)
{
    S_004b6810_Filter kFilter;
    kFilter.m_08 = 0x12;
    kFilter.m_04 = true;
    kFilter.m_0c = 0;
    kFilter.m_10 = iValue;
    kFilter.m_14 = -1;
    kFilter.m_18 = 0;
    if (abSkipPhantoms)
        kFilter.m_18 |= 1;
    if (abSkipBlend)
        kFilter.m_18 |= 2;
    if (abSkipUnknown)
        kFilter.m_18 |= 4;
    bhkWorld_DoObjectRec(a1, &kFilter, GetCollisionObjectIndex);
    return (kFilter.m_14 != -1) ? kFilter.m_14 : -1;
}

void __cdecl ProcessObjectMatch(NiCollisionObject*, CollisionObjectCountContext*);

struct FUN_004b6980_Context
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    void* pUserData;
    int iCount;
    void* pAuxiliaryData;
    unsigned int uiFilterFlags;
};

// Builds a traversal context from the three flags, runs FUN_00c68900 over object with ProcessObjectMatch, and returns the accumulated count.
// @fnv 0x004b6980
// src: XBOX_PDB 0x004b6980
int __cdecl GetCollisionObjectByIndexInSceneGraph(NiAVObject* object, void* auxiliaryData, bool flag1, bool flag2, bool flag3)
{
    FUN_004b6980_Context context;

    context.uiTraversalFlags = 0x12;
    context.bRecurse = true;
    context.pUserData = 0;
    context.iCount = 0;
    context.pAuxiliaryData = auxiliaryData;
    context.uiFilterFlags = 0;

    if (flag1)
    {
        context.uiFilterFlags |= 1;
    }
    if (flag2)
    {
        context.uiFilterFlags |= 2;
    }
    if (flag3)
    {
        context.uiFilterFlags |= 4;
    }

    bhkWorld_DoObjectRec(object, reinterpret_cast<CollisionObjectCountContext*>(&context), ProcessObjectMatch);

    return context.iCount;
}

void GetHavokWorldObjectIndex(NiCollisionObject* pkObject, CollisionObjectCountContext* pkContext);

// Traverses pkRoot with a context that counts collision objects and returns the auxiliary result, or -1 when it is unset.
// @fnv 0x004b6b60
// src: COMMUNITY 0x004b6b60
int GetHavokWorldObjectIndexInSceneGraph(NiAVObject* pkRoot, void* pvUserData)
{
    CollisionObjectCountContext kContext;
    kContext.uiTraversalFlags = 0x12;
    kContext.bRecurse = true;
    kContext.iCount = 0;
    kContext.pUserData = pvUserData;
    kContext.pAuxiliaryData = reinterpret_cast<void*>(-1);
    bhkWorld_DoObjectRec(pkRoot, &kContext, GetHavokWorldObjectIndex);
    return reinterpret_cast<int>(kContext.pAuxiliaryData) != -1 ? reinterpret_cast<int>(kContext.pAuxiliaryData) : -1;
}

class FUN_004b6ce0_cls
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual FUN_004b6ce0_cls* vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void* vfn_1c();
    FUN_004b6ce0_cls* FUN_00a59d30(int);
    int FUN_00441110();
    unsigned int GetNumChildren();
    FUN_004b6ce0_cls* FUN_0043b4a0(unsigned int);
};

class FUN_004b6ce0_gl
{
  public:
    void FUN_004534f0(void*);
};
extern FUN_004b6ce0_gl DAT_011e0e80;
int BSSM_ShaderPropertyIsLighting(void*);

// @fnv 0x004b6ce0
// src: COMMUNITY 0x004b6ce0
void RecursivelyRemoveAllDecals(FUN_004b6ce0_cls* p)
{
    FUN_004b6ce0_cls* RunFourthVirtual;
    FUN_004b6ce0_cls* x8;
    void* y;
    bool flag4;
    FUN_004b6ce0_cls* c;
    unsigned int i2;

    if (p == 0)
        return;
    if (p->vfn_1c() != 0)
    {
        x8 = p;
        RunFourthVirtual = x8->FUN_00a59d30(3);
        if (RunFourthVirtual != 0)
        {
            y = BSSM_ShaderPropertyIsLighting(RunFourthVirtual) ? RunFourthVirtual : 0;
            if (y != 0)
            {
                flag4 = false;
                if (RunFourthVirtual->FUN_00441110() == 3)
                    flag4 = true;
                DAT_011e0e80.FUN_004534f0(y);
                if (flag4)
                    return;
            }
        }
    }
    else
    {
        c = p->vfn_c();
        if (c != 0)
        {
            for (i2 = 0; i2 < c->GetNumChildren(); i2++)
                RecursivelyRemoveAllDecals(c->FUN_0043b4a0(i2));
        }
    }
}

void __cdecl FUN_00b57e30(NiAVObject*, int, int);

// Adds a BSShaderNoLightingProperty with shader flag 0x30 to a geometry lacking property 3, or recurses into a visual node's children.
// @fnv 0x004b6f90
void __cdecl EnsureLightingProperty(NiAVObject* apObject)
{
    if (apObject->IsGeometry() && !apObject->GetProperty(3))
    {
        BSShaderNoLightingProperty* pProp = new BSShaderNoLightingProperty;
        pProp->SetFlag(0x30, true);
        apObject->AttachProperty(pProp);
        apObject->UpdateProperties();
        FUN_00b57e30(apObject, 0, 0);
    }
    else
    {
        NiNode* pNode = apObject->IsSceneNode();
        if (pNode && pNode->IsVisualObject())
        {
            for (unsigned int i = 0; i < pNode->GetNumChildren(); i++)
            {
                NiAVObject* pChild = pNode->GetAt(i);
                if (pChild)
                    EnsureLightingProperty(pChild);
            }
        }
    }
}

// Deletes each of the global objects pointed to by DAT_011c61a4 through DAT_011c6278.
// @fnv 0x004b8cf0
// src: COMMUNITY 0x004b8cf0
void __cdecl FreeNiNodeBlocks()
{
    delete DAT_011c61a4;
    delete DAT_011c61a8;
    delete DAT_011c61ac;
    delete DAT_011c61b0;
    delete DAT_011c61bc;
    delete DAT_011c61c0;
    delete DAT_011c61c4;
    delete DAT_011c61c8;
    delete DAT_011c61cc;
    delete DAT_011c61d0;
    delete DAT_011c61d4;
    delete DAT_011c61d8;
    delete DAT_011c61dc;
    delete DAT_011c61e0;
    delete DAT_011c61e4;
    delete DAT_011c61e8;
    delete DAT_011c61ec;
    delete DAT_011c61f0;
    delete DAT_011c61f4;
    delete DAT_011c61f8;
    delete DAT_011c61fc;
    delete DAT_011c6200;
    delete DAT_011c6204;
    delete DAT_011c6208;
    delete DAT_011c620c;
    delete DAT_011c6210;
    delete DAT_011c6214;
    delete DAT_011c6218;
    delete DAT_011c621c;
    delete DAT_011c6220;
    delete DAT_011c6224;
    delete DAT_011c6228;
    delete DAT_011c622c;
    delete DAT_011c6230;
    delete DAT_011c6234;
    delete DAT_011c6238;
    delete DAT_011c623c;
    delete DAT_011c6240;
    delete DAT_011c6244;
    delete DAT_011c6248;
    delete DAT_011c624c;
    delete DAT_011c6250;
    delete DAT_011c6254;
    delete DAT_011c6258;
    delete DAT_011c625c;
    delete DAT_011c6260;
    delete DAT_011c6264;
    delete DAT_011c6268;
    delete DAT_011c626c;
    delete DAT_011c6270;
    delete DAT_011c6274;
    delete DAT_011c6278;
}

// Maps an input byte to a fixed index via a switch, returning -1 for unmapped values.
// @fnv 0x004b1680
int MapByteToIndex(unsigned char a)
{
    switch (a)
    {
    case 21:
        return 0;
    case 24:
        return 1;
    case 25:
        return 2;
    case 27:
        return 3;
    case 28:
        return 4;
    case 29:
        return 5;
    case 30:
        return 6;
    case 31:
        return 7;
    case 50:
        return 66;
    case 46:
        return 20;
    case 32:
        return 8;
    case 33:
        return 72;
    case 34:
        return 43;
    case 35:
        return 45;
    case 36:
        return 9;
    case 37:
        return 10;
    case 40:
        return 11;
    case 41:
        return 21;
    case 42:
        return 12;
    case 43:
        return 13;
    case 44:
        return 14;
    case 45:
        return 15;
    case 20:
        return 16;
    case 19:
        return 17;
    case 47:
        return 18;
    case 52:
        return 19;
    case 18:
        return 25;
    case 91:
        return 46;
    case 13:
        return 24;
    case 39:
        return 23;
    case 38:
        return 22;
    case 74:
        return 26;
    case 75:
        return 27;
    case 76:
        return 28;
    case 77:
        return 29;
    case 78:
        return 30;
    case 48:
        return 31;
    case 79:
        return 32;
    case 51:
        return 33;
    case 81:
        return 35;
    case 22:
        return 34;
    case 23:
        return 44;
    case 4:
        return 36;
    case 82:
        return 37;
    case 5:
        return 38;
    case 85:
        return 39;
    case 86:
        return 40;
    case 87:
        return 41;
    case 97:
        return 64;
    case 88:
        return 42;
    case 94:
        return 47;
    case 95:
        return 48;
    case 71:
        return 49;
    case 73:
        return 50;
    case 93:
        return 51;
    case 7:
        return 52;
    case 12:
        return 53;
    case 11:
        return 54;
    case 9:
        return 55;
    case 8:
        return 56;
    case 49:
        return 57;
    case 53:
        return 58;
    case 54:
        return 59;
    case 14:
        return 67;
    case 102:
        return 71;
    case 16:
        return 70;
    case 103:
        return 73;
    case 104:
        return 74;
    case 106:
        return 75;
    case 107:
        return 76;
    case 114:
        return 83;
    case 108:
        return 77;
    case 109:
        return 78;
    case 110:
        return 79;
    case 111:
        return 80;
    case 112:
        return 81;
    case 113:
        return 82;
    case 115:
        return 84;
    case 116:
        return 85;
    case 117:
        return 86;
    default:
        return -1;
    }
}

struct FormName
{
    const char* name;
    int unk04;
    int unk08;
};
extern FormName FNV_FormTypeNames[];
extern const char* typeNames[];
int __cdecl LookupType(unsigned char);
void __cdecl Warn(const char*, ...);
extern const char* DAT_01188f98;
extern const char* DAT_01188f9c;
extern const char* DAT_01188fa0;
extern const char* DAT_01188fa4;
extern const char* DAT_01188fa8;
extern const char* DAT_01188fac;
extern const char* DAT_01188fb0;
extern const char* DAT_01188fb4;
extern const char* DAT_01188fb8;
extern const char* DAT_01188fbc;
extern const char* DAT_01188fc0;
extern const char* DAT_01188fc4;
extern const char* DAT_01188fc8;
extern const char* DAT_01188fcc;
extern const char* DAT_01188fd0;
extern const char* DAT_01188fd4;
extern const char* DAT_01188fd8;
extern const char* DAT_01188fdc;
extern const char* DAT_01188fe0;
extern const char* DAT_01188fe4;
extern const char* DAT_01188fe8;
extern const char* DAT_01188fec;
extern const char* DAT_01188ff0;
extern const char* DAT_01188ff4;
extern const char* DAT_01188ff8;
extern const char* DAT_01188ffc;
extern const char* DAT_01189000;
extern const char* DAT_01189004;
extern const char* DAT_01189008;
extern const char* DAT_0118900c;
extern const char* DAT_01189010;
extern const char* DAT_01189014;
extern const char* DAT_01189018;
extern const char* DAT_0118901c;
extern const char* DAT_01189020;
extern const char* DAT_01189024;
extern const char* DAT_01189028;
extern const char* DAT_0118902c;
extern const char* DAT_01189030;
extern const char* DAT_01189034;

// Returns the type name string for a form type code, looking it up in typeNames, then a switch table, then FNV_FormTypeNames, warning on invalid codes.
// @fnv 0x004b1b60
// src: XBOX_PDB 0x004b1b60
const char* __cdecl FormIDToString(unsigned char type)
{
    int index = LookupType(type);
    if (index >= 0)
        return typeNames[index];
    switch (type)
    {
    case 12:
        return DAT_01188f98;
    case 7:
        return DAT_01188f9c;
    case 17:
        return DAT_01188fa0;
    case 69:
        return DAT_01188fa4;
    case 57:
        return DAT_01188fa8;
    case 8:
        return DAT_01188fac;
    case 13:
        return DAT_01188fb0;
    case 6:
        return DAT_01188fb4;
    case 55:
        return DAT_01188fb8;
    case 3:
        return DAT_01188fbc;
    case 16:
        return DAT_01188fc0;
    case 65:
        return DAT_01188fc4;
    case 54:
        return DAT_01188fc8;
    case 53:
        return DAT_01188fcc;
    case 15:
        return DAT_01188fd0;
    case 71:
        return DAT_01188fd4;
    case 9:
        return DAT_01188fd8;
    case 10:
        return DAT_01188fdc;
    case 11:
        return DAT_01188fe0;
    case 58:
        return DAT_01188fe4;
    case 72:
        return DAT_01188fe8;
    case 73:
        return DAT_01188fec;
    case 49:
        return DAT_01188ff0;
    case 83:
        return DAT_01188ff4;
    case 84:
        return DAT_01188ff8;
    case 14:
        return DAT_01188ffc;
    case 102:
        return DAT_01189000;
    case 104:
        return DAT_01189004;
    case 106:
        return DAT_01189008;
    case 107:
        return DAT_0118900c;
    case 108:
        return DAT_01189010;
    case 109:
        return DAT_01189014;
    case 110:
        return DAT_01189018;
    case 111:
        return DAT_0118901c;
    case 112:
        return DAT_01189020;
    case 113:
        return DAT_01189024;
    case 114:
        return DAT_01189028;
    case 115:
        return DAT_0118902c;
    case 116:
        return DAT_01189030;
    case 117:
        return DAT_01189034;
    default:
        if (type >= 121)
        {
            Warn("FORMS: Invalid FormID sent to FormIDToString().\r\n", FNV_FormTypeNames[type].name);
            type = 0;
        }
        return FNV_FormTypeNames[type].name;
    }
}

// Builds a 4-vertex square NiLines from four corner points at +/-extent, fills all vertex colors with color, and optionally attaches a BSShaderNoLightingProperty.
// @fnv 0x004b3b90
NiLines* __cdecl CreateSquareLines(float extent, const NiColorA& color, bool addLighting)
{
    NiPoint3* pVertices = new NiPoint3[4];
    NiColorA* pColors = new NiColorA[4];
    bool* pEnabled = new bool[4];
    pVertices[0] = NiPoint3(-extent, -extent, 0.0f);
    pVertices[1] = NiPoint3(-extent, extent, 0.0f);
    pVertices[2] = NiPoint3(extent, extent, 0.0f);
    pVertices[3] = NiPoint3(extent, -extent, 0.0f);
    for (int i = 0; i < 4; ++i)
    {
        pColors[i] = color;
        pEnabled[i] = true;
    }
    NiLines* lines = new NiLines(4, reinterpret_cast<stand::NiPoint3*>(pVertices), reinterpret_cast<NiColorA*>(pColors), 0, 0, 0, pEnabled);
    if (addLighting)
    {
        BSShaderNoLightingProperty* property = new BSShaderNoLightingProperty;
        lines->AttachProperty(property);
        FUN_00b57e30((NiAVObject*)lines, 0, 0);
    }
    return lines;
}

struct AuxPoint
{
    float x, y;
    AuxPoint();
};

struct Entry
{
    unsigned int first, second;
    float bestDistance10;
};
struct PairMap
{
    int unk00, unk04, unk08, unk0c;
    PairMap(int);
    ~PairMap();
    bool NiTMapBase_DFALL_NiTMapItem_unsigned_int_VertexDist_unsigned_int_VertexDist_GetAt(unsigned int, Entry&);
    void SetOrInsert(unsigned int, Entry);
    void* FUN_004b9ba0();
    void GetNextEntry(void*&, unsigned int&, Entry&);
};
NiPoint3* CreateElementArray(NiGeometry*);
bool FloatEQ(float, float, float);
NiPoint3 FUN_004a3760(float, const NiPoint3&);
extern NiGeometry* DAT_011c6320;
void __cdecl operator delete(void*);
// @fnv 0x004b3e60
bool __cdecl MatchGeometryVertices(NiGeometry* source, NiGeometry* target, float threshold, float unused, bool adjust)
{
    PairMap map30(37);
    NiMatrix3 rotation4;
    NiTransform aTransform;
    AuxPoint point12;
    bool bChangedB = false;
    if (!source || !target || source == target)
        return false;
    NiPoint3* sourceVertices7 = reinterpret_cast<NiPoint3*>(source->GetVertices());
    NiPoint3* sourceNormals2 = reinterpret_cast<NiPoint3*>(source->GetNormals());
    unsigned int uiCountX = source->GetVertexCount();
    if (!sourceVertices7 || !sourceNormals2 || !uiCountX)
        return false;
    NiPoint3* targetVertices5 = reinterpret_cast<NiPoint3*>(target->GetVertices());
    NiPoint3* targetNormals2 = reinterpret_cast<NiPoint3*>(target->GetNormals());
    unsigned int uiCountVal = target->GetVertexCount();
    if (!targetVertices5 || !targetNormals2 || !uiCountVal)
        return false;
    NiPoint3* sourcePositions = CreateElementArray(source);
    if (!sourcePositions)
        return false;
    NiPoint3* targetVertices = CreateElementArray(target);
    if (!targetVertices)
    {
        delete sourcePositions;
        return false;
    }
    target->NiAVObject_GetWorldRotate().FUN_004b4880(aTransform);
    rotation4 = target->NiAVObject_GetWorldRotate().m_Rotate.Inverse() * source->NiAVObject_GetWorldRotate().m_Rotate;
    unsigned int best4;
    float bestDist3;
    float bestDistance10;
    float minimumVal = 3.402823466e+38F;
    for (unsigned int outer = 0; outer < uiCountVal; outer++)
    {
        best4 = uiCountX;
        bestDist3 = threshold >= 0.0 ? threshold : 3.402823466e+38F;
        for (unsigned int inner = 0; inner < uiCountX; inner++)
        {
            bestDistance10 = (targetVertices[outer] - sourcePositions[inner]).Length();
            if (bestDistance10 < bestDist3)
            {
                best4 = inner;
                bestDist3 = bestDistance10;
            }
            if (bestDistance10 < minimumVal)
                minimumVal = bestDistance10;
        }
        if (best4 < uiCountX)
        {
            Entry entry20;
            entry20.first = outer;
            entry20.second = uiCountVal;
            entry20.bestDistance10 = bestDist3;
            Entry existing;
            if (map30.NiTMapBase_DFALL_NiTMapItem_unsigned_int_VertexDist_unsigned_int_VertexDist_GetAt(best4, existing))
            {
                if (FloatEQ(entry20.bestDistance10, existing.bestDistance10, 0.001F))
                {
                    entry20.second = existing.first;
                    map30.SetOrInsert(best4, entry20);
                }
                else if (entry20.bestDistance10 < existing.bestDistance10)
                    map30.SetOrInsert(best4, entry20);
            }
            else
                map30.SetOrInsert(best4, entry20);
        }
    }
    {
        void* position = map30.FUN_004b9ba0();
        unsigned int iCount = 0;
        unsigned int aHKey;
        Entry existing;
        while (position)
        {
            iCount++;
            map30.GetNextEntry(position, aHKey, existing);
            reinterpret_cast<NiPoint3&>(targetNormals2[existing.first]) = rotation4.operator*(reinterpret_cast<const NiPoint3&>(sourceNormals2[aHKey]));
            targetNormals2[existing.first].Unitize_004a0c10();
            if (existing.second < uiCountVal)
            {
                targetNormals2[existing.second] = targetNormals2[existing.first];
                iCount++;
            }
            if (adjust)
            {
                if (DAT_011c6320 != source)
                    sourceVertices7[aHKey] += FUN_004a3760(10.0F, sourceNormals2[aHKey]);
                targetVertices5[existing.first] += FUN_004a3760(10.0F, targetNormals2[existing.first]);
                if (existing.second < uiCountVal)
                    targetVertices5[existing.second] = targetVertices5[existing.first];
            }
            bChangedB = true;
        }
    }
    if (bChangedB)
    {
        if (adjust)
            source->NiGeometry_GetModelData()->SetDirtyFlags(3);
        target->NiGeometry_GetModelData()->SetDirtyFlags(3);
    }
    if (sourcePositions)
        delete sourcePositions;
    if (targetVertices)
        delete targetVertices;
    DAT_011c6320 = source;
    return bChangedB;
}

struct FUN_004b4ee0_sub
{
    void* __thiscall FUN_006815c0();
    void __thiscall FUN_00436aa0();
};

struct FUN_004b4ee0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    FUN_004b4ee0_sub unk10;
    void hkpMotion_getPosition();
};

// @fnv 0x004b4ee0
// src: XBOX_PDB 0x004b4ee0
void FUN_004b4ee0_cls::hkpMotion_getPosition()
{
    ((FUN_004b4ee0_sub*)unk10.FUN_006815c0())->FUN_00436aa0();
}

bhkCollisionObject* __cdecl FUN_0043b610(void* obj);

// Recursively picks, among an object's list children and its ref target, the one with the greatest FUN_004b5400 value; returns 0 for a null object.
// @fnv 0x004b52f0
// src: COMMUNITY 0x004b52f0
void* __cdecl bhkRigidBody_FindHeaviestRigidBody(void* object)
{
    void* bestX;
    NiNode* list6;
    bhkCollisionObject* ref;
    void* other;
    unsigned int count7;
    unsigned int i4;
    void* child2;
    if (object != 0)
    {
        bestX = 0;
        list6 = ((NiObject*)object)->IsSceneNode();
        if (list6 != 0)
        {
            count7 = list6->GetNumChildren();
            for (i4 = 0; i4 < count7; i4++)
            {
                child2 = bhkRigidBody_FindHeaviestRigidBody(list6->FUN_0043b4a0(i4));
                if (child2 != 0)
                {
                    if (bestX == 0 || bhkRigidBody_GetMass(bestX) < bhkRigidBody_GetMass(child2))
                        bestX = child2;
                }
            }
        }
        ref = FUN_0043b610(object);
        other = ref ? ref->bhkNiCollisionObject_GetWorldObject() : 0;
        if (bestX != 0 && (other == 0 || bhkRigidBody_GetMass(other) < bhkRigidBody_GetMass(bestX)))
        {
            return bestX;
        }
        else
        {
            return other;
        }
    }
    else
    {
        return 0;
    }
}

class NiCamera;

struct TimeGlobalS
{
    unsigned int GetFrameCount();
};

extern TimeGlobalS g_timeGlobal;

static NiCamera* s_pkLastCamera;
static unsigned int s_uiLastFrame;

// @fnv 0x004b5ff0
bool __cdecl IsBoundVisible(NiBound* pkBound, NiCamera* pkCamera)
{
    if (!pkCamera)
        return false;

    static NiFrustumPlanes g_kFrustumPlanes;

    if (s_pkLastCamera != pkCamera || s_uiLastFrame != g_timeGlobal.GetFrameCount())
    {
        g_kFrustumPlanes.Set(pkCamera);
        s_uiLastFrame = g_timeGlobal.GetFrameCount();
        s_pkLastCamera = pkCamera;
    }

    for (unsigned int i = 0; i < 6; i++)
    {
        NiPlane m_kFogPlane = *static_cast<NiPlane*>(g_kFrustumPlanes.GetPlane(i));
        if (pkBound->WhichSide(static_cast<void*>(&m_kFogPlane)) == 2)
            return false;
    }
    return true;
}

class FUN_00b668b0 : public NiMemObject
{
  public:
    FUN_00b668b0();
    // This unit uses the sized allocation cleanup entry.
    static void operator delete(void*, unsigned int);
    unsigned int vtable;
    unsigned int referenceCount;
    unsigned int flags;
    NiColorA color0;
    NiColorA color1;
    NiColorA color2;
    NiColorA color3;
    NiColorA color4;
    unsigned int mode0, mode1, mode2, mode3, mode4, mode5;
};
struct Property6360
{
    void AssignRefObj(FUN_00b668b0*);
};
Property6360* NiObject_DynamicCast(const NiRTTI*, NiProperty*);
extern const NiRTTI DAT_011fa010;
// @fnv 0x004b6360
// src: XBOX_PDB 0x004b6360
void TintScenegraph(NiAVObject* object, const NiPoint3* color, FUN_00b668b0* property)
{
    NiPointer<FUN_00b668b0> shared(property);
    if (!property)
    {
        shared = new FUN_00b668b0;
        property = shared;
        ((FUN_00b668b0*)shared)->color2 = NiColorA(color->x, color->y, color->z, 0.5f);
        ((FUN_00b668b0*)shared)->color3 = NiColorA(color->x, color->y, color->z, 0.5f);
        ((FUN_00b668b0*)shared)->color0 = NiColorA(color->x, color->y, color->z, 0.5f);
        ((FUN_00b668b0*)shared)->color1 = NiColorA(color->x, color->y, color->z, 0.5f);
        ((FUN_00b668b0*)shared)->mode0 = 9;
        ((FUN_00b668b0*)shared)->mode1 = 10;
        ((FUN_00b668b0*)shared)->mode2 = 1;
        ((FUN_00b668b0*)shared)->mode3 = 4;
    }
    Property6360* material = NiObject_DynamicCast(&DAT_011fa010, object->GetProperty(3));
    if (material)
        material->AssignRefObj(shared);
    NiNode* node = object->IsSceneNode();
    if (node)
    {
        for (unsigned int i = 0; i < node->GetNumChildren(); ++i)
        {
            if (node->GetAt(i))
                TintScenegraph(node->GetAt(i), color, property);
        }
    }
}

class FUN_004b50c0
{
  public:
    FUN_004b50c0();
    virtual ~FUN_004b50c0();
    void bhkMouseSpringAction_Init(unsigned int value);
};

class FUN_004b5040 : public FUN_004b50c0
{
  public:
    FUN_004b5040(unsigned int value);
    virtual ~FUN_004b5040();
};

extern int DAT_01268124;

// Calls FUN_00c87260 with value and increments the global counter DAT_01268124.
// @fnv 0x004b5040
FUN_004b5040::FUN_004b5040(unsigned int value)
{
    bhkMouseSpringAction_Init(value);
    ++DAT_01268124;
}
