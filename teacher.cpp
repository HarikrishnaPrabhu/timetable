#include"timetable.h"

int Teacher::count =0;

Teacher::Teacher()
{
}

Teacher::Teacher(TeacherConst& con,int id, string name, vector<string> courseid, int hrs)
:con_(con),teacherid_(id), name_(name), courseid_(courseid), hrs_(hrs)
{
	++count;
}

vector<string> Teacher::getCourseId() const
{
	return this->courseid_;
}

int Teacher::getCount()
{
	return count;
}

template <typename ptr_t>
void display_courses(ptr_t begin,ptr_t end)
{
	while(begin!=end)
	{
		cout<<*begin++<<"\t";
	}
	cout<<"\n";
}

void Teacher::display() const
{
	cout << "Teacher id: " << teacherid_ << endl;
	cout << "Teacher name: " << name_ << endl;
	cout << "Courses: ";
	display_courses(courseid_.begin(),courseid_.end());
	cout << "Hrs: " << hrs_ << endl;
	con_.display();	
}


