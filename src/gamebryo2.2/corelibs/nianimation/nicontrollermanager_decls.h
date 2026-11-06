extern NiFixedString* DAT_011c61e0;

// The shared playing-sequence set exposes its layout but not these out-of-line accessors.
class NiControllerManagerPlayingSequences
{
public:
    unsigned int GetSize();
    NiControllerSequence*& GetAt(unsigned int index);
};
