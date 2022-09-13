#include "Task.h"
#include <string>
#include<iostream>
using namespace std;


void Task::DateFormat( string & date)
{
	bool d  ;
	if ((date == "sat" || date == "SAT")
		|| (date == "sun" || date == "SUN")
		|| (date == "mon" || date == "MON")
		|| (date == "tue" || date == "TUE")
		|| (date == "wed" || date == "WED")
		|| (date == "thu" || date == "THU"))
		d = true;
		 
	else
	{
		d = false;
		cout << "The format should be the working day name like { sat,sun ,mon,...}" << endl;
		cin >> date;
		cout << endl;
		DateFormat(date);
	}
}

void Task::readData() {

	
	cout << " Enter task employee Name : " << endl  ;
	cin >> EmpName;
	cout << endl;
	cout << " Enter task priority : " << endl  ;
	cin >> priority; 
	cout << endl;
	bool f=true;
	while (f)
	{
		if (priority < 1 || priority >10)
		{
			cout << " Please the priority should be between [1:10] " << endl << endl;
			cout << " Enter task priority : " << endl << endl;
			cin >> priority;
			cout << endl;
		}
		else f = false;
	}
	cout << " Enter task title : " << endl << endl;
	cin >> TaskTitle;
	cout << endl;
	cout << " Enter task description : " << endl << endl;
	cin >> TaskDescription;
	cout << endl;
	cout << " Enter task start date : " << endl << endl;
	cin >> AssigningDate;
	cout << endl;
	DateFormat(AssigningDate);
	cout << " Enter task end date : " << endl << endl;
	cin >> RequiredEndingDate;
	cout << endl; 
	DateFormat(RequiredEndingDate);
}

void Task::showdata() {
	
	cout << " Task Id is: " << TaskId << endl << endl;
	cout << " The employee tasked with the task: " << EmpName << endl << endl;
	cout << " Task priority: " << priority << endl << endl;
	cout << " Task Title: " << TaskTitle << endl << endl;
	cout << " Task Description: " << TaskDescription << endl << endl;
	cout << " Assigning Date: " << AssigningDate << endl << endl;
	cout << " Required Ending Date: " << RequiredEndingDate << endl << endl << endl;

}

void Task::Postpone() {
	 
	cout << " Enter a new task end date" << endl;
	cin >> newDate;
	cout << endl;
	DateFormat(newDate);
	 
		 
	if (newDate == RequiredEndingDate)
		cout << " There is no change" << endl;
	else if ((newDate == "sun" || newDate == "SUN") && (RequiredEndingDate == "sat" || RequiredEndingDate == "SAT"))
	{
		cout << " The postpone must be before the deadline " << endl;
		Postpone();
	}
	else if ((newDate == "mon" || newDate == "MON") &&
		((RequiredEndingDate == "sat" || RequiredEndingDate == "SAT") ||
			(RequiredEndingDate == "sun" || RequiredEndingDate == "SUN")))
	{
		cout << " The postpone must be before the deadline " << endl;
		Postpone();
	}
	else if ((newDate == "tue" || newDate == "TUE") &&
		((RequiredEndingDate == "sat" || RequiredEndingDate == "SAT") ||
			(RequiredEndingDate == "sun" || RequiredEndingDate == "SUN") ||
			(RequiredEndingDate == "mon" || RequiredEndingDate == "MON")))
	{
		cout << " The postpone must be before the deadline " << endl;
		Postpone();
	}

	else if ((newDate == "wed" || newDate == "WED") &&
		((RequiredEndingDate == "sat" || RequiredEndingDate == "SAT") ||
			(RequiredEndingDate == "sun" || RequiredEndingDate == "SUN") ||
			(RequiredEndingDate == "mon" || RequiredEndingDate == "MON") ||
			(RequiredEndingDate == "tue" || RequiredEndingDate == "TUE")))
	{
		cout << " The postpone must be before the deadline " << endl;
		Postpone();
	}
	else if (newDate == "thu" || newDate == "THU")
	{
		cout << " You can't postpone to the last day of the week"<<endl;
		Postpone();
	}
	else if ((RequiredEndingDate == "thu" || RequiredEndingDate == "THU"))
		cout <<  " You can't postpone after this deadline ";
	else
	{
		DateFormat(newDate);
		RequiredEndingDate = newDate;
		cout << " The task postponed successfully" << endl;
	}
	}

 void Task::Edit_task()
 {
	 bool flag = true;
	 char choice = -1;
	 
	 string NewEmp, NewDiscriptoin, NewTitle;
	 while (flag)
	 {
		 cout << " To change task employee Name press 1 " << endl <<
			 " To change task title press 2 " << endl <<
			 " To change task discription press 3 " << endl
			 << " To end task editing press 0 ";
		 cin >> choice;
		 cout << endl;

		 if (choice == '1')
		 {
			 cout << " Enter new task employee Name ";
			 cin >> NewEmp;
			 cout << endl;
			 EmpName = NewEmp;

		 }
		 else if (choice == '2')
		 {
			 cout << " Enter new task title ";
			 cin >> NewTitle;
			 cout << endl;
			 TaskTitle = NewTitle;
		 }
		 else if (choice == '3')
		 {
			 cout << " Enter new task discription ";
			 cin >> NewDiscriptoin;
			 cout << endl;
			 TaskDescription = NewDiscriptoin;
		 }
		 else if (choice == '0')
		 {
			 cout << " Data changed successfully";
			 flag = false;
			 break;

		 }
		 else
		 {
			 cout << " Enter a valid number " << endl;

		 }

	 }
 }



 


 