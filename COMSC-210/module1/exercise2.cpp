//Student: Tyler Schmalenbach
//Student ID: 1482554

#include <iostream>
#include <string>
using namespace std;


void display(string x);

int main() {
  string x;

  cout << "Write a string of three characters: ";
  cin >> x;

  display(x);
  return 0;
}

void display(string x) {

  cout << "You typed: " << x << endl;
}

