#ifndef STUDENT_H
#define STUDENT_H

#include <fstream>
#include <string>
#include "personnel.h"
using namespace std;

class Student : public Personnel {
	char* major;
	int majorLen;

	public:
		Student(string& ssn, string& name, string& city, string& yob, uint32_t& salary, string& major);
		Student(fstream& file);
		~Student();
		int size();
		void writeToFile(fstream &file) const;
		Student* readFromFile(fstream &file) const;
		void print();
};

#endif
