#include<iostream>    
#include<vector> 
using namespace std;
int main()
{  
	vector<int> vec {1,2,3,4,5};
	vector<int> vec2 {21,22,23,24,25};
	
	cout<<"Intially vector: ";
	for(auto i=vec.begin(); i<vec.end(); i++)
	{
		cout<<" "<<*i;
	}
	
        //Inserting 10 to the vector
	vec.insert(vec.begin(),10);  
	
	cout<<"\n\nThe modified vector is: ";
	for(auto i=vec.begin(); i<vec.end(); i++)
	{
		cout<<" "<<*i;
	}

        //Inserting 100, 3 times to the vector
	vec.insert(vec.end(),3,100); 

	cout<<"\n\nThe modified vector is: ";
	for(auto i=vec.begin(); i<vec.end(); i++)
	{
		cout<<" "<<*i;
	}

	//Inserting vec2 at the beginning of the vec vector
	vec.insert(vec.begin(),vec2.begin(),vec2.end());
	
	cout<<"\n\nThe modified vector is: ";
	for(auto i=vec.begin(); i<vec.end(); i++)
	{
		cout<<" "<<*i;
	}
	return 0;
}