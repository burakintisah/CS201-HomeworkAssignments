#pragma once

#ifndef __SIMPLE_STUDENT_H
#define __SIMPLE_STUDENT_H
#include <string>
using namespace std;
class Student {

public:
	Student(const int sid = 0, const string sname = "");
	~Student();
	Student(const Student &studentToCopy);
	void operator=(const Student &right);
	int getStudentId();
	string getStudentName();
	void setStudentId(int newId);
	void setStudentName(string newName);
private:
	int studentId;
	string studentName;
};
#endif

