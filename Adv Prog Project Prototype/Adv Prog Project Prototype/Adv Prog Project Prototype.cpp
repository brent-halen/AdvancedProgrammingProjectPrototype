// Adv Prog Project Prototype.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <ctime>
#include <cmath>
#include <windows.h>

using namespace std;


struct round
{
	int Roundnum; // a kind if 'index number'.
	string description; // A description of the round, if needed.
	long int R1length; // Length of the active round (in microseconds)
	long int R1met; // Metronome count in BPM.
	long int Rest1length; // Length of the rest period (in microseconds)
	long int R1count; // # of times this round will occur in a sequence.
	long int R1metcount; // # of times the metronome beat will 'tick' during the active round (determined by a calculation using the R1length & R1met values)
	long int R1rem; // Remaning # of microseconds left in a round after all the metronome ticks have occurred (determined using modulo operation)
	long int R1metint; // # of microseconds between metronome "ticks" (determined by subtracting R1rem from R1length and dividing R1length by R1metcount).

};



int main()
{
	round defaultround; // Setting a default round for testing purposes.
	defaultround.Roundnum = 0; // Giving the default round the index 0. 
	defaultround.description = "Default"; // Description set to 'default'.
	defaultround.R1count = 3; // # of times the default round will occur. Set to 3.
	defaultround.R1length = 6000000; // Setting the active round to be one minute long. (6,000,000 microseconds)
	defaultround.Rest1length = 6000000; // Setting the rest round to be one minute long. (6,000,000 microseconds)
	defaultround.R1met = 30; // Setting the BPM for round 1 to 30.
	
	defaultround.R1metcount = (defaultround.R1length / 6000000) * defaultround.R1met;
	defaultround.R1rem = (defaultround.R1length % defaultround.R1metcount);
	defaultround.R1metint = ((defaultround.R1length - defaultround.R1rem)/defaultround.R1metcount);
	char Again = 'y';
	string t1 = "Tick!\n";
	string r1 = "Rest!\n";
	long int R1index = 0;
	long int R1countindex = 0;

	do{
		cout << "This is a prototype to test the algorithms and general function of this round timer/metronome combination\n";
		cout << "Let's call this one v0.0." << endl;
		cout << "Press 'Enter' when you are ready to begin. The default round timer has been set to operate at 30 BPM during active\nrounds for 3 cycles of 1/1 minute active/rest rounds." << endl;
		cout << "If the system performs correctly, you should see a 'Tick!' for each strike of the metronome (in this case, every\n2 seconds) and a 'Rest!' to indicate when the rest period begins."<< endl;
		system("pause");
	
		while(R1index < defaultround.R1count)
		{
			while(R1countindex < defaultround.R1metcount)
			{
				cout << t1 << endl;
				Sleep(defaultround.R1metint/100);
				R1countindex++;
			}
			cout << r1 << endl;
			Sleep(defaultround.Rest1length/100);
			R1countindex = 0;

		}
	cout << "\n\nWould you like to repeat the program? (Y/N) \n\n>>>   ";
		cin >> Again;
		if (tolower(Again) == 'y'){
			//clear the screen if they repeat the program.
			system("cls");
			cin.clear();
		}
	}while(toupper(Again == 'Y'));
	return 0;
}

