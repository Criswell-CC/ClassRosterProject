#include <array>
#include <iostream>

#include "student.h"
#include "degree.h"

using namespace std;

Student::Student(string studentID, string firstName, string lastName, string email, int age, array<int, 3> daysToCompleteEachCourse, DegreeProgram degreeProgram) {

	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setAge(age);
	setDaysToCompleteEachCourse(daysToCompleteEachCourse);
	setDegreeProgram(degreeProgram);

};

string Student::getStudentID() {

	return studentID;

};

string Student::getFirstName() {

	return firstName;

};

string Student::getLastName() {

	return lastName;

};

string Student::getEmail() {

	return email;

};

DegreeProgram Student::getDegreeProgram() {

	return degreeProgram;

};

int Student::getAge() {

	return age;

};

array<int, 3> Student::getDaysToCompleteEachCourse() {

	return daysToCompleteEachCourse;

};

void Student::setStudentID(string newStudentID) {

	studentID = newStudentID;

};

void Student::setFirstName(string newFirstName) {

	firstName = newFirstName;

};

void Student::setLastName(string newLastName) {

	lastName = newLastName;

};

void Student::setEmail(string newEmail) {

	email = newEmail;

};

void Student::setDegreeProgram(DegreeProgram newDegreeProgram) {

	degreeProgram = newDegreeProgram;

};

void Student::setAge(int newAge) {

	age = newAge;

};

void Student::setDaysToCompleteEachCourse(array<int, 3> newDaysToComplete) {

	daysToCompleteEachCourse.at(0) = newDaysToComplete.at(0);
	daysToCompleteEachCourse.at(1) = newDaysToComplete.at(1);
	daysToCompleteEachCourse.at(2) = newDaysToComplete.at(2);

};

void Student::print() {

	string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };

	cout << getStudentID() << '\t' << "First Name: " << getFirstName() << '\t' << "Last Name: " << getLastName() << '\t' << "Email: " << getEmail() << '\t' << "Age: " <<
		getAge() << '\t' << "Days in Course: {" << getDaysToCompleteEachCourse()[0] << ", " << getDaysToCompleteEachCourse()[1] << ", " << getDaysToCompleteEachCourse()[2] << "}"
		<< '\t' << "Degree Program: " << degreeProgramStrings[getDegreeProgram()] << "\n";

};