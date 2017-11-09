// Helper functions for music

#include <cs50.h>

#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    // TODO
	int a = string[0];
	int b = string[2];
	
	a = (8/b)*a;	//determine how many octaves there are in the fraction and returns the number of octaves
	
	return a;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    // TODO
	return 0;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
	bool rest = false;
	if(s.get_string()==""){ //checks if the string is empty
		rest true;
	}

	return rest;
}
