// Tyler Schmalenbach
// 1482664

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include "DynamicArray.h"

using namespace std;

class subject {
public:
	string subjectCode; 
	int count = 0; 
};

int main() {
	
	cout << "Programmer: Tyler Schmalenbach" << endl; 
	cout << "Programmer ID: 1482664" << endl; 
	cout << "File: " << __FILE__ << endl; 

	DynamicArray<string> firstInstance(100);
	DynamicArray<subject> subjectCount(100);

	int count = 0; 
	int duplicate = 0; 
	int classIndex = 0; 
	int subjectIndex = 0; 

	char* token; 
	char buf[1000];
	const char* const tab = "\t"; 

	ifstream fin; 
	fin.open("dvc-schedule.txt"); 
	if (!fin.good()) throw "I/O Error.";

	while (fin.good()) {
		//parse file
		//make copy to find duplicates 
		string line; 
		getline(fin, line); 
		strcpy(buf, line.c_str()); 

		if (buf[0] == 0) continue;

		const string term(token = strtok(buf, tab));
		const string section((token = strtok(0, tab)) ? token : "");
		const string course((token = strtok(0, tab)) ? token : "");
		const string instructor((token = strtok(0, tab)) ? token : "");
		const string whenWhere((token = strtok(0, tab)) ? token : "");
		if (course.find('-') == string::npos) continue;
		const string subjectCode(course.begin(), course.begin() + course.find('-'));
		string classCode = term + "." + section;

		//Duplicate check. 
		int i = 0; 
		for (i = 0; i < classIndex; i++) {
			if (firstInstance[i] == classCode) {
				break;
			}
		}
		 if (i == classIndex) { //is not duplicate
			firstInstance[classIndex++] = classCode;
		}
		else { //is duplicate
			duplicate++;
			count++; 
			continue;
		}
		
		//Progress bar
		if (count % 1000 == 0) {
			cout << '.'; cout.flush();
		}

		int s = 0;
		for (s = 0; s < subjectIndex; s++) {
			if (subjectCount[s].subjectCode == subjectCode)	{
				subjectCount[s].count++;
				break;
			}
		}

		if (s == subjectIndex) {
			subjectCount[subjectIndex++] = {subjectCode, 1};
		}

		count++;  // total
		
	}
	fin.close(); 

	for (int i = 0; i < subjectIndex; i++) {
		for (int j = i + 1; j < subjectIndex; j++) {
			if (subjectCount[j].subjectCode < subjectCount[i].subjectCode) {
				swap(subjectCount[j], subjectCount[i]);
			}
		}
	}

	cout << endl;

	//output
	for (int i = 0; i < subjectIndex; i++) {
		cout << subjectCount[i].subjectCode << "," << subjectCount[i].count << " sections" << endl; 
	}

	cout << endl; 

	cout << "Total duplicates: " << duplicate << endl; 
	cout << "Total counts: " << count << endl; 
	cout << "Total subjects: " << subjectIndex << endl; 

	return 0;
}

