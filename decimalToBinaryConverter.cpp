#include <iostream>
#include <string>

std::string ConvertToBinary();

int UserInputValidation(int);

void menu();

int main(){
	menu();

	std::cin.ignore();

	return 0;
}

void menu(){
	std::string userResponse;
	std::string answer;

	std::cout << "This application will convert a decimal value to its equivalent binary value. \n" << std::endl;

	while (true){
		answer = ConvertToBinary();

		std::cout << "The binary equivalent is = " << answer << '\n';

		std::cout << "Would you like to go again? (yes/no): ";

		std::cin >> userResponse;

		if (userResponse == "yes"){
			continue;
		}
		else{
			std::cout << "Goodbye!";

			break;
		}
	}
}

std::string ConvertToBinary() {
	int userInput = 0;

	userInput = UserInputValidation(userInput);

	std::string result = "";

	while (userInput!= 0) {
		result = (userInput % 2 == 0 ? "0" : "1") + result;

		userInput /= 2;
	}
	
	return result;
}

int UserInputValidation(int userInput) {
	bool isValid = true;

	std::cout << "Please enter a number: ";

	while (isValid != false) {
		std::cin >> userInput;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');

			std::cout << "Please enter valid integers greater than 0:  ";
		}
		else if (userInput <= 0) {
			std::cout << "Please enter an integer greater than 0: ";
		}
		else {
			isValid = false;
		}
	}

	return userInput;
}