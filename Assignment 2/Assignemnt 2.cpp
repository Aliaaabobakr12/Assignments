/*
Aliaa Abobakr Elshiekh
120210151
CSE 3
*/

#include <iostream>
using namespace std;

struct Employee {
    string name;
    int Employee_id;
    float Salary;
};

void getMaxSalary(Employee* ptr, int n) {
    int maxSalary = 0;

    for (int i = 1; i < n; i++) {
        if ((ptr + i)->Salary > (ptr + maxSalary)->Salary) {
            maxSalary = i;
        }
    }

    cout << "Employee has the Maximum Salary: " << endl;
    cout << "Name: " << (ptr + maxSalary)->name << endl;
    cout << "ID: " << (ptr + maxSalary)->Employee_id << endl;
    cout << "Salary: " << (ptr + maxSalary)->Salary << endl;
}

int main() {
    int n;
    cout << "Enter Number of Employees" << endl;
    cin >> n;
    Employee E[n];
    Employee* ptr = E;
    cout << "Enter Employees data (Name, ID, Salary)" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Employee Number:" << i + 1 << endl;
        cin >> (ptr + i) -> name >> (ptr + i)->Employee_id >> (ptr + i)->Salary;
    }
    cout << endl;
    cout << "Employees Information: Name\t ID \tSalary \n";
    for (int i = 0; i < n; i++)
        cout << "Employee " << i + 1 << ": " << (ptr + i)->name << "\t" << (ptr + i)->Employee_id << "\t" << (ptr + i)->Salary << endl;

    getMaxSalary(ptr, n);
}