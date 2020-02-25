#include "Student.h"

Student::Student(const int sid, const string sname)
{
	studentId = sid;
	studentName = sname;
	courses = NULL;
	courseNo = 0;

}

Student::~Student()
{
	if (courseNo>0 && courses != NULL)
		delete [] courses;
}

Student::Student(const Student & studentToCopy)
{
	studentId = studentToCopy.studentId;
	studentName = studentToCopy.studentName;
	courseNo = studentToCopy.courseNo;
	if (courseNo > 0)
		courses = new Course[courseNo];
	else
		courses = NULL;
	for (int i = 0; i < courseNo; i++) {
		courses[i] = studentToCopy.courses[i];
	}
}

void Student::operator=(const Student & right)
{
	studentId = right.studentId;
	studentName = right.studentName;
	if (&right != this) {
		if (courseNo != right.courseNo) {
			if (courseNo > 0)
				delete[] courses;
			courseNo = right.courseNo;
			if (courseNo > 0)
				courses = new Course [courseNo];
			else
				courses = NULL;
		}
		for (int i = 0; i < courseNo; i++)
			courses[i] = right.courses[i];
	}
}

int Student::getStudentId()
{
	return studentId;
}

string Student::getStudentName()
{
	return studentName;
}

double Student::calculateStudentCurrentGPA()
{
	double GPA = 0;
	int totalCredit = 0;
	double totalPoint = 0;
	if (courses != NULL) {
		for (int i = 0; i < courseNo; i++) {
			string grade = courses[i].getCourseGrade();
			if (grade != "W" ) {
				totalCredit += courses[i].getCourseCredit();
			}
			if (grade == "A+")
				totalPoint += (4 * courses[i].getCourseCredit());
			else if (grade == "A")
				totalPoint += (4 * courses[i].getCourseCredit());
			else if (grade == "A-")
				totalPoint += (3.7 * courses[i].getCourseCredit());
			else if (grade == "B+")
				totalPoint += (3.3 * courses[i].getCourseCredit());
			else if (grade == "B")
				totalPoint += (3 * courses[i].getCourseCredit());
			else if (grade == "B-")
				totalPoint += (2.7 * courses[i].getCourseCredit());
			else if (grade == "C+")
				totalPoint += (2.3 * courses[i].getCourseCredit());
			else if (grade == "C")
				totalPoint += (2 * courses[i].getCourseCredit());
			else if (grade == "C-")
				totalPoint += (1.7 * courses[i].getCourseCredit());
			else if (grade == "D+")
				totalPoint += (1.3* courses[i].getCourseCredit());
			else if (grade == "D")
				totalPoint += (1 * courses[i].getCourseCredit());
			else if (grade == "F" || grade == "FX" || grade == "FZ")
				totalPoint += (0 * courses[i].getCourseCredit());

		}
		GPA = totalPoint / totalCredit;
		return GPA;
	}
	else
		return 0;
}


int Student::getCourseNo()
{
	return courseNo;
}

void Student::setCourseNo(int num)
{
	courseNo = num;
}

void Student::setCourses (Course *& coursesNew)
{
	courses = coursesNew;
}

Course * Student::getCourses()
{
	return courses;
}
