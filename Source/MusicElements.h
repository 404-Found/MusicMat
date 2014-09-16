/*
 * MusicElements.h
 *
 *  Created on: Sep 16, 2014
 *      Author: chan
 */

#ifndef MUSICELEMENTS_H_
#define MUSICELEMENTS_H_

#include<array>
enum meter_t{meter1=1, meter2=1/2, meter4=1/4, meter8=1/8, meter16=1/16};
enum pitch{dou=1,re=2,mi=3,fa=4,so=5,la=6,si=7,empt=0};
enum chord{C, Dm, Em, F, G, Am, Bdim};

typedef std::array <pitch,3> ChordsCombo;
typedef std::array <chord,3> KeyChords;


#endif /* MUSICELEMENTS_H_ */
