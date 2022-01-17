#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

class Employee{
    public:
        long long int employee_number;
        string name;
        int salary;
        void getData();
        void putData();
};

void Employee::getData(){
    cout<<"Enter employee number\t";
    cin>>employee_number;
    cin.clear();
    cin.sync();
    cout<<"Enter Name of employee"<<endl;
    getline(cin,name);
    cout<<"Enter Salary\t";
    cin>>salary;
}

void Employee::putData(){
    cout<<left<<"|"<<setw(15)<<employee_number<<"|"<<setw(15)<<name<<"|"<<setw(15)<<salary<<endl;
}

int main(){
    Employee arr[10];
    cout<<"Enter details:\n";
    for(int i=0;i<10;i++){
        cout<<"Enter data for employee "<<i+1<<endl;
        arr[i].getData();
    }
    cout<<"Employee Details:\n"<<
      "_________________________________________________\n|Employee Number|Name           |Salary         |\n_________________________________________________\n";
    for(int i=0;i<10;i++){
        arr[i].putData();
        cout<<"_________________________________________________\n";
    }
    return 0;
}