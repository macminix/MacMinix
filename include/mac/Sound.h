#ifndef _MAC_SOUND_H
#define _MAC_SOUND_H

/*
 * Macintosh include files
 * Based on Inside Macintosh Volumes 1-4.
 */

#ifndef _MAC_TYPES_H
#include <mac/Types.h>
#endif

/* mode values */
#define swMode	-1
#define ftMode	1
#define ffMode	0

typedef struct FFSynthRec FFSynthRec;
typedef struct FFSynthRec *FFSynthPtr;
typedef char   FreeWave[30001];
typedef struct SWSynthRec SWSynthRec;
typedef struct SWSynthRec *SWSynthPtr;
typedef struct Tone Tone;
typedef struct FTSynthRec FTSynthRec;
typedef struct FTSynthRec *FTSynthPtr;
typedef struct FTSoundRec FTSoundRec;
typedef struct FTSoundRec *FTSndRecPtr;
typedef char Wave[256];
typedef Wave *WavePtr;

struct FFSynthRec {
   Short mode;
   Fixed count;
   FreeWave waveBytes;
};

struct Tone {
   Short count;
   Short amplitude;
   Short duration;
};

typedef struct Tone Tones[5001];

struct SWSynthRec {
   Short mode;
   Tones triplets;
};

struct FTSoundRec {
   Short duration;
   Fixed sound1Rate;
   Long  sound1Phase;
   Fixed sound2Rate;
   Long  sound2Phase;
   Fixed sound3Rate;
   Long  sound3Phase;
   Fixed sound4Rate;
   Long  sound4Phase;
   WavePtr sound1Wave;
   WavePtr sound2Wave;
   WavePtr sound3Wave;
   WavePtr sound4Wave;
};

struct FTSynthRec {
   Short mode;
   FTSndRecPtr sndRec;
};

/* Declare ANSI or K&R prototypes */
#ifndef _ANSI_H
#include <ansi.h>
#endif

_PROTOTYPE( void GetSoundVol, (Short *level) );
_PROTOTYPE( void SetSoundVol, (Short level) );
_PROTOTYPE( Boolean SoundDone, (void) );
_PROTOTYPE( void StartSound, (Ptr synthRec, Long numBytes, ProcPtr completionRtn) );
_PROTOTYPE( void StopSound, (void) );
#endif
