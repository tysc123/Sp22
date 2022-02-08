//Student: Tyler Schmalenbach
//ID: 1482664

#include <iostream>
using namespace std;

class Array {  
  int values[100]; 
  int dummy;

public:
  Array();
  int capacity() const;
  int operator [](int) const;
  int& operator [](int);
};

int capacity(){
  return 100;
}

int operator[](int i){
  if (i < 0 || i >= capacity)
    return dummy; 
  return values[i];
}

