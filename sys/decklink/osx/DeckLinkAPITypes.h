/* -LICENSE-START-
** Copyright (c) 2021 Blackmagic Design
**
** Permission is hereby granted, free of charge, to any person or organization
** obtaining a copy of the software and accompanying documentation covered by
** this license (the "Software") to use, reproduce, display, distribute,
** execute, and transmit the Software, and to prepare derivative works of the
** Software, and to permit third-parties to whom the Software is furnished to
** do so, all subject to the following:
**
** The copyright notices in the Software and this entire statement, including
** the above license grant, this restriction and the following disclaimer,
** must be included in all copies of the Software, in whole or in part, and
** all derivative works of the Software, unless such copies or derivative
** works are solely in the form of machine-executable object code generated by
** a source language processor.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
** SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
** FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
** ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
** -LICENSE-END-
*/

#ifndef BMD_DECKLINKAPITYPES_H
#define BMD_DECKLINKAPITYPES_H


#ifndef BMD_CONST
    #if defined(_MSC_VER)
        #define BMD_CONST __declspec(selectany) static const
    #else
        #define BMD_CONST static const
    #endif
#endif

#ifndef BMD_PUBLIC
	#define BMD_PUBLIC
#endif

// Type Declarations

typedef int64_t BMDTimeValue;
typedef int64_t BMDTimeScale;
typedef uint32_t BMDTimecodeBCD;
typedef uint32_t BMDTimecodeUserBits;

// Interface ID Declarations

BMD_CONST REFIID IID_IDeckLinkTimecode                            = /* BC6CFBD3-8317-4325-AC1C-1216391E9340 */ { 0xBC,0x6C,0xFB,0xD3,0x83,0x17,0x43,0x25,0xAC,0x1C,0x12,0x16,0x39,0x1E,0x93,0x40 };

/* Enum BMDTimecodeFlags - Timecode flags */

typedef uint32_t BMDTimecodeFlags;
enum _BMDTimecodeFlags {
    bmdTimecodeFlagDefault                                       = 0,
    bmdTimecodeIsDropFrame                                       = 1 << 0,
    bmdTimecodeFieldMark                                         = 1 << 1,
    bmdTimecodeColorFrame                                        = 1 << 2,
    bmdTimecodeEmbedRecordingTrigger                             = 1 << 3,	// On SDI recording trigger utilises a user-bit.
    bmdTimecodeRecordingTriggered                                = 1 << 4
};

/* Enum BMDVideoConnection - Video connection types */

typedef uint32_t BMDVideoConnection;
enum _BMDVideoConnection {
    bmdVideoConnectionUnspecified                                = 0,
    bmdVideoConnectionSDI                                        = 1 << 0,
    bmdVideoConnectionHDMI                                       = 1 << 1,
    bmdVideoConnectionOpticalSDI                                 = 1 << 2,
    bmdVideoConnectionComponent                                  = 1 << 3,
    bmdVideoConnectionComposite                                  = 1 << 4,
    bmdVideoConnectionSVideo                                     = 1 << 5
};

/* Enum BMDAudioConnection - Audio connection types */

typedef uint32_t BMDAudioConnection;
enum _BMDAudioConnection {
    bmdAudioConnectionEmbedded                                   = 1 << 0,
    bmdAudioConnectionAESEBU                                     = 1 << 1,
    bmdAudioConnectionAnalog                                     = 1 << 2,
    bmdAudioConnectionAnalogXLR                                  = 1 << 3,
    bmdAudioConnectionAnalogRCA                                  = 1 << 4,
    bmdAudioConnectionMicrophone                                 = 1 << 5,
    bmdAudioConnectionHeadphones                                 = 1 << 6
};

/* Enum BMDDeckControlConnection - Deck control connections */

typedef uint32_t BMDDeckControlConnection;
enum _BMDDeckControlConnection {
    bmdDeckControlConnectionRS422Remote1                         = 1 << 0,
    bmdDeckControlConnectionRS422Remote2                         = 1 << 1
};

#if defined(__cplusplus)

// Forward Declarations

class IDeckLinkTimecode;

/* Interface IDeckLinkTimecode - Used for video frame timecode representation. */

class BMD_PUBLIC IDeckLinkTimecode : public IUnknown
{
public:
    virtual BMDTimecodeBCD GetBCD (void) = 0;
    virtual HRESULT GetComponents (/* out */ uint8_t* hours, /* out */ uint8_t* minutes, /* out */ uint8_t* seconds, /* out */ uint8_t* frames) = 0;
    virtual HRESULT GetString (/* out */ CFStringRef* timecode) = 0;
    virtual BMDTimecodeFlags GetFlags (void) = 0;
    virtual HRESULT GetTimecodeUserBits (/* out */ BMDTimecodeUserBits* userBits) = 0;

protected:
    virtual ~IDeckLinkTimecode () {} // call Release method to drop reference count
};

/* Functions */

extern "C" {


}



#endif /* defined(__cplusplus) */
#endif /* defined(BMD_DECKLINKAPITYPES_H) */
