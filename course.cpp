#include"timetable.h"

int Course::count=0;

Course::Course()
{
}

Course::Course(CourseConst &con, string id, string name, int credits,int sem)
:con_(con),courseid_(id), coursename_(name), credits_(credits),sem_(sem),hours_(0)
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

bool Course::isdone() const
{
	return (this->hours_==this->credits_);
}

void Course::increment_alloc()
{
	++this->hours_;
}

void Course::display() const
{
	cout << "Course id: " << courseid_ << endl;
	cout << "Course name: " << coursename_ << endl;
	cout << "Credits: " << credits_ << endl;
	cout << "Sem: " << sem_ << endl;	
}


