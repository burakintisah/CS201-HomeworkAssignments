#include <string>
using namespace std;
#include "SimpleStudent.h"
#include "SimpleSRS.h"

SRS::SRS()
{
	studentNo = 0;
	students = NULL;
}

SRS::~SRS(){
	delete [] students;
}

SRS::SRS(const SRS & srsToCopy){
		studentNo = srsToCopy.studentNo;
		if (studentNo > 0)
			students = new Student[studentNo];
		else
			students = NULL;
		for (int i = 0; i < studentNo; i++) {
			students[i] = srsToCopy.students[i];
		}
}

void SRS::operator=(const SRS & right) {
	if (&right != this) {
		if (studentNo != right.studentNo) {
			if (studentNo > 0)
				delete [] students;
			studentNo = right.studentNo;
			if (studentNo > 0)
				students = new Student[studentNo];
			else
				students = NULL;
		}
		for (int i = 0; i < studentNo; i++)
			students[i] = right.students[i];
	}
}

bool SRS::addStudent(const int studentId, const string studentName)
{
	bool exist = false;
	for (int i = 0; i < studentNo; i++) {
		if (students[i].getStudentId() == studentId)
			exist = true;
	}
	if (exist) {
		return false;
	}
	else {
		Student newStudent(studentId, studentName);
		Student * newStudents = new Student[studentNo+1];
		for (int k = 0; k < studentNo ; k++) {
			newStudents[k] = students[k];
		}
		newStudents[studentNo] = newStudent;
		studentNo = studentNo + 1;
		Student * temp = students;
		students = newStudents;
		delete[] temp;
		return true;
	}
}

bool SRS::removeStudent(const int studentId)
{
	bool exist = false;
	int count = 0;
	for (int i = 0; i < studentNo; i++) {
		count++;
		if (students[i].getStudentId() == studentId) {
			exist = true;
			break;
		}
	}
	if (exist) {
		
		if (studentNo == 1){
			delete [] students;
			students = NULL;
			return true;
		}
		else {
			Student * newStudents = new Student[studentNo - 1];
			int size = 0;
			for (int k = 0; k < count-1; k++)
				newStudents [size++] = students [k];
			for (int i = count; i < studentNo; i++)
				newStudents [size++] = students [i];
			studentNo = studentNo - 1;
			Student * temp = students;
			students = newStudents;
			delete[] temp;
			return true;
		}

	}
	else 
		return false;
}

int SRS::getStudents(Student *& allStudents)
{
	int studentNum = this -> studentNo;
	allStudents = new Student[studentNum];
	for (int i = 0; i < studentNum; i++) {
		allStudents [i] = students[i];
	}
	return studentNum;
}
