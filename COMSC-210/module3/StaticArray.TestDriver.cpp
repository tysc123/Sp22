
#include <iostream>
using namespace std;

#include <cassert>
#include "StaticArray.h"

int main() {

  cout << endl  << "Programmer: Tyler Schmalenbach" << endl;
  cout << "Programmer's ID: 1482664" << endl;
  cout << "File: " << __FILE__ << endl << endl;

  StaticArray<int, 100> a; 

  cout << "\nTesting StaticArray::capacity\n";
  cout << "EXPECTED:" << 100 << endl;
  cout << "ACTUAL: " << a.capacity( ) << endl;
  assert(100 == a.capacity( )); //if false program will crash

  if (100 == a.capacity( ))cout << "Pass" << endl;
    cout << "\nTesting StaticArray::StaticArray\n";

  for (int i = 0; i < a.capacity( ); i++)
    assert(a[i] == 0);
  cout << "Pass" << endl;

  a[1] = 12356;
  a[2] = 7654321;
  cout << "\nTesting StaticArray::operator[ ] setter\n";
  cout << "EXPECTED: 12356 for a[1]" << endl;
  cout << "ACTUAL: " << a[1] << endl;
  assert(12356 == a[1]);

  cout << "EXPECTED: 7654321 for a[2]" << endl;
  cout << "ACTUAL: " << a[2] << endl;
  assert(7654321 == a[2]);

  a[-1000] = 123123;
  cout << "EXPECTED: 123123 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;
  assert(12356 == a[1]);
  assert(7654321 == a[2]);
  assert(123123 == a[-6]); // out-of-range uses dummy
  assert(123123 == a[100]); // upper end of range
  assert(123123 != a[99]); // upper end of range
  assert(123123 != a[0]); // lower end of range

  //testing doubles
  StaticArray<double, 100> b;

  cout << "\nTesting Array::capacity\n";
  cout << "EXPECTED:" << 100 << endl;
  cout << "ACTUAL: " << b.capacity( ) << endl;
  assert(100 == a.capacity( )); //if false program will crash

  if (100 == b.capacity( ))cout << "Pass" << endl;
    cout << "\nTesting Array::Array\n";

  for (int i = 0; i < b.capacity( ); i++)
    assert(a[i] == 0);
  cout << "Pass" << endl;

  a[1] = 123.56;
  a[2] = 54.321;
  cout << "\nTesting Array::operator[ ] setter\n";
  cout << "EXPECTED: 123.56 for a[1]" << endl;
  cout << "ACTUAL: " << a[1] << endl;
  assert(123.56 == a[1]);

  cout << "EXPECTED: 54.321 for a[2]\n";
  cout << "ACTUAL: " << a[2] << endl;
  assert(54.321 == a[2]);

  a[-1000] = 123123;
  cout << "EXPECTED: 123123 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;
  assert(123.56 == a[1]);
  assert(54.321 == a[2]);
  assert(123123 == a[-6]); // any out-of-range uses dummy
  assert(123123 == a[100]); // upper end of range
  assert(123123 != a[99]); // upper end of range
  assert(123123 != a[0]); // lower end of range

}




