#ifndef FNV_ORIGINAL_SETTING_EH_INITIALIZERS_H
#define FNV_ORIGINAL_SETTING_EH_INITIALIZERS_H

// Game-setting globals whose constructors are inlined (/Od /Ob1). Classes are named by original vtable, collection
// and init-function addresses; vtables, destructors, the collection and init function stay original (bound by address).
void SettingT_INIPrefSettingCollection_InitCollection();
class SetColl_011f35a0_004de4a0
{
  public:
    virtual void vfn0();
    virtual void Add(void* setting);
};
extern SetColl_011f35a0_004de4a0* g_coll_011f35a0;
inline SetColl_011f35a0_004de4a0* GetSetColl_011f35a0_004de4a0()
{
    int a;
    int b;
    int c;
    SettingT_INIPrefSettingCollection_InitCollection();
    return g_coll_011f35a0;
}
void FUN_0044f570();
class SetColl_011f96a0_0044f570
{
  public:
    virtual void vfn0();
    virtual void Add(void* setting);
};
extern SetColl_011f96a0_0044f570* g_coll_011f96a0;
inline SetColl_011f96a0_0044f570* GetSetColl_011f96a0_0044f570()
{
    int a;
    int b;
    int c;
    FUN_0044f570();
    return g_coll_011f96a0;
}
class SettingBase_01012120
{
  public:
    SettingBase_01012120(const char* name)
    {
        m_name = name;
    }
    SettingBase_01012120(const char* name, const char* value)
    {
        m_name = name;
        m_uiFilterValue.s = value;
    }
    SettingBase_01012120(const char* name, int value)
    {
        m_name = name;
        m_uiFilterValue.i = value;
    }
    SettingBase_01012120(const char* name, float value)
    {
        m_name = name;
        m_uiFilterValue.f = value;
    }
    SettingBase_01012120(const char* name, bool value)
    {
        m_name = name;
        m_uiFilterValue.b = value;
    }
    virtual ~SettingBase_01012120();
    union
    {
        const char* s;
        int i;
        float f;
        bool b;
    } m_uiFilterValue;
    const char* m_name;
};
class Setting_01017720_011f96a0 : public SettingBase_01012120
{
  public:
    Setting_01017720_011f96a0(const char* name) : SettingBase_01012120(name)
    {
        GetSetColl_011f96a0_0044f570()->Add(this);
    }
    Setting_01017720_011f96a0(const char* name, const char* value) : SettingBase_01012120(name, value)
    {
        GetSetColl_011f96a0_0044f570()->Add(this);
    }
    Setting_01017720_011f96a0(const char* name, int value) : SettingBase_01012120(name, value)
    {
        GetSetColl_011f96a0_0044f570()->Add(this);
    }
    Setting_01017720_011f96a0(const char* name, float value) : SettingBase_01012120(name, value)
    {
        GetSetColl_011f96a0_0044f570()->Add(this);
    }
    Setting_01017720_011f96a0(const char* name, bool value) : SettingBase_01012120(name, value)
    {
        GetSetColl_011f96a0_0044f570()->Add(this);
    }
    virtual ~Setting_01017720_011f96a0();
};
class Setting_01022738_011f35a0 : public SettingBase_01012120
{
  public:
    Setting_01022738_011f35a0(const char* name) : SettingBase_01012120(name)
    {
        GetSetColl_011f35a0_004de4a0()->Add(this);
    }
    Setting_01022738_011f35a0(const char* name, const char* value) : SettingBase_01012120(name, value)
    {
        GetSetColl_011f35a0_004de4a0()->Add(this);
    }
    Setting_01022738_011f35a0(const char* name, int value) : SettingBase_01012120(name, value)
    {
        GetSetColl_011f35a0_004de4a0()->Add(this);
    }
    Setting_01022738_011f35a0(const char* name, float value) : SettingBase_01012120(name, value)
    {
        GetSetColl_011f35a0_004de4a0()->Add(this);
    }
    Setting_01022738_011f35a0(const char* name, bool value) : SettingBase_01012120(name, value)
    {
        GetSetColl_011f35a0_004de4a0()->Add(this);
    }
    virtual ~Setting_01022738_011f35a0();
};
extern const char s_01094eb8[];
extern const char s_01094ed8[];
extern const char s_01095074[];
extern const char s_0109528c[];
extern const char s_010952b0[];
extern const char s_010952c4[];
extern const char s_010952e4[];
extern const char s_010952f8[];
extern const char s_01095320[];
extern const char s_01095334[];
extern const char s_01095364[];
extern const char s_01095378[];
extern const char s_010953a4[];
extern const char s_010953b8[];
extern const char s_010953e4[];
extern const char s_010953f8[];
extern const char s_01095420[];
extern const char s_01095434[];
extern const char s_0109545c[];
extern const char s_0109589c[];
extern const char s_010958b4[];
extern const char s_010958d4[];
extern const char s_010958f0[];
extern const char s_01095910[];
extern const char s_01095930[];
extern const char s_01095954[];
extern const char s_01095978[];
extern const char s_010959a4[];
extern const char s_010959c8[];
extern const char s_010a325c[];
extern const char s_010a3270[];
extern const char s_010a328c[];
extern const char s_010a32a8[];
extern const char s_010a32b8[];
extern const char s_010a32c8[];
extern const char s_010a32d8[];
extern const char s_010a32ec[];
extern const char s_010a3758[];
extern const char s_010a3774[];
extern const char s_010a3790[];
extern const char s_010a37ac[];
extern const char s_010a37c8[];
extern const char s_010a37e4[];
extern const char s_010a3800[];
extern const char s_010a3820[];
extern const char s_010a3838[];
extern const char s_010a3850[];
extern const char s_010a386c[];
extern const char s_010a388c[];
extern const char s_010a38ac[];
extern const char s_010a38d0[];
extern const char s_010a38f4[];
extern const char s_010a390c[];
extern const char s_010a3924[];
extern const char s_010a3944[];
extern const char s_010a41a0[];
extern const char s_010a41c0[];
extern const char s_010a41d0[];
extern const char s_010a41f4[];
extern const char s_010a4210[];
extern const char s_010a4228[];
extern const char s_010c1774[];
extern const char s_010c179c[];
extern const char s_010c17dc[];
extern const char s_010c180c[];
extern const char s_010c2820[];
extern const char s_010c2844[];
extern const char s_010c2864[];
extern const char s_010c2884[];
extern const char s_010c289c[];
extern const char s_010c28b0[];
extern const char s_010c28cc[];
extern const char s_010c28f0[];
extern const char s_010c291c[];
extern const char s_010c2938[];
extern const char s_010c2958[];
extern const char s_010c2978[];
extern const char s_010f1dbc[];
extern const char s_010f1ddc[];
extern const char s_010f1df8[];
#endif
