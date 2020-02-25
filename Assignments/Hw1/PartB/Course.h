#ifndef __COURSE_H
#define __COURSE_H
#include <string>
using namespace std;
class Course {
public:
	Course();
	~Course();
	Course(const Course &courseToCopy);
	void operator=(const Course &right);
	int getCourseCredit();
	string getCourseGrade();
	int getCourseId();
	
	void setCourseId(int id);
	void setCourseCredit(int credit);
	void setCourseGrade(string grade);
private:
	int courseId;
	int courseCredit;
	string courseGrade;
};
#endif