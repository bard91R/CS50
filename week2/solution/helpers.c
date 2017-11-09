// Helper functions for music

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include "helpers.h"
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
    //printf("fraction %c\n",fraction[0]);
	int a = fraction[0];
	int b = fraction[2];

	a = (8/b)*a;	//determine how many octaves there are in the fraction and returns the number of octaves
	//printf("duration %i",a);

	return a;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO

    //considering A4 as the fundamental frequency as described on the documentation of the problem set, the frequencies of the other notes
    //will be calculated based on their relative position to A4, where n = (section number-4)*12 + (octave difference - 9), this is
    //obtained by considering that A4 needs to be = 0 in the previous expression

	//added the list of the possible notes in here to calculate the frequencies based on their position
	string NOTES[] = {"C", "C#", "D", "D#", "E", "F",
                        "F#", "G", "G#", "A", "A#", "B"
                       };

    double frequency=0;
    string octave = note;	//initializing this way, when I tried initializing with any constant string "xxx" it would seg fault in str copy, since it seems like this strings are saved in memory reserved as read only.
    int group = 0;
    int position = 0;

    if(strlen(note)==3){
        group = note[2]-48;
        sprintf(octave, "%c%c", note[0], note[1]);		//this is done to handle both  possible formats for the octave notation

    }else if(strlen(note)==2){
    	group = note[1]-48;
    	sprintf(octave, "%c", note[0]);

    }

    while(position<12){
        //if(NOTES[position]==octave){
        if(strcmp(NOTES[position],octave)==0){		//compares the octave with the elements of NOTES until it finds a match
            break;

        }
        position++;

    }

    frequency = (group-4)*12+(position-9);  // (multiplier-4)*12+(offset-9)
    frequency = 440*pow(2, frequency/12);   // 440 * 2^n/12

    					//receives something with the following format A4, or A#4
    //note = "change";
	return frequency;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
	bool rest = false;
	if(strncmp(s,"\n",-1)==0){ //checks if the string is empty
							//this comparison may have to be with \n instead of ""

		rest = true;
	}

	return rest;
}
