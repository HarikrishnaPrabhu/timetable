#include "timetable.h"

/*
Algorithm:
	//Need to write search methods according to some criteria for both teachers and Courses	
	Three Semesters. Each sem has three sections .
	Global: search for lab hours, allocate all of them.(Max of two sections in the lab)(Have to do fro all three sems before other subjects-> Randomize the sem chosen)		
	Lets go in order i.e 3,5,7 or 4,6,8	
	1. First fetch all courses pertaining to the current sem.
	2. Fetch corresponding teachers.
	3. Search the courses for a common course. If found, allocate required hours to it. (how?)
	4. Use the same algo as the one used for the python project . ALso include checks to the other semester's timetable to see that the teachers don't clash. Make sure the constraints are not violated. 
	5. May need to check previous hour because of constraint validation.(In case of no continuos hours)
*/


/*
one array for each section of a semester
	each array will have 6 arrays which contain pointers to integer pointers which point to values
	of courseid and the corresponding teacher who handles the course at that hour of the week
*/
//Global variable declarations
const int sem=4;
Teacher *tarr;
Course  *carr;
struct field *a1[6];
struct field *a2[6];
struct field *a3[6];
struct field *b1[6];
struct field *b2[6];
struct field *b3[6];
struct field *c1[6];
struct field *c2[6];
struct field *c3[6];

//Allocates memory for each array passed to it.
void alloc(struct field *x[6])
{
	for(int i=0;i<6;i++)//6 days per week
	{
		//x[i]=(struct field *)malloc(sizeof(struct field *)*6);
		x[i]=new field[6];
	}
}

