# include <iostream>
using namespace std;
#include <string>
#include<cstdlib>

int main()
{
	for(int i=0;i<6;i++)
	{
		cout<<i<<"\n";
		if(i%2)
		{
			if(i==3)
			{
				continue;
			}
			cout<<"i%2==0\n";
		}
	}
}	
