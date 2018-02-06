#include <iostream>
#include <fstream>
#include <string.h>
#include "personnel.h"

Personnel::Personnel(string& ssn, string& name, string& city, string& yob, uint32_t& salary) : nameLen(10), cityLen(10) {
	this->salary = salary;
	this->ssn = new char[9];
    this->name = new char[nameLen];
    this->city = new char[cityLen];
	this->yearOfBirth = new char[4];
 	strcpy(this->ssn, ssn.c_str());
 	strcpy(this->name, name.c_str());
 	strcpy(this->city, city.c_str());
 	strcpy(this->yearOfBirth, yob.c_str());
}

Personnel::Personnel(fstream& file) : nameLen(10), cityLen(10) {
	ssn = new char[9];
    name = new char[nameLen];
    city = new char[cityLen];
	yearOfBirth = new char[4];
	file.read(ssn, 9);
	file.read(name, nameLen);
	file.read(city, cityLen);
	file.read(yearOfBirth, 4);
	file.read(reinterpret_cast<char*>(&salary), sizeof(&salary));
}

Personnel::~Personnel() {
	delete ssn;
    delete name;
    delete city;
	delete yearOfBirth;
}

void Personnel::writeToFile(fstream& file) const {
	file.write(ssn, 9);
	file.write(name, nameLen);
	file.write(city, cityLen);
	file.write(yearOfBirth, 4);
	file.write(reinterpret_cast<const char*>(&salary), sizeof(&salary));
}

Personnel* readFromFile(fstream& file) {
	return new Personnel(file);
}

int Personnel::size() {
	return 9 + nameLen + cityLen + 4 + sizeof(&salary);
}

bool Personnel::operator==(const Personnel& rhs) {
	// strcomp returns 0 if cstrings are equal
	return strcmp(this->ssn, rhs.ssn) == 0;
}

void Personnel::print() {
	cout << "SSN: " << ssn << endl;
	cout << "Name: " << name << endl;
	cout << "City: " << city << endl;
	cout << "Year of Birth: " << yearOfBirth << endl;
	cout << "Salary: " << salary << endl;
}

char* Personnel::getSSN() {
	return ssn;
}
