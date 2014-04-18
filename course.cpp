#include"timetable.h"

int Course::count=0;

Course::Course()
{
}

Course::Course(CourseConst &con, string id, string name, int credits,int sem)
:con_(con),courseid_(id), coursename_(name), credits_(credits),sem_(sem)
{
	++count;
}
int Course::getCount()
{
	return count;
}

int Course::getSem() const
{
	return this->sem_;
}

string Course::getCourseId() const
{
	return this->courseid_;
}

bool Course::isLab() const
{
	return this->con_.isLab();
}

bool Course::isfixed() const
{
	return this->con_.isfixed();
}
void Course::display() const
{
	cout << "Course id: " << courseid_ << endl;
	cout << "Course name: " << coursename_ << endl;
	cout << "Credits: " << credits_ << endl;
	cout << "Sem: " << sem_ << endl;	
}


