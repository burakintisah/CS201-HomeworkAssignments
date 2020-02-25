#include "SRS.h"
#include "Student.h"
#include "Course.h"

SRS::SRS()
{
	students = NULL;
	studentNo = 0;
}

SRS::~SRS()
{
	delete[] students;
}

SRS::SRS(const SRS & srsToCopy)
{
	studentNo = srsToCopy.studentNo;
	if (studentNo > 0) 
		students = new Student[studentNo];
	else
		students = NULL;
	for (int i = 0; i < studentNo; i++) {
		students[i] = srsToCopy.students[i];
	}
}

void SRS::operator=(const SRS & right)
{
	if (&right != this) {
		if (studentNo != right.studentNo) {
			if (studentNo  > 0)
				delete[] students;
			studentNo = right.studentNo;
			if (studentNo  > 0)
				students = new Student [studentNo];
			else
				students = NULL;
		}
		for (int i = 0; i < studentNo; i++)
			students [i] = right.students[i];
	}
}

int SRS::getStudents(Student *& allStudents)
{
	int studentNum = this->studentNo;
	allStudents = new Student[studentNum];
	for (int i = 0; i < studentNum; i++) {
		allStudents[i] = students[i];
	}
	return studentNum;
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
		Student * newStudents = new Student[studentNo + 1];
		for (int k = 0; k < studentNo; k++) {
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
	int count = -1;
	for (int i = 0; i < studentNo; i++) {
		count++;
		if (students[i].getStudentId() == studentId) {
			exist = true;
			break;
		}
	}
	if (exist) {

		if (studentNo == 1) {
			delete[] students;
			students = NULL;
			return true;
		}
		else {
			Student * newStudents = new Student [studentNo - 1];
			int size = 0;
			for (int k = 0; k < count ; k++)
				newStudents[size++] = students[k];
			for (int i = count + 1 ; i < studentNo; i++)
				newStudents[size++] = students[i];
			studentNo = studentNo - 1;
			delete [] students;
			students = newStudents;
			return true;
		}

	}
	else
		return false;
}

bool SRS::addCourse(const int studentId, const int courseId, const string courseGrade, const int courseCredit)
{
	bool stuExist = false;
	bool courExist = false;
	bool gradeFails = false;
	int indexOfStudent = -1;
	for (int i = 0; i < this->studentNo; i++) {
		indexOfStudent++;
		if (students[i].getStudentId() == studentId) {
			stuExist = true;
			int corsNum = students[i].getCourseNo();
			if (corsNum > 0) {
				for (int k = 0; k < corsNum; k++) {
					int courseIDcheck = (students[i].getCourses() + k)->getCourseId();
					if (courseIDcheck == courseId) {
						courExist = true;
						break;
					}
				}
			}
			else
				courExist = false;
			break;
		}
	}
	if (courseGrade == "A+")
		gradeFails = true;
	else if (courseGrade == "A")
		gradeFails = true;
	else if (courseGrade == "A-")
		gradeFails = true;
	else if (courseGrade == "B+")
		gradeFails = true;
	else if (courseGrade == "B")
		gradeFails = true;
	else if (courseGrade == "B-")
		gradeFails = true;
	else if (courseGrade == "C+")
		gradeFails = true;
	else if (courseGrade == "C")
		gradeFails = true;
	else if (courseGrade == "C-")
		gradeFails = true;
	else if (courseGrade == "D+")
		gradeFails = true;
	else if (courseGrade == "D")
		gradeFails = true;
	else if (courseGrade == "F" || courseGrade == "FX" || courseGrade == "FZ")
		gradeFails = true;
	else if (courseGrade == "W")
		gradeFails = true;

	if (stuExist && !courExist && gradeFails) {
		Course courseNew;
		courseNew.setCourseCredit(courseCredit);
		courseNew.setCourseId(courseId);
		courseNew.setCourseGrade(courseGrade);

		int courseNum = students[indexOfStudent].getCourseNo() + 1;
		Course * coursesArray = new Course[courseNum];
		Course * oldCourses = students[indexOfStudent].getCourses() ;
		
		for (int i = 0; i < courseNum - 1; i++) {
			coursesArray[i] = oldCourses[i];
		}
		coursesArray[courseNum - 1] = courseNew;
		delete [] oldCourses;
		oldCourses = NULL;
		students[indexOfStudent].setCourses(coursesArray);
		students[indexOfStudent].setCourseNo(courseNum);
		return true;

	}
	else
		return false;
}

bool SRS::removeCourse(const int studentId, const int courseId)
{
	bool stuExist = false;
	bool courExist = false;
	int indexOfStudent = -1;
	int indexOfCourse = -1; 
	for (int i = 0; i < this->studentNo; i++) {
		indexOfStudent++;
		if (students[i].getStudentId() == studentId) {
			stuExist = true;
			for (int k = 0; k < students[i].getCourseNo(); k++) {
				int courseIDcheck = (students[i].getCourses() + k)->getCourseId() ;
				if (courseIDcheck == courseId) {
					indexOfCourse++;
					courExist = true;
					break;
				}
			}
			break;
		}
	}
	
	if (stuExist && courExist ) {
		int courseNum = students[indexOfStudent].getCourseNo() - 1;
		Course * oldCourses = students[indexOfStudent].getCourses();
		if (courseNum > 0) {
			Course * coursesArray = new Course[courseNum];

			int ind = 0;
			for (int i = 0; i < indexOfCourse; i++) {
				coursesArray[ind++] = oldCourses[i];
			}
			for (int k = indexOfCourse + 1 ; k < courseNum + 1; k++) {
				coursesArray[ind++] = oldCourses[k];
			}

			delete[] oldCourses;
			students[indexOfStudent].setCourses(coursesArray);
			students[indexOfStudent].setCourseNo(courseNum);
			return true;
		}
		else if (courseNum == 0) {
			delete[] oldCourses;
			students[indexOfStudent].setCourseNo(courseNum);
			return true;
		}
	}
	else
		return false;
}

double SRS::calculateCourseGPA(const int courseId)
{
	double GPA = 0;
	double totalPoint = 0;
	int total = 0;
	for (int i = 0; i < studentNo; i++) {
		Course * temp = students[i].getCourses();
		for (int k = 0; k < students[i].getCourseNo(); k++) {
			if (temp[k].getCourseId() == courseId) {
				string tempGrade = temp[k].getCourseGrade();
				if (tempGrade != "W" && tempGrade != "FZ" && tempGrade != "FX") {
					total++;
				}
				if (tempGrade == "A+")
					totalPoint += 4 ;
				else if (tempGrade == "A")
					totalPoint += 4 ;
				else if (tempGrade == "A-")
					totalPoint += 3.7 ;
				else if (tempGrade == "B+")
					totalPoint += 3.3;
				else if (tempGrade == "B")
					totalPoint += 3 ;
				else if (tempGrade == "B-")
					totalPoint += 2.7 ;
				else if (tempGrade == "C+")
					totalPoint += 2.3 ;
				else if (tempGrade == "C")
					totalPoint += 2;
				else if (tempGrade == "C-")
					totalPoint += 1.7 ;
				else if (tempGrade == "D+")
					totalPoint += 1.3;
				else if (tempGrade == "D")
					totalPoint += 1 ;
				else if (tempGrade == "F" )
					totalPoint += 0 ;
			}
		}
	}
	if (total != 0) {
		GPA = totalPoint / total;
		return GPA;
	}
	else
		return 0;
		
}
