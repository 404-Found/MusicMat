#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stack>

#include "MusicElements.h"
#include "Notes.h"
#include "Arranger.h"

using namespace std;


int main(int arg, char* argv[]){

	long long melody;
	int x_pitch;
	stack<Notes> in_melody;
	queue<Notes> chord_melody;
	Arranger mybot;
	srand (time(NULL));

	cout<<"Please input a melody to start a test(eg:XXXXXXXX):"<<endl;
	cin>>melody;

	for(;melody;melody/=10){
		x_pitch=melody%10;
		in_melody.push(x_pitch);
	}

	mybot.ArrangeChordForMelody(in_melody,chord_melody);

	cout<<"Src Melody:";
	while(!in_melody.empty()){
		cout<<in_melody.top().GetPitch()<<' ';
		in_melody.pop();
	}
	cout<<endl;

	cout<<"Dst Melody:";
	while(!chord_melody.empty()){
		cout<<chord_melody.front().GetPitch()<<' ';
		chord_melody.pop();
	}

	cout<<endl;

	return 0;

}
