#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <fstream>
#include <string.h>
#include "student.h"
#include "personnelfactory.h"
using namespace std;

template <class T>
class Database {
	fstream file;
	PersonnelFactory personnelFactory;

	public:
		Database(PersonnelFactory& personnelFactory);
		int find(T& person);
		Personnel* findBySSN(string& ssn);
		void modify(T& person);
		void add(T& person);
		void print();
	private:
		void open();
		void resetFilePointer();
		void close();
};

template <class T>
Database<T>::Database(PersonnelFactory& personnelFactory) {
	this->personnelFactory = personnelFactory;
};

template <class T>
int Database<T>::find(T& person) {
	this->open();
	int streamPos = 0;
	int eof;
	while (eof != -1) {
		Personnel* personFromFile = personnelFactory.createFromFile(file);
		if (*personFromFile == person) {
			return streamPos;
		} else {
			eof = file.peek();
			streamPos += person.size();
			file.seekg(streamPos);
		}
		delete personFromFile;	
	}
	this->close();
    return -1;
};

template <class T>
Personnel* Database<T>::findBySSN(string& ssn) {
	this->open();
	int streamPos = 0;
	int eof;
	while (eof != -1) {
		Personnel* personFromFile = personnelFactory.createFromFile(file);
		if (strcmp(personFromFile->getSSN(), ssn.c_str()) == 0) {
			return personFromFile;
		} else {
			eof = file.peek();
		}
		delete personFromFile;	
	}
	this->close();
    return NULL;
}

template <class T>
void Database<T>::modify(T& person) {
	int streamPos = this->find(person);
	if (streamPos > -1) {
		file.seekp(streamPos);
		person.writeToFile(file);
	}
};

template <class T>
void Database<T>::add(T& person) {
	this->open();
    file.seekp(0, ios_base::end);
    person.writeToFile(file);
	this->close();
}

template <class T>
void Database<T>::print() {
	this->open();
	int streamPos = 0;
	int eof = file.peek();
	while (eof != -1) {
		Personnel* personFromFile = personnelFactory.createFromFile(file);
		personFromFile->print();
		cout << endl;
		eof = file.peek();
		delete personFromFile;	
	}
	this->close();
}

template <class T>
void Database<T>::open() {
	file.open("input.txt", fstream::out | fstream::in);
	if (!file.is_open()) {
		file.open("input.txt", fstream::out);
		file.close();
		file.open("input.txt", fstream::out | fstream::in);
	}
	this->resetFilePointer();
}

template <class T>
void Database<T>::resetFilePointer() {
	file.clear();
	file.seekg(0);
}

template <class T>
void Database<T>::close() {
	file.close();
}

#endif
