void __fastcall Sleep(unsigned long milliseconds);

// @fnv 0x00868250
void __fastcall RecursiveSpinLock_Lock(RecursiveSpinLock* lock)
{
    Sleep(lock->m_uiOwningThreadID);
}
