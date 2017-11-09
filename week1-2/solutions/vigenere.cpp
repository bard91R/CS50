#include <iostream>
#include <string>

using namespace std;


char encrypt(char letter, int key){


	if(isupper(letter) && (int(letter+key)>90) || islower(letter) && (int(letter+key)>122)){

		letter = int(letter+key)-26;
	}else if(isupper(letter)!=0 || islower(letter)!=0){

		letter = int(letter+key);		
	}

return letter;
}



int main (){


	//unsigned int keyword=0;
	string keyword;
	int index = 0;
	int key_position = 0;	//will be used to keep track of element of the key being used
	int key_value;
	string text;

	cout << "Enter Keyword:";
	//getchar();
	getline(cin, keyword);

	if(keyword.size()==0){	//checks and see if the keyword has at least one element
		cout << "Invalid Keyword";
		return 1;
	}
	else{
		while(keyword[index]){	//checks if the keyword has anything other than letters
			if(isalpha(keyword[index])==false){
				cout << "Invalid Keyword";
				return 1;
			}
			
			index++;	
		}

		cout << "Plaintext:";
		//getchar();
		getline(cin, text);

		index = 0;	//resets the index

		while(text[index]){

			key_position;


			if(isupper(keyword[key_position])){		//figures out value of the key regardless if it is upper or lower case
				key_value = (keyword[key_position]-65)%26;
			}else{
				key_value = (keyword[key_position]-97)%26;
				
			}			

			if(isalpha(text[index])){	//increments the cipher to be used if it was actually used
				text[index] = encrypt(int(text[index]),key_value);
				key_position++;
			}


			index++;
			if(key_position==keyword.size()){ 
				key_position=0; 
			}
		}

		cout << text << "    output " << "\n";

	}

	return 0;
}

