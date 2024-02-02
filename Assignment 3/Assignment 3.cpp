/*
Aliaa Abobakr Ebrahim Elshiekh
120210151
CSE 3
Assignment 3
*/

/*
Linked Lists: Write and call a function that returns the 
average degree of all students in the linked list.
*/

#include<iostream>
using namespace std;

struct ListNode
{
	int id;
	string name;
	float degree;
	ListNode* next;
};

int countList(ListNode* listHead)
{
	int counter = 0;
	ListNode* nodePtr = listHead;
	while (nodePtr)
	{
		counter++;
		nodePtr = nodePtr->next;
	}
	return counter;
}

void add_to_end(ListNode*& listHead, int id, string name, float degree)
{
	ListNode* newNode, * nodePtr;
	newNode = new ListNode;
	newNode->id = id;
	newNode->name = name;
	newNode->degree = degree;
	newNode->next = NULL;
	if (!listHead)
		listHead = newNode;
	else
	{
		nodePtr = listHead;
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}

void displayList(ListNode* listHead)
{
	if (!listHead)
	{
		cout << "Empty List!" << endl;
		return;
	}
	ListNode* nodePtr = listHead;
	while (nodePtr)
	{
		cout << nodePtr->id << "\t" << nodePtr->name << "\t" << nodePtr->degree << "=>";
		nodePtr = nodePtr->next;
	}
	cout << endl;
}

float avg(ListNode* listHead) {
	/*Function to caculate the average of studetns' degrees*/
	float totalDeg = 0.0;
	int studentCount = countList(listHead);

	ListNode* nodePtr = listHead;
	while (nodePtr != NULL) {
		totalDeg += nodePtr->degree;
		nodePtr = nodePtr->next;
	}

	if (studentCount > 0) {
		return totalDeg / studentCount;
	}
	else {
		return 0.0;
	}
}

main()
{
	ListNode* Head = NULL;
	int choice;
	do
	{
		cout << endl << endl;
		cout << "--- Basic Linked List Operations ---" << endl << endl;
		cout << "\n (1) Display Linked List" << endl;
		cout << "\n (2) Add Node at End of List" << endl;
		cout << "\n (3) Calculate average students' degrees" << endl;
		cout << "\n PLEASE ENTER YOUR CHOICE: " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			displayList(Head);
			break;
		case 2:
		{
			cout << "Add a new student to the list:\n";
			displayList(Head);
			cout << "\n Please enter the student info (Id, Name, Degree):";
			int id;
			string name;
			float degree;
			cout << "Enter The Student Info: ";
			cin >> id >> name >> degree;
			add_to_end(Head, id, name, degree);
		}
		break;
		case 3:
		{
			/*Calling function in main to dispaly result*/
			cout << "The average of total dgrees of students is: " << avg(Head) << endl;
		}
		break;
		default:
			cout << "ERROR: You Entered Wrong Choice Number !!!!!!! Try Again" << endl;
			break;
		}
	} while (choice != 0);
}
