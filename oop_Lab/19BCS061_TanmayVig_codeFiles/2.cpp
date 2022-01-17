#include <bits/stdc++.h>
using namespace std;
class Student {
    public:
        string name;
        int _class, rollNum, totalSubjects;
        string subjectNames[100], subjectCodes[100];
        int marks[100], maxMarks[100]; 
// Default Constructor
    Student() {
    this->name="";
    this->_class=0;
    this->rollNum=0;
    }
// Parameterized Constructor
    Student(string name, int _class, int rollNum) {
        this->name=name;
        this->_class=_class;
        this->rollNum=rollNum;
    }
// Student data setter, in case of default constructor
    void setStudentData(string name, int _class, int rollNum) {
        this->name=name;
        this->_class=_class;
        this->rollNum=rollNum;
    }
    void setData() {
        int n;
        cout << "Enter the number of subjects" << endl;
        cin >> n;
        this->totalSubjects = n;
        for(int i=0;i<n;i++) {
            string subName, subCode;
            int marks, maxMarks;
            cout << "Enter the name, code, marks and max marks for subject " << i+1 << endl;
            cin >> subName;
            cin >> subCode;
            cin >> marks;
            cin >> maxMarks;
            this->subjectNames[i] = subName;
            this->subjectCodes[i] = subCode;
            this->marks[i] = marks;
            this->maxMarks[i] = maxMarks;
        }
    }
    void getData() {
        cout << "Subject wise marks of " << this->name << " are" <<endl;
        cout << "Name\t\t" << "Code\t\t" << "Max Marks\t\t" << "Marks Obtained" << endl;
        int totalMarks = 0, totalMaxMarks = 0;
        double avg;
        for(int i=0;i<this->totalSubjects;i++) {
            cout << this->subjectNames[i] << "\t\t" << this->subjectCodes[i] << "\t\t" << this->maxMarks[i] << "\t\t\t" << this->marks[i] << endl;
            totalMarks += this->marks[i];
            totalMaxMarks += this->maxMarks[i];
        }
        avg = ((double)totalMarks/(double)totalMaxMarks)*100.0;
        cout << endl << "Grade of student " << this->name << " is: ";
        if(avg >= 75.0) cout << "A" << endl << endl;
        else if(avg >= 60.0) cout << "B" << endl << endl;
        else if(avg >= 45.0) cout << "C" << endl << endl;
        else if(avg >= 35.0) cout << "D" << endl << endl;
        else cout << "F" << endl << endl;
    }
};
int main() {
    cout << "Enter the number of students" << endl;
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        string name;
        int _class, rollNum;
        cout << "Enter the name, class and roll number of student " << i << endl;
        cin >> name;
        cin >> _class;
        cin >> rollNum;
        int choice;
        cout << "Enter 0 to use default constructor, 1 to use parameterized constructor" << endl;
        cin >> choice;
        if(choice == 0) {
            Student* student = new Student();
            student->setStudentData(name, _class, rollNum);
            student->setData();
            student->getData();
        } else {
            Student* student = new Student(name, _class, rollNum);
            student->setData();
            student->getData();
        }
    }
return 0;
}
