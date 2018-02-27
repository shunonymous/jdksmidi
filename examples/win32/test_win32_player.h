/*

  AdvancedSequencer class example for libJDKSmidi C++ MIDI Library
  (Win32 GUI App using MS Windows API)

  Copyright (C) 2013 N.Cassetta
  ncassetta@tiscali.it

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public License
  as published by the Free Software Foundation; either version 2
  of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program;
  if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/
//
// Copyright (C) 2013 N. Cassetta
// ncassetta@tiscali.it
//

#ifndef TEST_WIN32_H_INCLUDED
#define TEST_WIN32_H_INCLUDED

#include <windows.h>

#include "jdksmidi/advancedsequencer.h"
#include "jdksmidi/smpte.h"

using namespace jdksmidi;

const char GMpatches[][128]
    = {"0-Acoustic Grand Piano",     "1-Bright Acoustic Piano",    "2-Electric Grand Piano",    "3-Honky-tonk Piano",
       "4-Rhodes Piano",             "5-Chorused Piano",           "6-Harpsichord",             "7-Clavinet",
       "8-Celesta",                  "9-Glockenspiel",             "10-Music Box",              "11-Vibraphone",
       "12-Marimba",                 "13-Xylophone",               "14-Tubular Bells",          "15-Dulcimer",
       "16-Hammond Organ",           "17-Percussive Organ",        "18-Rock Organ",             "19-Church Organ",
       "20-Reed Organ",              "21-Accordion",               "22-Harmonica",              "23-Tango Accordion",
       "24-Acoustic Guitar (nylon)", "25-Acoustic Guitar (steel)", "26-Electric Guitar (jazz)", "27-Electric Guitar (clean)",
       "28-Electric Guitar (muted)", "29-Overdriven Guitar",       "30-Distortion Guitar",      "31-Guitar Harmonics",
       "32-Acoustic Bass",           "33-Electric Bass (finger)",  "34-Electric Bass (pick)",   "35-Fretless Bass",
       "36-Slap Bass 1",             "37-Slap Bass 2",             "38-Synth Bass 1",           "39-Synth Bass 2",
       "40-Violin",                  "41-Viola",                   "42-Cello",                  "43-Contrabass",
       "44-Tremolo Strings",         "45-Pizzicato Strings",       "46-Orchestral Harp",        "47-Timpani",
       "48-String Ensemble 1",       "49-String Ensemble 2",       "50-SynthStrings 1",         "51-SynthStrings 2",
       "52-Choir Aahs",              "53-Voice Oohs",              "54-Synth Voice",            "55-Orchestra Hit",
       "56-Trumpet",                 "57-Trombone",                "58-Tuba",                   "59-Muted Trumpet",
       "60-French Horn",             "61-Brass Section",           "62-Synth Brass 1",          "63-Synth Brass 2",
       "64-Soprano Sax",             "65-Alto Sax",                "66-Tenor Sax",              "67-Baritone Sax",
       "68-Oboe",                    "69-English Horn",            "70-Bassoon",                "71-Clarinet",
       "72-Piccolo",                 "73-Flute",                   "74-Recorder",               "75-Pan Flute",
       "76-Bottle Blow",             "77-Shakuhachi",              "78-Whistle",                "79-Ocarina",
       "80-Lead 1 (square)",         "81-Lead 2 (sawtooth)",       "82-Lead 3 (calliope lead)", "83-Lead 4 (chiff lead)",
       "84-Lead 5 (charang)",        "85-Lead 6 (voice)",          "86-Lead 7 (fifths)",        "87-Lead 8 (bass + lead)",
       "88-Pad 1 (new age)",         "89-Pad 2 (warm)",            "90-Pad 3 (polysynth)",      "91-Pad 4 (choir)",
       "92-Pad 5 (bowed)",           "93-Pad 6 (metallic)",        "94-Pad 7 (halo)",           "95-Pad 8 (sweep)",
       "96-FX 1 (rain)",             "97-FX 2 (soundtrack)",       "98-FX 3 (crystal)",         "99-FX 4 (atmosphere)",
       "100-FX 5 (brightness)",      "101-FX 6 (goblins)",         "102-FX 7 (echoes)",         "103-FX 8 (sci-fi)",
       "104-Sitar",                  "105-Banjo",                  "106-Shamisen",              "107-Koto",
       "108-Kalimba",                "109-Bagpipe",                "110-Fiddle",                "111-Shanai",
       "112-Tinkle Bell",            "113-Agogo",                  "114-Steel Drums",           "115-Woodblock",
       "116-Taiko Drum",             "117-Melodic Tom",            "118-Synth Drum",            "119-Reverse Cymbal",
       "120-Guitar Fret Noise",      "121-Breath Noise",           "122-Seashore",              "123-Bird Tweet",
       "124-Telephone Ring",         "125-Helicopter",             "126-Applause",              "127-Gunshot"
      };

const char GMDrumKits[][128]
    = {"0-Standard Kit",        "1-",                 "2-",                "3-",                "4-",
       "5-",                    "6-",                 "7-",                "8-",                "9-Room Kit",
       "10-",                   "11-",                "12-",               "13-",               "14-",
       "15-",                   "16-",                "17-Power Kit",      "18-",               "19-",
       "20-",                   "21-",                "22-",               "23-",               "24-",
       "25-Electric Kit",       "26-TR 808 Kit",      "27-",               "28-",               "29-",
       "30-",                   "31-",                "32-",               "33-Jazz Kit",       "34-",
       "35-",                   "36-",                "37-",               "38-",               "39-",
       "40-",                   "41-Brush Kit",       "42-",               "43-",               "44-",
       "45-",                   "46-",                "47-",               "48-",               "49-Orchestra Kit",
       "50-",                   "51-",                "52-",               "53-",               "54-",
       "55-",                   "56-",                "57-",               "58-",               "59-",
       "60-",                   "61-",                "62-",               "63-",               "64-",
       "65-",                   "66-",                "67-",               "68-",               "69-",
       "70-",                   "71-",                "72-",               "73-",               "74-",
       "75-",                   "76-",                "77-",               "78-",               "79-",
       "80-",                   "81-",                "82-",               "83-",               "84-",
       "85-",                   "86-",                "87-",               "88-",               "89-",
       "90-",                   "91-",                "92-",               "93-",               "94-",
       "95-",                   "96-",                "97-",               "98-",               "99-",
       "100-FX 5 (brightness)", "101-FX 6 (goblins)", "102-FX 7 (echoes)", "103-FX 8 (sci-fi)", "104-Sitar",
       "105-Banjo",             "106-Shamisen",       "107-Koto",          "108-Kalimba",       "109-Bagpipe",
       "110-Fiddle",            "111-Shanai",         "112-Tinkle Bell",   "113-Agogo",         "114-Steel Drums",
       "115-Woodblock",         "116-Taiko Drum",     "117-Melodic Tom",   "118-Synth Drum",    "119-Reverse Cymbal",
       "120-Guitar Fret Noise", "121-Breath Noise",   "122-Seashore",      "123-Bird Tweet",    "124-Telephone Ring",
       "125-Helicopter",        "126-Applause",       "127-Gunshot"
      };

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure( HWND, UINT, WPARAM, LPARAM );

/* Declare other functions called by WinMain and WindowProcedure */
VOID ProcessNotifierMessage( MIDISequencerGUIEvent msg );
VOID LoadFile();
VOID SetControls();
const char *GetSmpteString();

#endif // TEST_WIN32_H_INCLUDED
