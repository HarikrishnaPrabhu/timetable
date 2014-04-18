#include"timetable.h"

Teacher::Teacher()
{
}

Teacher::Teacher(TeacherConst& con,int id, string name, string courseid, int hrs)
:con_(con),teacherid_(id), name_(name), courseid_(courseid), hrs_(hrs)
{
}

void Teacher::display() const
{
	cout << "Teacher id: " << teacherid_ << endl;
	cout << "Teacher name: " << name_ << endl;
	cout << "Course: " << courseid_ << endl;
	cout << "Hrs: " << hrs_ << endl;
	con_.display();	
}


