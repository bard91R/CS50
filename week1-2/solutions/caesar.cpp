#include <iostream>
#include <string>

using namespace std;


char encrypt(char letter, int key){


	if(isupper(letter) && (int(letter+key)>91) || islower(letter) && (int(letter+key)>122)){

		letter = int(letter+key)-26;
	}else if(isupper(letter)!=0 || islower(letter)!=0){

		letter = int(letter+key);		
	}

return letter;
}



int main (){

	unsigned int key=0;
	string text;
	int index = 0;

	cout << "Please enter the key: ";
	cin >> key;
	cout << "Plaintext:" << "\n";

	getchar();
	getline(cin, text);

	if(key>26){
		key = key%26;	//handles any value for key greater than 26
	}
	
	while(index<text.size()){
		text[index] = encrypt(int(text[index]), key);	
		index+=1;
	}

	cout<< text << "\n";
	return 0;
}
