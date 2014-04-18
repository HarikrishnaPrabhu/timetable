#ifndef TIMETABLE_H
//AGJ: <Please use these>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;
#define TIMETABLE_H

class TeacherConst
{
	public:
	TeacherConst();
	TeacherConst(int,string,string,int continuous);
	TeacherConst(TeacherConst&);
	void display() const;
	int getTeacherId() const;
	friend class Teacher;
	private:
	int teacherid_;
	string days_avail_;
	string hrs_avail_;
	int continuous_;//yes, no, i don't give a damn
};

class CourseConst
{
	public:
	CourseConst();
	CourseConst(string,bool,bool);
	CourseConst(CourseConst&);
	string getCourseId() const;
	bool isfixed() const;
	bool isLab() const;
	friend class Course;
	private:
	string courseid_;
	bool common_;
	bool lab_;
		
};

class Teacher
{
	public:
	Teacher();
	Teacher(TeacherConst&,int,string,string,int);
	void display() const;
	int getTeacherId() const;
	private:
	int teacherid_;
	string name_;
	string courseid_;
	int hrs_;
	TeacherConst con_;
};
	
class Course
{
	public:
	Course();
	Course(CourseConst&, string, string, int, int);
	void display() const;
	int getSem() const;
	bool isfixed() const;
	bool isLab() const;
	string getCourseId() const;
	static int getCount();
	private:
	CourseConst con_;
	string courseid_;
	string coursename_;	
	int credits_;
	int sem_;
	static int count;
};


struct field
{
	string cid;
	int tid;
	bool done;
};

//teacherInit method parses the contents of the teacher file and fetches the fields
//in each record.These fields are then used to create objects of type teacher, which
//are stored together in an array.
Teacher *teacherInit();
Course *courseInit();
void create();
void process();
#endif
