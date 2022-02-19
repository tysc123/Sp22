#include <iostream>
#include <string>

using namespace std;

#include<cstdlib>
#include "StaticArray.h"

const bool PLACED = true;

int main(){

  cout << endl  << "Programmer: Tyler Schmalenbach" << endl;
  cout << "Programmer's ID: 1482664" << endl;
  cout << "File: " << __FILE__ << endl << endl;

  StaticArray<double, 100> valsStored;
  StaticArray<bool, 100> storeStatus;
  int storeTotal = 0;
  string index;
  string value;

  do{
    cout << "Input an index and a value [Q to quit]: ";
    cin >> index;
    if(index == "Q" || index == "q"){
    break;
    }

    cin >> value;
    cin.ignore(1000,10);
    valsStored[atof(index.c_str())] = atof(value.c_str());

    storeStatus[atof(index.c_str())] = PLACED;
  }

  while(index != "Q" || index != "q");
    cout << endl;

    //counting number of stored values
    for(int i = 0; i < 100; i++){
      if(storeStatus[i] == PLACED){
      storeTotal++;
      }
  }

  cout << "You stored this many values: " << storeTotal << endl;

  //printing the index-value pairs
  cout << "The index-value pairs are:" << endl;
  for(int i = 0; i < 100; i++){
    if(storeStatus[i] != 0){
    cout << i << " => " << valsStored[i] << endl;
    }
  }
  cout << endl;

  do{
    cout << "Input an index and a value [Q to quit]: ";
    cin >> index;

    if(index == "Q" || index == "q"){
    break;
    }

    if(storeStatus[atof(index.c_str())] == PLACED && atof(index.c_str()) >=0 && atof(index.c_str()) < 100){
    double valFind = valsStored[atoi(index.c_str())];
    cout << "Found it -- the value stored at " << index << " is " << valFind << endl;
    }
    else{
      cout << "I didn't find it\n";
    }
    }while(index != "Q" || index != "q");
}