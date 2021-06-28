#include <array> 
#include <iostream>
#include <string>
#include <vector>

#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;

int Roster::findIndexByStudentID(string studentID) {

	int index = -1;

	for (size_t i = 0; i < classRosterSize; i++) {

		if (classRosterArray[i]->getStudentID() == studentID) {
			index = i;
			break;
		}

	}

	return index;

};

string stringSplice(string studentRecord, int numberCommas) {

	string newString = studentRecord;

	for (int i = 0; i < numberCommas; i++) {

		newString = newString.substr(newString.find(',') + 1);

	};

	return newString;

};

string parseStudentID(string studentData) {

	string studentID = studentData.substr(0, studentData.find(','));

	return studentID;

};

string parseStudentFirstName(string studentData) {

	string newString = stringSplice(studentData, 1);

	string firstName = newString.substr(0, newString.find(','));

	return firstName;

};

string parseStudentLastName(string studentData) {

	string newString = stringSplice(studentData, 2);

	string lastName = newString.substr(0, newString.find(','));

	return lastName;

};

string parseEmail(string studentData) {

	string newString = stringSplice(studentData, 3);

	string email = newString.substr(0, newString.find(','));

	return email;

};

int parseStudentAge(string studentData) {

	string newString = stringSplice(studentData, 4);

	string ageString = newString.substr(0, newString.find(','));

	int age = stoi(ageString);

	return age;

};

array<int, 3> parseStudentDaysToCompleteEachCourse(string studentData) {

	string newString = stringSplice(studentData, 5);

	string firstDayNumString = newString.substr(0, newString.find(','));

	newString = stringSplice(studentData, 6);

	string secondDayNumString = newString.substr(0, newString.find(','));

	newString = stringSplice(studentData, 7);

	string thirdDayNumString = newString.substr(0, newString.find(','));

	int firstDayNum = stoi(firstDayNumString);

	int secondDayNum = stoi(secondDayNumString);

	int thirdDayNum = stoi(thirdDayNumString);

	array<int, 3> daysToCompleteEachCourse = { firstDayNum, secondDayNum, thirdDayNum };

	return daysToCompleteEachCourse;

};

DegreeProgram parseDegreeProgram(string studentData) {

	string newString = stringSplice(studentData, 8);

	DegreeProgram degreeProgram;

	if (newString == "NETWORK") {

		degreeProgram = NETWORK;

	}

	if (newString == "SECURITY") {

		degreeProgram = SECURITY;

	}

	if (newString == "SOFTWARE") {

		degreeProgram = SOFTWARE;

	}

	return degreeProgram;

};


Roster::Roster(const string studentData[], size_t arraySize) {

	classRosterSize = arraySize;

	for (size_t i = 0; i < classRosterSize; i++) {

		add(parseStudentID(studentData[i]), parseStudentFirstName(studentData[i]), parseStudentLastName(studentData[i]), parseEmail(studentData[i]),
			parseStudentAge(studentData[i]), parseStudentDaysToCompleteEachCourse(studentData[i]), parseDegreeProgram(studentData[i]), i);

	};

};

Roster::~Roster() {

	for (size_t i = 0; i < classRosterSize; i++) {

		delete classRosterArray[i];

	};

};

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, array<int, 3> daysToCompleteEachCourse, DegreeProgram degreeprogram, size_t index) {

	Student* newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysToCompleteEachCourse, degreeprogram);

	classRosterArray[index] = newStudent;

};

void Roster::remove(string studentID) {

	int index = findIndexByStudentID(studentID);

	if (index == -1) {

		cout << "No student with that ID found" << "\n";

	}

	else {

		delete classRosterArray[index];

		for (size_t i = index + 1; i < classRosterSize; i++) {

			memcpy(&classRosterArray[i-1], &classRosterArray[i], sizeof(classRosterArray[i]));

		}

		classRosterSize = classRosterSize - 1;

		classRosterArray[classRosterSize] = nullptr;

	}

};

void Roster::printAll() {

	for (size_t i = 0; i < classRosterSize; i++) {

		if (classRosterArray[i] != nullptr) {
		
			classRosterArray[i]->print();

		}
	};

	cout << '\n';

};

void Roster::printAverageDaysInCourse(string studentID) {

	int index = findIndexByStudentID(studentID);

	array<int, 3> daysToComplete = classRosterArray[index]->getDaysToCompleteEachCourse();

	int sum = 0;

	for (size_t i = 0; i < daysToComplete.size(); i++) {

		sum += daysToComplete[i];

	};

	int avg = sum / daysToComplete.size();

	cout << "Student ID: " << studentID << " averages " << avg << " days in a course." << "\n";

};

vector<string> Roster::getInvalidEmails() {

	vector<string> invalidEmails;

	for (size_t i = 0; i < classRosterSize; i++) {

		string currentEmail = classRosterArray[i]->getEmail();

		if (currentEmail.find('@') == string::npos || currentEmail.find(' ') != string::npos || currentEmail.find('.') == string::npos) {

			invalidEmails.push_back(currentEmail);

		}

	};

	return invalidEmails;

};

void Roster::printInvalidEmails() {

	vector<string> invalidEmails = getInvalidEmails();

	if (invalidEmails.size() != 0) {

		cout << "Invalid emails found: " << '\n';

		for (size_t i = 0; i < invalidEmails.size(); i++) {

			cout << '\t' << invalidEmails[i] << '\n';

		}

		cout << '\n';

	}

	else {

		cout << "No invalid emails." << '\n';

	}

};

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };

	cout << "Showing students in degree program: " << degreeProgramStrings[degreeProgram] << '\n';

	for (size_t i = 0; i < classRosterSize; i++) {

		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {

			classRosterArray[i]->print();

		}

	}

	cout << '\n';

};