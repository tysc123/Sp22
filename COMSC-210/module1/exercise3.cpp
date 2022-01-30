//Student: Tyler Schmalenbach
//Student ID: 1482554

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib>

void mathCheck(string x);

int main() {
  string x;
  cout << "What is the sum or 2 and 3?";
  cin >> x;

  mathCheck(x);
}

void mathCheck(string x){
  int y;
  y = stoi(x);

  if (y == 5)
    cout << "Correct!" << endl;
  else
    cout << "Incorrect." << endl;
}