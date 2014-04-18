#include"timetable.h"

CourseConst::CourseConst()
{
}
 	
CourseConst::CourseConst(string id, bool common, bool lab)
:courseid_(id), common_(common), lab_(lab)
{
}

CourseConst::CourseConst(CourseConst& rhs)
{
	courseid_= rhs.courseid_;
	common_= rhs.common_;
	lab_= rhs.lab_;	
}

bool CourseConst::isfixed() const
{
	return this->common_;
}
bool CourseConst::isLab() const
{
	return this->lab_;
}
string CourseConst::getCourseId() const
{
	return this->courseid_;
}

