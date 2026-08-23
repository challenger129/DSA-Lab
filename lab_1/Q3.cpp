#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct Employee {
    string name;
    int age;
    double salary;
};

int main() {
    cout << "Enter the number of employees: ";
    int n;
    cin >> n;
    vector<int> salaryBeforeIncrement(n,0);
    ofstream outfile("employees.txt");
    for (int i = 0; i < n; i++) {
        Employee emp;
        cout << "Enter name of employee " << i + 1 << ": ";
        cin >> emp.name;
        cout << "Enter age of employee " << i + 1 << ": ";
        cin >> emp.age;
        cout << "Enter salary of employee " << i + 1 << ": ";
        cin >> emp.salary;
        salaryBeforeIncrement[i] = emp.salary;
        outfile << emp.name << " " << emp.age << " " << emp.salary << endl;
    }
    outfile.close();

    ifstream infile("employees.txt");
    vector<Employee> employees;
    for (int i = 0; i < n; i++) {
        Employee emp;
        infile >> emp.name >> emp.age >> emp.salary;
        if (emp.salary >= 50000) {
            emp.salary *= 1.05;
        } else if (emp.salary >= 20000) {
            emp.salary *= 1.10;
        } else {
            emp.salary *= 1.15;
        }
        employees.push_back(emp);
    }
    infile.close();
    ofstream outfile2("employees.txt");
    for(int i = 0; i < employees.size(); i++) {
        outfile2 << employees[i].name << " " << employees[i].age << " " << employees[i].salary << endl;
        cout << "Change in salary of employee" << i+1 << " " << employees[i].salary - salaryBeforeIncrement[i] << endl;
    }
    outfile2.close();

    return 0;
}
