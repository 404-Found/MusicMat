/*
 * Notes.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: chan
 */

#include "Notes.h"


Notes::Notes():v_pitch(empt),v_meter(meter1){

};


Notes::Notes(int i=0):v_pitch(static_cast<pitch>(i)),v_meter(meter1){

};

Notes::Notes(pitch v_y=empt) : v_pitch(v_y),v_meter(meter1){
	// TODO Auto-generated constructor stub

}

Notes::Notes(pitch v_y,meter_t v_b):v_pitch(v_y),v_meter(v_b) {
	// TODO Auto-generated constructor stub

}



Notes::~Notes() {
	// TODO Auto-generated destructor stub
}

pitch Notes::GetPitch(){
	return v_pitch;
}


meter_t Notes::GetMeter(){
	return v_meter;
}

bool Notes::SetMeter(meter_t x_meter){
	v_meter = x_meter;
	return true;
}

bool Notes::SetPitch(pitch x_pitch){
	v_pitch = x_pitch;
	return true;
}
