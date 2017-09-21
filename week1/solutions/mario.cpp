#include <iostream>

using namespace std;

int main (){


	int size = 100000;
	cout << "Enter the side of the pyramids ";
	cin >> size;


	while(size>23){

	cout << "The size entered is too big please enter a number lower than 23 ";
	cin >> size;
	}

	int elements = size;	//variable used to keep a reference of the size

	while(size>0){
	
		for(int i=1; i<=elements*2+2; i++){
			if(i<size || i>elements*2+3-size || i==elements+1 || i==elements+2){ //+2 because of the 2 spaces in the middle, and +1 because there's an offset of one position
				cout << " ";
			}
			else{
				cout << "#";
			}
		}
	
		cout << "\n";

		size--;	
	}

}
