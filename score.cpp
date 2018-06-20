#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

struct Student
{
	string name;
	string sex;
	double score;
	bool operator<(const Student S)const
	{
		return score<S.score||(score==S.score&&name<S.name);
	}
};

double average1(Student* student,int n)
{
	double sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=student[i].score;
	}
	return sum/n;
}

double average2(Student* student,int n)
{
	double sum=0;
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(student[i].sex=="male")
		{
			sum+=student[i].score;
			j++;
		}
	}
		return sum/j;
}

int main()
{
	Student student[100];
	int i=0;
	ifstream fin("score.csv");
	while(!fin.eof())
	{
		getline(fin,student[i].name,',');
		fin.get();
		getline(fin,student[i].sex,',');
		fin.get();
		fin>>student[i].score;
		fin.get();
		i++;
	}
	sort(student,student+i+1);
	cout<<"Average: "<<average1(student,i+1)<<endl;
	cout<<"Male Average: "<<average2(student,i+1)<<endl;
	for(int j=0;j<=i;j++)
	{
		cout<<student[j].score<<endl;
	}
	return 0;
}
