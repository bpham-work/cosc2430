#ifndef PERSONNEL_H
#define PERSONNEL_H

#include <string>
#include <fstream>
#include <bitset>
using namespace std;

class Personnel {
		char* ssn;
		char* name;
		char* city;
		char* yearOfBirth;
		uint32_t salary;
		int nameLen;
		int cityLen;

	public:
		Personnel(string& ssn, string& name, string& city, string& yob, uint32_t& salary);
		Personnel(fstream& file);
		~Personnel();
		void writeToFile(fstream& file) const;
		Personnel* readFromFile(fstream& file) const;
		int size();
		bool operator==(const Personnel& rhs);
		virtual void print();
		char* getSSN();
};

#endif

