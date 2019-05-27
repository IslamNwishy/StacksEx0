//File: App.cpp

//Name: Islam Osama Nwishy
//ID#:900170200
//Assignment 1 - Part (2)

#include <iostream>
#include <string>
#include "Stackt.h"
#include "stackt.cpp"
using namespace std;

void Start(stackt<char> &Check, stackt<string> &postfix, stackt<double> &Result);
void GetPostfixStack(string values, stackt<char>& Check, stackt<string> &postfix, stackt<double> &Result);
void Calculate(double Num1, double Num2, char Operator, stackt<double> &Result);
void Reverse(stackt<string>& postfix);
void Show(stackt<string> &postfix, stackt<double> &Result);


//Declares the 3 main Stacks and Starts the Program
//Checks if the user wants to restart the program
void main() {
	

	//Restart returns true only if the user enters Y or y when asked
	//choice is made to take the users input for the answer if they want to restart the program or not
	bool Restart = false;
	char choice;
	
	//the loop breaks if the user entered any key other than Y or y
	do {
		//3 stacks 1 to check the bracktes, 1 to make the postfix expression and 1 to make the calculations get the result
		stackt<char> CheckBrackets;
		stackt<string> Postfix;
		stackt<double> Result;

		Start(CheckBrackets, Postfix, Result);
		cout << endl << endl << "Do you want to Restart?" << endl << "Y or N ?" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
			Restart = true;
		else
			Restart = false;
	} while (Restart);

	
}

//The entry point to the program
//Asks for the input and calls the Functions needed to calculate and display the results
void Start(stackt<char> &Check, stackt<string> &postfix, stackt<double> &Result) {
	string values;

	cout << "Please Enter an Infix Expression" << endl;
	cin >> values;

	GetPostfixStack(values, Check, postfix,Result);
	Reverse(postfix);
	Show(postfix,Result);


}


//Get the postfix stack of the given Expression named "Values" and calculate it
void GetPostfixStack(string values, stackt<char>& Check, stackt<string> &postfix, stackt<double> &Result) {
	string numbers;

	//Loop In the given Expression
	for (int i = 0; i < values.length(); i++) {
		char letter = values[i];
		
		//compare each letter with the following possibilities
		switch (letter)
		{
			//if it is an open bracket push it to the Check stack
		case '(':
			Check.push(letter); break;
		//if it is a closing bracket do the following:
		case ')':
			//Add the number (could be a 2 digit number) to the postfix stack and the reuslt stack if there is any
			if (!numbers.empty()) {
				postfix.push(numbers);
				Result.push(stod(numbers));
				numbers.clear();
			}

			//keep poping operators into postfix when the bracket closes until you find its opening one
			//It Also Calculates the Operation of the top 2 elements
			while(Check.Peak() != '(') {
				
					postfix.push(string(1, Check.Peak()));

					Calculate(Result.pop(), Result.pop(), Check.pop(),Result);
					
			}
			//pop the opened bracket to match the closed one (so the check stack would not check it again)
			Check.pop();

			//check if there was an operator between 2 seprate closed pair of brackets
			//i.e (2+4)*(5-8) --> in this case the following statement will push "*" after its done with the 2 pair of brackets
			//It Also Calculates the Operation of the top 2 elements
			if (!Check.IsEmpty())
				if (Check.Peak() != '(') {
					postfix.push(string(1, Check.Peak()));
					Calculate(Result.pop(), Result.pop(), Check.pop(), Result);
				}
			break;

			//in case of any operator, push that operator into the check stack and push the numbers (if any) into the postfix
		case '+':
		case '-':
		case '/':
		case '*':
			Check.push(letter);
			//Add the number (could be a 2 digit number) to the postfix stack and the reuslt stack if there is any
			if (!numbers.empty()) {
				postfix.push(numbers);
				Result.push(stod(numbers));
				numbers.clear();
			}
			
	break;

	//in case non of the above is satisfied then the letter is a digit, in that case push it into a string
	//this allows the program to handle multiple digit integers (Bonus)
		default:
			numbers.push_back(letter); break;
		}

	}

	//after the loop is done add any remaining operators to the postfix stack
	while (!Check.IsEmpty()) {
		postfix.push(string(1, Check.pop()));
		Calculate(Result.pop(), Result.pop(), Check.pop(), Result);
	}
}


//It Takes 2 numbers, an Operator and a Stack then Pushes the reuslt of the operation on the 2 numbers to the stack
void Calculate (double Num1, double Num2, char Operator, stackt<double> &Result) {
	if (Operator == '+')
		Result.push (Num1 + Num2);
	else if (Operator == '-')
		Result.push(Num1 - Num2);
	else if (Operator == '*')
		Result.push(Num1 * Num2);
	else if (Operator == '/')
		Result.push(Num1 / Num2);
}

//Reverses the postfix stack to display it in the right order
void Reverse(stackt<string>& postfix) {
	stackt<string>Temp;

	while (!postfix.IsEmpty()) {
		Temp.push(postfix.pop());
	}
	postfix = Temp;
}

//Outputs the Results
void Show(stackt<string>& postfix, stackt<double>& Result) {

	cout << endl <<"Converted Postfix string is: ";
	postfix.Display();
	cout << endl << endl << "The Result Is " << Result.pop() << endl;

}