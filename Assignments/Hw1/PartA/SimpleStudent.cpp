#include <string>
using namespace std;

#include "SimpleStudent.h"

//constructer
Student::Student(const int sid, const string sname){
	studentId = sid;
	studentName = sname;
}
//destructer
Student::~Student(){
}

//copy constructor
Student::Student(const Student & studentToCopy) {
	studentId = studentToCopy.studentId;
	studentName = studentToCopy.studentName;
}

//assignment operator
void Student::operator=(const Student & right) {
		studentId = right.studentId;
		studentName = right.studentName;
}

//getter methods
int Student::getStudentId() {
	return studentId;
}
string Student::getStudentName() {
	return studentName;
}
//setter methods
void Student::setStudentId(int newId) {
	studentId = newId;
}
void Student::setStudentName(string newName) {
	studentName = newName;
}
