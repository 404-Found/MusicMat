/*
 * Arranger.h
 *
 *  Created on: Sep 15, 2014
 *      Author: chan
 */

#ifndef ARRANGER_H_
#define ARRANGER_H_

#include <iostream>
#include <map>
#include <array>
#include <stack>
#include <queue>
#include "MusicElements.h"
#include "Notes.h"

const ChordsCombo C_pitchs		={dou,mi,so};
const ChordsCombo Dm_pitchs		={re,fa,la};
const ChordsCombo Em_pitchs		={mi,so,si};
const ChordsCombo F_pitchs 		={fa,la,dou};
const ChordsCombo G_pitchs		={so,si,re};
const ChordsCombo Am_pitchs		={la,dou,mi};
const ChordsCombo Bdim_pitchs	={si,re,fa};


const KeyChords dou_chord 	={C, F, Am};
const KeyChords re_chord 	={Dm, G, Bdim};
const KeyChords mi_chord 	={C, Em, Am};
const KeyChords fa_chord 	={Dm, F, Bdim};
const KeyChords so_chord 	={C, Em, G};
const KeyChords la_chord 	={Dm, F, Am};
const KeyChords si_chord 	={Em, G, Bdim};



class Arranger {
	std::map<pitch,KeyChords> Note2ChordMap;
	std::map<chord,ChordsCombo> Chord2NoteMap;
public:
	Arranger();
	virtual ~Arranger();

	void FindChord(Notes src_note, chord& candi_chord);
	void ArrangeNote(chord src_chord, Notes& candi_note);
	void ArrangeChordForMelody(std::stack<Notes> src_melody, std::queue<Notes> &dst_melody);

	bool Belong2Chord(Notes candi_note, ChordsCombo dst_chord);
};

#endif /* ARRANGER_H_ */
