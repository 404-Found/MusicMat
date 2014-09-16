/*
 * Notes.h
 *
 *  Created on: Sep 15, 2014
 *      Author: chan
 */

#ifndef BEATS_H_
#define BEATS_H_

#include "MusicElements.h"


class Notes {
	pitch v_pitch;
	meter_t v_meter;
public:
	Notes();
	Notes(int i);
	Notes(pitch v_y);
	Notes(pitch v_y,meter_t v_b);
	virtual ~Notes();

	pitch GetPitch();
	meter_t GetMeter();

	bool SetPitch(pitch x_pitch);
	bool SetMeter(meter_t x_meter);
};

#endif /* BEATS_H_ */
