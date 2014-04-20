#include"timetable.h"

TeacherConst::TeacherConst()
{
}

TeacherConst::TeacherConst(int teacherid, string days_avail, string hrs_avail, int continuous)
:teacherid_(teacherid), days_avail_(days_avail), hrs_avail_(hrs_avail), continuous_(continuous)
{
}

TeacherConst TeacherConst::operator=(TeacherConst& rhs)
{
	this->teacherid_=rhs.teacherid_;
	this->days_avail_=rhs.days_avail_;
	this->hrs_avail_=rhs.hrs_avail_;
	this->continuous_=rhs.continuous_;
	return *this;
}

TeacherConst::TeacherConst(TeacherConst& rhs)
{
	this->teacherid_=rhs.teacherid_;
	this->days_avail_=rhs.days_avail_;
	this->hrs_avail_=rhs.hrs_avail_;
	this->continuous_ = rhs.continuous_;
}

void TeacherConst::display() const
{
	cout << "Teacher id: " << teacherid_ << endl;
	cout << "Days Available: " << days_avail_ << endl;
	cout << "Hours Available: " << hrs_avail_ << endl;
	cout << "Continuous Hours: " << continuous_ << endl;
}

int TeacherConst::getTeacherId() const
{
	return this->teacherid_;
}

string TeacherConst::getDaysAvail() const
{
	return this->days_avail_;
}

string TeacherConst::getHoursAvail() const
{
	return this->hrs_avail_;	
}

