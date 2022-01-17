#include<iostream>
#include<string>
#include <iomanip>
#define M 10

using namespace std;

class Student{
    public:
        int student_id;
        char name[30];
        int marks;
        void getData(){
            cout<<"Enter student number\t";
            cin>>student_id;
            cin.clear();
            cin.sync();
            cout<<"Enter Name of student"<<endl;
            cin.getline(name,30);
            cout<<"Enter Marks\t";
            cin>>marks;
        }
        void putData(){
            cout<<left<<"|"<<setw(15)<<student_id<<"|"<<setw(15)<<name<<"|"<<setw(15)<<marks<<"|"<<endl;
        }
};

int main(){
    Student arr[M];
    cout<<"Enter details:\n";
    for(int i=0;i<M;i++){
        cout<<"Enter data for student "<<i+1<<endl;
        arr[i].getData();
    }
    cout<<"Student Details:\n"<<
      "_________________________________________________\n|Student Number |Name           |Marks          |\n_________________________________________________\n";
    for(int i=0;i<M;i++){
        arr[i].putData();
        cout<<"_________________________________________________\n";
    }
    return 0;
}
