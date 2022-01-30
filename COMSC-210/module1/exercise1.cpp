//Student: Tyler Schmalenbach
//Student ID: 1482554

#include <iostream>
using namespace std;

int add(int x, int y);

int main() {
  int x, y;
  cout << "Enter number: ";
  cin >> x;
  cout << "Enter another number: ";
  cin >> y;

  cout << "The sum of " << x << " and " << y << " is: " << add(x, y);
  cout << endl;

  return 0;
}

int add(int x, int y){
  return (x + y);
}