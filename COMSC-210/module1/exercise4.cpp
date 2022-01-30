//Student: Tyler Schmalenbach
//Student ID: 1482554
#include <iostream>
using namespace std;

#include <fstream>

int main(){

  ofstream outf{"exercise.csv"};
  if (!outf){
    cout << "Uh oh, could not be opened for writing!\n";
    return 0;
  }
  else
  outf << "Name\tAge\tGPA\n";
  outf << "Tyler\t26\t3.9" << endl;
  outf << "Kelly\t21\t4.1" << endl;
  outf << "Joe\t19\t3.6" << endl;
 
  return 0;
}