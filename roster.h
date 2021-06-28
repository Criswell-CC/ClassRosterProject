#pragma once

#include <array>
#include <string>
#include <vector>

#include "degree.h"

using namespace std;

class Student;

class Roster {

	size_t classRosterSize = 0;

	//private utility methods
	int findIndexByStudentID(string studentID);
	vector<string> getInvalidEmails();

public:

	Student* classRosterArray[5] = { NULL };

	Roster(const string studentData[], size_t arraySize);
	~Roster();

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, array<int, 3> daysLeftInCourse, DegreeProgram degreeprogram, size_t index);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

};