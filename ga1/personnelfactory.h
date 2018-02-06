#ifndef PERSONNEL_FACTORY_H
#define PERSONNEL_FACTORY_H

#include <fstream>
#include "personnel.h"

/**
 * Factory class used to instantiate personnel objects from records in file
 */
class PersonnelFactory {
	string PERSONNEL_TYPE = "PERSONNEL";
	string STUDENT_TYPE = "STUDENT";

	string personnelType;

	public:
		PersonnelFactory();
		PersonnelFactory(string personnelType);
		Personnel* createFromFile(fstream& file);
};

PersonnelFactory::PersonnelFactory() : personnelType("PERSONNEL") {}

PersonnelFactory::PersonnelFactory(string personnelType) : personnelType(personnelType) {}

Personnel* PersonnelFactory::createFromFile(fstream& file) {
	if (personnelType == STUDENT_TYPE) {
		return new Student(file);
	} else {
		return new Personnel(file);
	}
}

#endif
