#pragma once
#include <string>
using namespace std;

class Task
{
public :
	int TaskId;
	int  priority;
	string EmpName;
	string TaskTitle;
	string TaskDescription;
	string AssigningDate;
	string RequiredEndingDate, newDate;
	void DateFormat(string& date);
	void readData();
	void showdata();
	void Postpone();
	void Edit_task();
	

};

