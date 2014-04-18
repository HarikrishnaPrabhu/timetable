#include "timetable.h"

template <typename ptr_t>
void display(ptr_t begin,ptr_t end)
{
	while(begin!=end)
	{
		cout<<*begin++<<"\t";
	}
	cout<<"\n";
}

//Running into infinite loop
vector<string> split(string str, string delim)
{ 
      int start = 0;
      int end; 
      vector<string> v; 

      while( (end = str.find(delim, start)) != string::npos )
      { 
            v.push_back(str.substr(start, end-start)); 
            start = end + delim.length(); 
      } 
      v.push_back(str.substr(start)); 
      
      return v; 
}


//Function to get number of records in file denoted by fname
int get_num_rec(string fname)
{
	int len = 0;
	string line;
	ifstream myfile (fname.c_str());
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			++len;
		}
		myfile.close();
	}
	return len;

}

CourseConst* CourseConstInit()
{
	string line;
	int idx = 0;
	string fname = "Courseconst.txt";
	int num_rec = get_num_rec(fname);
	//Course *arr=(Course *)malloc(sizeof(Course)*num_rec);
	CourseConst *arr=new CourseConst[num_rec];	
	ifstream myfile(fname.c_str());
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			vector<string> x = split(line, ";");
			//display(x.begin(),x.end());			
			bool common = (x[1]=="true");
			bool lab = (x[2]=="true");
			CourseConst c(x[0], common , lab);	//Course object!
			arr[idx++] = c;
		}
		myfile.close();
	}
	else cout << "Unable to open file"; 
	return arr;
}

TeacherConst* TeacherConstInit() 
{
	string line;
	int idx = 0;
	string fname = "TeacherConst.txt";
	int num_rec = get_num_rec(fname);
	TeacherConst *arr=new TeacherConst[num_rec];	
	ifstream myfile(fname.c_str());
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			vector<string> x = split(line, ";");
			//display(x.begin(),x.end());
			int id = atoi(x[0].c_str());
			string d_avail = x[1];
			string h_avail = x[2];
			int conti= atoi(x[3].c_str());
			TeacherConst t(id, d_avail , h_avail, conti);	//Course object!
			arr[idx++] = t;
		}
		myfile.close();
	}
	else cout << "Unable to open file"; 
	return arr;
}


//TeacherID;
Teacher *teacherInit()
{
	int idx(0);
	string fname("teacherinfo.txt");
	string line;
	vector <string> fields;
	int num_rec = get_num_rec(fname);
	//Teacher *arr=(Teacher *)malloc(sizeof(Teacher)*num_rec);
	Teacher *arr=new Teacher[num_rec];	
	ifstream myfile (fname.c_str());
	TeacherConst *cont = TeacherConstInit();
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
		//	cout <<line<<"\n";
			vector<string> x = split(line, ";");
			//display(x.begin(),x.end());
			int id = atoi(x[0].c_str());
			int hrs = atoi(x[3].c_str());
			
			TeacherConst con;
			for(int i=0;i<num_rec;i++)
			{
				if(id==cont[i].getTeacherId())
				{
					con=cont[i];
					break;
				}
			}
			Teacher t(con, id, x[1], x[2], hrs);
			arr[idx++] = t;
		}
		myfile.close();
	}
	else cout << "Unable to open file"; 
	return arr;
}

//CourseCode;CourseName;Credits;Semester
Course *courseInit()
{
	string line;
	int idx = 0;
	string fname = "courseinfo.txt";
	int num_rec = get_num_rec(fname);
	//Course *arr=(Course *)malloc(sizeof(Course)*num_rec);
	Course *arr=new Course[num_rec];	
	CourseConst *cont = CourseConstInit();	
	ifstream myfile(fname.c_str());
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			vector<string> x = split(line, ";");
			//display(x.begin(),x.end());			
			int credits = atoi(x[2].c_str());
			int sem= atoi(x[3].c_str());
			CourseConst con;			
			for(int i=0;i<num_rec;i++)
			{
				if(x[0]==cont[i].getCourseId())
				{
					con=cont[i];
					break;
				}
			}
			Course c(con, x[0], x[1], credits, sem);	//Course object!
			//c.display();
			arr[idx++] = c;
		}
		myfile.close();
	}
	else cout << "Unable to open file"; 
	return arr;
}

