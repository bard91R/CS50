#include <iostream>

using namespace std;

//I don't believe the algorithm as described in the course page is correct for all credit cards, it works for Amex, it is described differently in here, and the results do change
//https://www.freeformatter.com/credit-card-number-generator-validator.html

int sum_of_digits(int digit){

	digit=digit*2;

	if(digit>9){
		digit-=9;
	}
	cout << digit<<" digito \n";
	return digit;
}




int main (){


	long long int card_number=0;
	
	cout << "Please enter a credit card number: ";
	cin >> card_number;

	cout<< card_number << "\n";

	long long int card_copy=card_number;


	int first_checksum=0;
	int second_checksum=0;
	int checksum=1;

	int residuo = 0;
	int count = 0; //counts the number of elements in the card

	//iterates over each number of the card
	while(card_copy>0){
		
		//residuo = card_copy % 10;
		//card_copy-=residuo;
		card_copy= card_copy/10;
		count++;
	}

	
	int number_of_digit = count;
	count = 0;

	while(card_number!=0){

		residuo = card_number % 10;
		if(number_of_digit%2==0){
			if(count%2==0){						
				first_checksum+=sum_of_digits(residuo);
			}else{
				second_checksum+=residuo;
			}
		}else{
			if(count%2==0){		
				first_checksum+=residuo;
			}else{
				second_checksum+=sum_of_digits(residuo);
			}
		}
	
		card_number-=(residuo);
		card_number=card_number/10;
		count++;
	}

	

	cout<<first_checksum << " \nfirst\n";
	cout<<second_checksum << " \nsecond\n";

	checksum=first_checksum+second_checksum;

	if(checksum%10==0){
		cout << "valid\n";
	}else{
		cout << "invalid\n";
		}

}
