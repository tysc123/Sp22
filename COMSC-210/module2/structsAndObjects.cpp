

// Programmer: First Last
// Programmer's ID: 1234567

#include <iostream>
#include <string>
using namespace std;

#include <cstdlib> // for atoi and atof

struct Student
{
  string name;
  int studentID;
  float gpa;
};

Student input( );
void output(const Student&);

int main( )
{
  cout << "Programmer: First Last\n";
  cout << "Programmer's ID: 1234567\n";
  cout << "File: " << __FILE__ << ends;

// create an array of student objectt
  const int CAPACITY = 2;
  Student x[CAPACITY]; // an array of objects

// enter data for each student
  for (int i = 0; i < CAPACITY; i++)
    x[i] = input( );

// output each student's data
  for (int i = 0; i < CAPACITY; i++)
    output(x[i]);
}

Student input( ) // a value-returning function that returns an object
{
  Student result;
  cout << "Enter a student's name ";
  getline(cin, result.name);

  char buf[100];
  cout << "Enter " << result.name <<"'s student ID: ";
  cin >> buf; result.studentID = atoi(buf);
  cin.ignore(1000, 10);

  cout << "Enter " << result.name << "'s GPA: ";
  cin >> buf; result.gpa = atof(buf);
  cin.ignore(1000, 10);

  return result;
}

void output(const Student& s) // a void function
{
  cout.width(32);
  cout << s.name;
  cout.width(10);
  cout << s.studentID;
  cout.setf(ios::fixed);
  cout.precision(2);
  cout.width(10);
  cout << s.gpa << endl;
}

