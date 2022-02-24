
#include <iostream>
using namespace std;

#include <cassert>

class Array {
  int values[100];
  int dummy;

public:
  int capacity() const;
  int operator[](int) const; 
  int& operator[](int); 

};

int main() {

  cout << endl  << "Programmer: Tyler Schmalenbach" << endl;
  cout << "Programmer's ID: 1482664" << endl;
  cout << "File: " << __FILE__ << endl << endl;

  Array x;

  cout << endl << "Testing Array::capacity";

  cout << "EXPECTED: 100" << endl;
  cout << "RESULT: " << x.capacity() << endl;

  assert(100 == x.capacity());

  cout << endl << "Testing Array::operator[ ] setter" << endl;

  x[20] = 99;
  x[45] = 999;

  cout << "EXPECTED: 99 for x[20]" << endl;
  cout << "RESULT: " << x[20] << endl;
  assert(99 == x[20]);

  cout << "EXPECTED: 999 for x[45]" << endl;
  cout << "RESULT: " << x[45] << endl;
  assert(999 == x[45]);

  const Array y = x;

  cout << endl << "testing Array::operator[ ] getter" << endl;

  cout << "EXPECTED: 99 for y[20]" << endl;
  cout << "RESULT: " << y[20] << endl;

  assert(99 == y[20]);

  cout << "EXPECTED: 999 for y[45]" << endl;
  cout << "RESULT: " << y[45] << endl;

  assert(999 == y[45]);

}

int Array::operator[](int i) const {
  if (i < 0 || i >= capacity()) 
    return dummy;
  else
    return values[i];
}

int& Array::operator[](int i) {
  if (i < 0 || i >= capacity()) 
    return dummy;
  else
    return values[i];
}