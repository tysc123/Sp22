#include <iostream>
using namespace std;

#include <cstdlib>

class Array
{
  int values[100];
  int dummy;

public:
  int capacity() const {
    return 100; // how do I do this without changing public interface?
  } 
  int operator[](int) const; //getter
  int& operator[](int); //setter
};

int main() {
  // identification
  cout << endl  << "Programmer: Tyler Schmalenbach" << endl;
  cout << "Programmer's ID: 1482664" << endl;
  cout << "File: " << __FILE__ << endl << endl;

  Array x, y;
  int i;

  // initialize to zero
  for(int i = 0; i < y.capacity(); i++)
    y[i] = 0;

  // data prompts, while loop that stays true until user quits
  while(true) {
    string buf;
    cout << "Input an i and a value [Q to quit]: ";
    cin >> buf;

    if (buf == "Q" || buf == "q")
      break;
    
    i = atoi(buf.c_str());
    cin >> buf;
    
    if (buf == "Q" || buf == "q")
      break;
    
    x[i] = atoi(buf.c_str());
    y[i] = 9999;
  }

  int numberOfValues = 0;
  for(int i = 0; i < y.capacity(); i++) {
    if(y[i] == 9999)
      numberOfValues ++;
  }

  cout << endl << "You stored this many values: " << numberOfValues << endl;
  cout << endl << "The i-value pairs are:" << endl << endl;

  for(int i = 0; i < y.capacity(); i++) {
    if(y[i] == 9999)
      cout << i << " " << x[i] << endl;
  }

  // index lookup, q to quit
  while (true) {
    string buf;
    cout << endl << "Input an index for me to look up [Q to quit]: ";
    cin >> buf;

    if (buf == "Q" || buf == "q") 
      break;
    i = atoi(buf.c_str());

    if(y[i] == 9999 && i > 0 && i <= 100)
      cout << "Found it -- the value stored at " << i << " is " << x[i] << endl;

    else
      cout << "I didn't find it :(" << endl;
  }
}

// member functions, use dummy if out of range
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