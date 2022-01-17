#include<iostream>
#include<vector>
#include<string>
#include <iomanip>
#include<vector>

using namespace std;

class Student{
    private:
        string name;
        string _class;
        string roll_num;
        int num;
        string *subject_code;
        string *subject_name;
        float *marks;
        float max_marks;
    public:
        
        Student() {}

        Student(string na,string cl,string r_n,int n, string s_c[],string s_n[], float m[]){
            name=na;
            _class=cl;
            roll_num=r_n;
            num=n;
            subject_code=s_c;
            subject_name=s_n;
            marks=m;
            max_marks=-1;
            for(int i=0;i<num;i++){
                if(max_marks<marks[i]) max_marks=marks[i];
            }
        }
        void marksheet(){
            cout<<"Name: "<<name<<"\nRoll Number: "<<roll_num<<"\nClass: "<<_class<<endl;
            cout<<"-------------------------------------------\n";
            cout<<"| Subject code| Subject Name| Marks| Grade|\n";
            cout<<"-------------------------------------------\n";
            for(int i=0;i<num;i++){
                cout<<"| "<<setw(12)<<subject_code[i]<<"| "<<setw(12)<<subject_name[i]<<"| "<<setw(5)<<marks[i]<<"| "<<setw(5)<<grade(marks[i])<<"|\n";
            }
            cout<<"-------------------------------------------\n";
            cout<<"Max_marks: "<<max_marks<<endl;
            cout<<"Net Grade: "<<grade(total(marks,num)/num)<<endl;
        }

        float total(float m[],int n){
            float sum=0;
            for(int i=0;i<n;i++) sum+=m[i];
            return sum;
        }

        string grade(float m){
            if(m>=75) return "A";
            else if(m<75 && m>=60) return "B";
            else if(m<60 && m>=45) return "C";
            else if(m<45 && m>=35) return "D";
            return "F";
        }
};

int main(){
    int n;
    cout<<"Enter Number of students:\t";
    cin>>n;
    Student arr[100];
    for(int i=0;i<n;i++){
        string name,clas,r_n,s_c[20],s_n[20]; int num; float m[20];
        cout<<"Enter Name and Roll Number of student:\t";
        cin>>name>>r_n;
        cout<<"Enter Class of student:\t";
        cin>>clas;
        cout<<"Enter Number of subjects:\t";
        cin>>num;
        cout<<"Enter the Subject codes, Subject Name, marks obtained\n";
        for(int j=0;j<num;j++) cin>>s_c[j]>>s_n[j]>>m[j];
        Student s(name,clas,r_n,num,s_c,s_n,m);
        cout<<endl;
        s.marksheet();
    }
    return 0;
}