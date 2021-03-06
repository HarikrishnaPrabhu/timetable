#include"timetable.h"

int Teacher::count =0;

Teacher::Teacher()
{
}

Teacher::Teacher(TeacherConst& con,string id, string name, vector<string> courseid, int hrs)
:con_(con),teacherid_(id), name_(name), courseid_(courseid), hrs_(hrs)
{
	++count;
}

Teacher Teacher::operator=(Teacher& rhs)
{
	this->con_=rhs.con_;
	this->teacherid_ = rhs.teacherid_;
	this->name_ = rhs.name_;
	this->courseid_ = rhs.courseid_;
	this->hrs_ = rhs.hrs_;
	return (*this);
}
vector<string> Teacher::getCourseId() const
{
	return this->courseid_;
}

int Teacher::getCount()
{
	return count;
}

string Teacher::getDaysAvail() const
{
	return (this->con_).getDaysAvail();
}

string Teacher::getHoursAvail() const
{
	return (this->con_).getHoursAvail();	
}

string Teacher::getTeacherId() const
{
	return this->teacherid_;
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


