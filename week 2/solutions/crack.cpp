#include <iostream>
#include <string>

using namespace std;

//in progress


int main(){

	string hashed_pswd;
	/*
	int index = 0;
	int key_position = 0;	
	int key_value;
	string text;
	*/

	cout << "Enter Keyword:";
	//getchar();
	getline(cin, hashed_pswd);

	if(hashed_pswd.size()==0){	//checks and see if the keyword has at least one element
		cout << "Invalid Hash";
		return 1;
	}




return 0;
}