void display_timetable()
{
	struct field **b[]={a1,a2,a3,b1,b2,b3,c1,c2,c3};
	for(int k=0;k<9;k++)
	{
		for(int i=0;i<5;i++)
		{
			for(int j=0;j<6;j++)
			{
				cout<<i<<":"<<j<<" "<<b[k][i][j].cid<<"\t";
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
}

//This method calls the allocation method which allocates space to hold the
//teacher,course pairs which are later used to render the entire timetable.
//There is one array for each of the sections in the 3 years for which the timetables
//are being generated.
void create()
{
	alloc(a1);
	alloc(a2);
	alloc(a3);
	alloc(b1);
	alloc(b2);
	alloc(b3);
	alloc(c1);
	alloc(c2);
	alloc(c3);
}
//This method is used to call the functions that allocate courses to the sections
//by preference of the function call made.Each function call made here allocates
//some classes to each of the sections.

int getLabCount(int sem)
{
	int count = 0;
	for(int i=0;i<Course::getCount();i++)
	{
		if(carr[i].getSem() == sem && carr[i].isLab())
		{
			//carr[i].display();
			count++;
		}
	}
	return count;
}

int getFixedCount(int sem)
{
	int count = 0;
	for(int i=0;i<Course::getCount();i++)
	{
		if(carr[i].getSem() == sem && carr[i].isfixed())
		{
			//courses[i].display();
			++count;
		}
	}
	return count;
}

Course* getLabs(int sem)
{
	int cur = 0;
	int no_lab = getLabCount(sem);
	Course *ptr=new Course[no_lab];
	cur=0;
	for(int i=0;i<Course::getCount() && cur<no_lab;i++)
	{
		if(carr[i].getSem() == sem && carr[i].isLab())
		{
			//carr[i].display();
			ptr[cur++]=carr[i];
		}	
	}
	return ptr;
}

Course& getCoursebyid(string courseid)
{
	Course temp;
	//cout<<"in method getcourse\n";
	for(int i=0;i<Course::getCount();++i)
	{
		
		if(carr[i].getCourseId() == courseid)
		{
			//cout<<courseid<<":"<<carr[i].getCourseId()<<"\n";
			return carr[i];
		}
	}

}


bool course_done_for_day(struct field *x,Course *c)
{
	bool islab = c->isLab();
	bool isfixed = c->isfixed();
	for(int i=0;i<6;++i)
	{
		if(x[i].cid=="\0")
		{
			return false;
		}
		else
		{
			Course &temp = getCoursebyid(x[i].cid);
			bool flag_lab = islab && temp.isLab();
			bool flag_fixed = isfixed && temp.isfixed(); 
			//if(x[i].cid==(*c).getCourseId() || (islab && (getCoursebyid(x[i].cid)).isLab()))
			if(x[i].cid==c->getCourseId() || flag_lab || flag_fixed)
			{
				//cout<<c->getCourseId()<<"\n";
				return true;
			}
		}
	}
	return false;
}

void find_free(struct field *x[],Course *c)
{
	int i,j;
	int hr_inc=1;
	for(i=0;i<5;i++)
	{
		
		if(course_done_for_day(x[i],c))
		{
			//cout<<i<<"\n";
			continue;
		}
		else
		{
			if(c->isLab() || c->isfixed())
				hr_inc=2;
			for(j=0;j<6;j+=hr_inc)
			{
				if(!x[i][j].done)
				{
					x[i][j].cid=c->getCourseId();
					x[i][j].done=1;
					if(hr_inc==2)
					{
						x[i][j+1].cid=c->getCourseId();
						x[i][j+1].done=1;
					}
					return;
				}
			}
		}
		//display_timetable();
	}
}


Course* findfixed(int sem)
{
	int fixed_count = getFixedCount(sem);
	int cur=0;
	
	//cout<<"Count:"<<count<<"\n";
	Course *fixed_courses = new Course[fixed_count];
	for(int i=0;i<Course::getCount() && cur<fixed_count ;i++)
	{
		if(carr[i].getSem() == sem && carr[i].isfixed())
		{
			fixed_courses[cur++] = carr[i];
			
		}
	}
	return fixed_courses;	
}

void course_alloc(struct field *x[],struct field *y[],struct field *z[],Course *c)
{
	int i=0,rand,free;
	srand(time(NULL));
	rand=random()%3;
	int prev_rand = rand;
	while(i<3)//all 3 sections..randomize as to not give any section the first preference
	{
		if(rand==0)
		{
			find_free(x,c);
			rand ++;
		}
		else if(rand==1)
		{
			find_free(y,c);
			rand=(prev_rand==2?0:2);
			prev_rand=1;
		}
		else
		{
			find_free(z,c);
			rand = (prev_rand==1?0:1);
		}
		
		i++;
	}
	//display_timetable();
}


void alloc_lab()
{
	//Use random function to determine from which section we start to
	//allocate the lab hours from. This makes the preference selection
	//process fair and unbiased to all sections and semesters.
	int i,j,cur_sem=sem;
	int lab_count=0;
	Course *c;
	
	struct field **b[]={a1,a2,a3,b1,b2,b3,c1,c2,c3};
	for(i=0;i<3;i++)//each sem
	{
		c=getLabs(cur_sem);
		lab_count = getLabCount(cur_sem);
		cur_sem += 2;
		//cout <<"done********************\n";
		for(j=0;j<lab_count;j++)//each lab for that sem
		{
		//	c[j].display();
			course_alloc(b[i*3],b[i*3+1],b[i*3+2],(c+j));//get 3 sections at a time
		}
	}
	
}

void alloc_fixed()
{
	int cur_sem = sem;
	struct field **b[]={a1,a2,a3,b1,b2,b3,c1,c2,c3};
	for(int i = 0; i<3 ; ++i)
	{
		Course *fixed_courses = findfixed(cur_sem);
		int fixed_count = getFixedCount(cur_sem);
		cur_sem += 2;
		for(int j=0;j<fixed_count;++j)
		{
			course_alloc(b[i*3],b[i*3+1],b[i*3+2],(fixed_courses+j));
		}
	}
}


void process()
{
	//Now we obtain the arrays containing the course and teacher objects
	tarr=teacherInit();
	carr=courseInit();
	alloc_fixed();
	alloc_lab();
	display_timetable();
	
}
