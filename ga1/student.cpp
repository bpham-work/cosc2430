#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "student.h"
using namespace std;

Student::Student(string& ssn, string& name, string& city, string& yob, uint32_t& salary, string& major) : majorLen(10), Personnel(ssn, name, city, yob, salary) {
	this->major = new char[majorLen];
	strcpy(this->major, major.c_str());
}

Student::Student(fstream& file) : majorLen(10), Personnel(file) {
	major = new char[majorLen];
	file.read(major, majorLen);
}

Student::~Student() {
	delete major;
}

/**
 * Write object values to file
 */
void Student::writeToFile(fstream& file) const {
	Personnel::writeToFile(file);
	file.write(major, majorLen);
}

/**
 * Read record from file and create new student
 */
Student* Student::readFromFile(fstream& file) const {
	return new Student(file);
}

/**
 * Return size of record
 */
int Student::size() {
	return Personnel::size() + majorLen;
}

void Student::print() {
	Personnel::print();
	cout << "Major: " << major << endl;
}
