/*
 * Arranger.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: chan
 */

#include "Arranger.h"


Arranger::Arranger() {
	// TODO Auto-generated constructor stub
	Note2ChordMap.insert(std::pair<pitch,KeyChords> (dou,dou_chord));
	Note2ChordMap.insert(std::pair<pitch,KeyChords> (re,re_chord));
	Note2ChordMap.insert(std::pair<pitch,KeyChords> (mi,mi_chord));
	Note2ChordMap.insert(std::pair<pitch,KeyChords> (fa,fa_chord));
	Note2ChordMap.insert(std::pair<pitch,KeyChords> (so,so_chord));
	Note2ChordMap.insert(std::pair<pitch,KeyChords> (la,la_chord));
	Note2ChordMap.insert(std::pair<pitch,KeyChords> (si,si_chord));

	Chord2NoteMap.insert(std::pair<chord,ChordsCombo>(C,C_pitchs));
	Chord2NoteMap.insert(std::pair<chord,ChordsCombo>(Dm,Dm_pitchs));
	Chord2NoteMap.insert(std::pair<chord,ChordsCombo>(Em,Em_pitchs));
	Chord2NoteMap.insert(std::pair<chord,ChordsCombo>(F,F_pitchs));
	Chord2NoteMap.insert(std::pair<chord,ChordsCombo>(G,G_pitchs));
	Chord2NoteMap.insert(std::pair<chord,ChordsCombo>(Am,Am_pitchs));
	Chord2NoteMap.insert(std::pair<chord,ChordsCombo>(Bdim,Bdim_pitchs));
}

Arranger::~Arranger() {
	// TODO Auto-generated destructor stub
}


/*

pitch Arranger::ArrangeChordForNote(pitch src_pitch){

	KeyChords chord_array;
	ChordsCombo pitch_array;
	pitch dst_pitch;
	chord_array = Note2ChordMap.find(src_pitch);
	pitch_array 	= chord_array[rand()%(chord_array.size())];
	dst_pitch	= pitch_array[rand()%(pitch_array.size())];

	return dst_pitch;
}
*/
void Arranger::FindChord(Notes src_note, chord& candi_chord){
	KeyChords chord_array;

	chord_array = Note2ChordMap.find(src_note.GetPitch())->second;
	candi_chord = chord_array[rand() % (chord_array.size())];
}


void Arranger::ArrangeNote(chord src_chord, Notes& candi_note){
	ChordsCombo pitch_array;


	pitch_array = Chord2NoteMap.find(src_chord)->second;
	candi_note = pitch_array[rand()%(pitch_array.size())];
}



void Arranger::ArrangeChordForMelody(std::stack<Notes> src_melody, std::queue<Notes> &dst_melody){
	chord candi_chord;
	Notes dst_note;
	std::queue<chord> dst_chord_queue;
	while(!src_melody.empty()){
		if(!dst_chord_queue.empty() && Belong2Chord(src_melody.top(),Chord2NoteMap.find(dst_chord_queue.back())->second)){
			candi_chord = dst_chord_queue.back();
		}else{
			FindChord(src_melody.top(),candi_chord);
		}

		dst_chord_queue.push(candi_chord);

		ArrangeNote(candi_chord,dst_note);
		dst_melody.push(dst_note);
		src_melody.pop();
	}


	char *ChordType[] =
	{
	    "C",
	    "Dm",
	    "Em",
	    "F",
	    "G",
	    "Am",
	    "Bdim"
	};
	std::cout<<"Chosen Chord:";
	while(!dst_chord_queue.empty()){
		std::cout<<ChordType[dst_chord_queue.front()]<<' ';
		dst_chord_queue.pop();
	}
	std::cout<<"\n";

}

bool Arranger::Belong2Chord(Notes candi_note, ChordsCombo dst_chord){
	for(unsigned int i=0; i <dst_chord.size();i++){
		if(candi_note.GetPitch() == dst_chord[i])
			return true;
	}
	return false;
}
