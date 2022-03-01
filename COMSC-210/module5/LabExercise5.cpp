#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstring>

int main() {

    cout << "Programmer: Tyler Schmalenbach" << endl;
    cout << "Programmer ID: 1482664" << endl;
    cout << "File Name: " << __FILE__ << endl << endl;

    int count = 0;
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    ifstream fin;
    fin.open("dvc-schedule.txt");
    if (!fin.good()) throw "I/0 error";

    //read input file
    while (fin.good()) {
        string line;
        getline(fin, line);
        strcpy(buf, line.c_str());

        if (buf[0] == 0) continue; //skip blank lines

        //parse the lines
        const string term(token = strtok(buf, tab));
        const string section((token = strtok(0, tab)) ? token : "");
        const string course((token = strtok(0, tab)) ? token : "");
        const string instructor((token = strtok(0, tab)) ? token : "");
        const string whenWhere((token = strtok(0, tab)) ? token : "");
        if (course.find('-') == string::npos) continue; //may be invalid if not dash in course name
        const string subjectCode(course.begin(), course.begin() + course.find('-'));
        
        // cout << term << '|' << section << '|'
        //      << subjectCode << endl;

    
        count++;
   


    }

    fin.close();

    cout << "Total lines processed: " << count << endl << endl;

    return 0;

}