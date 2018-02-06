#include <iostream>
#include <fstream>
#include <string>
#include "database.h"
#include "student.h"
#include "personnelfactory.h"
using namespace std;

/**
 * Add student to database
 */
void add(Database<Student>& db, PersonnelFactory& factory) {
	cout << endl;
	cout << "----- ADD NEW STUDENT -----" << endl;
	string ssn, name, city, yob, major;
	uint32_t salary;
	cout << "SSN: ";
	cin >> ssn;
	cout << "Name: ";
	cin >> name;
	cout << "City: ";
	cin >> city;
	cout << "Year Of Birth: ";
	cin >> yob;
	cout << "Salary: ";
	cin >> salary;
	cout << "Major: ";
	cin >> major;
	Student newStudent(ssn, name, city, yob, salary, major);

	Personnel* student = db.findBySSN(ssn);
	if (student == NULL) {
		db.add(newStudent);
		cout << endl;
		cout << "Added student: " << endl;
		newStudent.print();
	} else {
		cout << "Student with entered SSN already exists" << endl;
	}
	cout << endl;
}

/**
 * Find student in database
 */
void findStudent(Database<Student>& db) {
	cout << endl;
	cout << "----- FIND STUDENT BY SSN -----" << endl;
	cout << "Enter SSN of student: ";
	string ssn;
	cin >> ssn;
	Personnel* student = db.findBySSN(ssn);
	if (student == NULL) {
		cout << "Student not found by SSN entered" << endl;
	} else {
		student->print();
	}
	cout << endl;
}

/**
 * Modify student in database
 */
void modifyStudent(Database<Student>& db) {
	cout << endl;
	cout << "----- MODIFY STUDENT -----" << endl;
	cout << "Enter SSN of student: ";
	string ssn;
	cin >> ssn;
	Personnel* student = db.findBySSN(ssn);

	if (student == NULL) {
		cout << "Student not found by SSN entered" << endl;
	} else {
		string name, city, yob, major;
		uint32_t salary;
		cout << "Name: ";
		cin >> name;
		cout << "City: ";
		cin >> city;
		cout << "Year Of Birth: ";
		cin >> yob;
		cout << "Salary: ";
		cin >> salary;
		cout << "Major: ";
		cin >> major;
		Student modifiedStudent(ssn, name, city, yob, salary, major);
		db.modify(modifiedStudent);

		cout << endl;
		cout << "Modified student: " << endl;
		modifiedStudent.print();
	}
	cout << endl;
}

/**
 * Print all students in database
 */
void printAll(Database<Student>& db) {
	cout << endl;
	cout << "----- PRINTING ALL STUDENTS -----" << endl;
	db.print();
}

int main() {
	PersonnelFactory factory("STUDENT");
	Database<Student> db(factory);
	bool exit = false;
	int menuInput = -1;
	while (!exit) {
		cout << "----- Main Menu -----" << endl;
		cout << "1. Add student" << endl;
		cout << "2. Find student" << endl;
		cout << "3. Modify student" << endl;
		cout << "4. Print all students" << endl;
		cout << "5. Exit" << endl;
		cout << "Selection: ";
		cin >> menuInput;
		switch (menuInput) {
			case 1:
				add(db, factory);
				break;
			case 2:
				findStudent(db);
				break;
			case 3:
				modifyStudent(db);			
				break;
			case 4:
				printAll(db);
				break;
			default:
				cout << "Exiting program" << endl;
				exit = true;
				break;
		}
	}
	return 0;
}
