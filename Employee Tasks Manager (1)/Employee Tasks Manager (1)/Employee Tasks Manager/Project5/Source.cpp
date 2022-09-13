#include <iostream>
#include<vector>
#include <algorithm>
#include "Task.h"
#include <string>
using namespace std;


vector<Task>EmpTasks;
Task t;
char choice = -1;
bool flag = true;



void UserGuide()
{
	cout << endl << " To Add A Task: Press  1 " << endl << endl;
	cout << " To Display The Sorted Priority List: press 2 " << endl << endl;
	cout << " To Update the List ( when a task is done ): Press 3 " << endl << endl;
	cout << " To Edit The Task's Priority: press 4 " << endl << endl;
	cout << " To Postpone A Task To Another Day: press 5 " << endl << endl;
	cout << " To Edit Thetask's Data: press 6 " << endl << endl;
	cout << " To exit the system : press 0 " << endl << endl;

}

void case_add()
{
	int  id;
	int  i=0, exist=-1;
	if(EmpTasks.empty())
	{
	cout << " Enter task id : " << endl << endl;
	cin >> t.TaskId;
	cout << endl;
	t.readData();
	
	
	}
	else 
	{
		cout << " Enter task id : " << endl << endl;
		cin >> id;
		cout << endl;
	for ( i = 0; i < EmpTasks.size(); i++) {
		if (EmpTasks[i].TaskId != id) {
			EmpTasks[i].readData();
			EmpTasks[i].TaskId = id;
			exist = 0;
			break;
		}
		else  exist = 1;
	}
	}

	if (exist == 1) {
		cout << " This task already exists  Please enter another task "<<endl;
		 

		case_add();
	}
	cout << " The task added successfully " << endl;
	EmpTasks.push_back(t);


	sort(EmpTasks.begin(), EmpTasks.end(), [](const Task& lhs, const Task& rhs) {
		return lhs.priority > rhs.priority;	});
}

void Deletion()
{
	if (EmpTasks.empty())
	{
		cout << "There is no task to delete";
	}  
	else {
	EmpTasks.erase(EmpTasks.begin());
	cout << " Task deleted successfully " << endl;
	if (EmpTasks.empty())
	{
		flag = false;
		cout << " **Well Done** " << endl <<
			" Doing the best at this moment puts you in the best place for the next moment " << endl;
	}

	else
		cout << " Your Next Task is : " << EmpTasks[0].TaskTitle << endl;
}
}

void Edit_proirity()
{
	if (EmpTasks.empty())
	{
		cout << " There ara no tasks to prioritize " << endl;
	}
	else {
		bool flag1 = true, flag2 = true;
		int check = 0;
		int i = 0;
		int tempid = 0;
		int Priority = 0;
		while (flag1) {
			cout << " Enter the task Id to edit task Priority " << endl;
			cin >> tempid;
			cout << endl;
			for (i = 0; i < EmpTasks.size(); i++)
			{
				if (tempid == EmpTasks[i].TaskId)
				{
					check++;
					break;
				}
			}
			if (check == 1) {
				while (flag2) {
					cout << " Enter the new Priority: ";
					cin >> Priority;
					cout << endl;
					if (1 <= Priority && Priority <= 10) {
						EmpTasks[i].priority = Priority;
						cout << " Task Priority changed successfully ";

						sort(EmpTasks.begin(), EmpTasks.end(), [](const Task& lhs, const Task& rhs) {
							return lhs.priority > rhs.priority;	});
						flag1 = false, flag2 = false;
						break;
					}
					else if (Priority < 1 || Priority >10)
					{
						cout << " The Priority should be between [1:10] " << endl;
						continue;
					}
				}
			}
			else if (check == 0)
			{
				cout << " The Id doesn't exist in the list" << endl;
				continue;
			}
		}
	}
}

void case_postpone()
{
	if (EmpTasks.empty())
	{
		cout << " There are no tasks to postpone";
	}
	else {
		bool exist = false;
		int id;
		cout << " Enter task id " << endl;
		cin >> id;
		cout << endl;
		 
		for (int i = 0; i < EmpTasks.size(); i++) {
			if (EmpTasks[i].TaskId == id) {
				EmpTasks[i].Postpone();
				exist = true;
				break;
			}
		}
		 
		if (exist == false) {
			cout << " This id not found"  ;
			cout << " Please enter correct id" << endl;
			 
			case_postpone();
		}
	}
}

void  case_Edit_task()
{


	if (EmpTasks.empty())
	{
		cout << " There are no tasks to edit data "<<endl;
	}
	else {
		bool exist = false;
		int id;
		cout << " Enter task id " << endl;
		cin >> id;
		cout << endl;
		for (int i = 0; i < EmpTasks.size(); i++) {
			if (EmpTasks[i].TaskId == id) {
				EmpTasks[i].Edit_task();
				exist = true;
				break;
			}
		}

		if (exist == false) {
			cout << " This id not found";
			cout << " Please enter correct id" << endl;
			case_Edit_task();
		}
	}
}

void display_list()
{
	if (EmpTasks.empty())
	{
		cout << " There are no tasks to display " << endl;
	}
	else {
		cout << " List of all exist tasks " << endl;
		for (int i = 0; i < EmpTasks.size(); i++)
		{

			EmpTasks[i].showdata();
		}
	}
}
	 

int main() 
{
	cout <<endl <<"    *** Welcome to Task Organizer *** "<<endl;
	
	while (flag)
	{
		UserGuide();
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case '1':
		{
			case_add();
			break;
		}
		case '2':
		{
			display_list();
			break;
		}
		case '3':
		{
			Deletion();
			 break;
		}
		case '4':
		{
			Edit_proirity();
			break;
		}
		case '5':
		{
			case_postpone();
			break;
		}
		case '6':
		{
			case_Edit_task();
			break;
		}
		case '0':
		{
			flag = false;
			cout << endl << " Thank you for using Task Organizer " << endl << endl;
			break;

		}
		default:
		{ 
			cout << " Please enter integer choice between [0:6] "<<endl;
			break;
		}
			
		}
	}

	system("pause");
	return 0;
}

