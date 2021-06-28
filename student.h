#pragma once

#include <array>
#include <string>

#include "degree.h"
#include "roster.h"

using namespace std;

class Student {

	string studentID;
	string firstName;
	string lastName;
	string email;
	DegreeProgram degreeProgram;

	int age;
	array<int, 3> daysToCompleteEachCourse;

public:

	Student(string studentID, string firstName, string lastName, string email, int age, array<int, 3> daysToCompleteEachCourse, DegreeProgram degreeProgram);

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	DegreeProgram getDegreeProgram();
	int getAge();
	array<int, 3> getDaysToCompleteEachCourse();

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setDegreeProgram(DegreeProgram degreeProgram);
	void setAge(int age);
	void setDaysToCompleteEachCourse(array<int, 3> daysToCompleteEachCourse);

	void print();

};