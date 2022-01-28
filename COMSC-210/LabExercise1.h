#include <iostream>
#include <string>
using namespace std;

void welcome() {

    string firstName;
    string lastName;

    //ask for user input
    cout << "Please enter your first name: ";
    cin >> firstName;
    cout << "Please enter your last name: ";
    cin >> lastName;

    //display output

    cout << "COMSC210: Lab Exercise 1" << endl;
    cout << "================================" << endl;
    cout << firstName << " " << lastName << ", welcome to COMSC-210-2704!" << endl;
    cout << firstName << " ";
    cout << lastName;
    cout << " enjoys the hybrid format class!" << endl;
    cout << lastName << ", " << firstName << endl;
    cout << "The class will meet once a week at 11:10am in ATC115 on Thursday." << endl; 

}