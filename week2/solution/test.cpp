#include <iostream>
#include <string>
#include <math.h>
#include <stdlib.h>

using namespace std;

string NOTES[] = {"C", "C#", "D", "D#", "E", "F",
                        "F#", "G", "G#", "A", "A#", "B"
                       };

int main()
{

    double frequency=0;
    double note = 0;
    string code = "C4";
    string octave = "";
    string group = "";
    int groupnum =0;
    int position = 0;

    if(code.size()==3){
        octave = code.substr(0,2);
        group = code.substr(2,1);

    }else if(code.size()==2){
        octave = code.substr(0,1);
        group = code.substr(1,1);
    }

    while(position<12){
        if(NOTES[position]==octave){
            break;
        }
        position++;
    }

    groupnum= atoi(group.c_str());
    note = (groupnum-4)*12+(position-9);  // multiplicador*12+(offset-9)



    frequency = 440*pow(2, note/12);   // 440 * 2^n/12

    cout << frequency << endl;

	return 0;
}