#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Employee{
    private:
        // int holidays; 
        long long int id,salary;
        string name;
        int friend find(Employee *arr[], int n, string name,long long int id, bool mode_id, bool print);
        void friend display(Employee *arr[],int , bool );
        void friend sort(Employee *arr[],int n,int form);
        void friend del(Employee *arr[], int n,int pos);
    public:
        Employee(){}
        Employee(int i, string n,long long int s){
            id = i;
            name = n;
            salary = s; 
            // holidays = h;
        }
};


int find(Employee *arr[],int n,string name,long long int id,bool mode_id, bool print){
    bool found=false;
    for(int i=0;i<n;i++){
        if((!mode_id && arr[i]->name==name) || (mode_id && arr[i]->id == id)){
            found = true; 
            if(print)display(arr,i,found);
            return i;
            break;
        }
    }
    if(!found) cout<<"No related data found.\n";
    return -1;
}

void display(Employee *arr[],int n, bool single){
    cout<<"---------------------------------------\n";
    cout<<"|id        |Name           |Salary    |\n";
    cout<<"---------------------------------------\n";
    if(single){
        cout<<left<<"|"<<setw(10)<<(*arr[n]).id<<"|"<<setw(15)<<(*arr[n]).name<<"|"<<setw(10)<<(*arr[n]).salary<<"|\n";
        cout<<"---------------------------------------\n";
    }else{
        for(int i=0;i<n;i++){
            cout<<left<<"|"<<setw(10)<<(*arr[i]).id<<"|"<<setw(15)<<(*arr[i]).name<<"|"<<setw(10)<<(*arr[i]).salary<<"|\n";
            cout<<"---------------------------------------\n";
        }
    }
}

void sort(Employee *arr[],int n,int form){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if((form == 1 && arr[j]->id>arr[j+1]->id) || (form==2 && arr[j]->name.compare(arr[j+1]->name)>0) || (form==3 && arr[j]->salary>arr[j+1]->salary)){
                Employee temp = *arr[j];
                *arr[j] = *arr[j+1];
                *arr[j+1] = temp;
            }
            
        }
    }
    display(arr,n,false);

}

void del(Employee *arr[],int n,int pos){
    for(int i=pos;i<n-1;i++){
        Employee temp = *arr[i];
        *arr[i] = *arr[i+1];
        *arr[i+1] = temp;
    }
    cout<<"Deleted\n";
}

int main(){
    int n=5;
    Employee *arr[100];
    cout<<"Enter the employee Details:\n";
    for(int i=0;i<n;i++){
        long long int id, salary; string name;
        cout<<"Enter the details of employee "<<(i+1)<<endl;
        cout<<"Enter id, name salary\n";
        cin>>id;
        cin.ignore();
        getline(cin,name);
        cin>>salary;
        arr[i] = new Employee(id,name,salary);
    }
    while(true){
        int choice=0,s=0;
        long long int id,salary;
        string name;
        cout<<"to display data of all employees Enter 1\nto display data of one employee Enter 2\nto sort data Enter 3\nto delete Enter 4\nto insert new employee Enter 5\nto exit Enter 0\n";
        cin>>choice;
        switch (choice)
        {
        case 2:
            cout<<"to search by name Enter 1\nto search by id Enter 2\n";
            cin>>s;
            if(s==1){
                cout<<"Enter name: ";
                cin.clear();
                cin.sync();
                getline(cin,name);
                find(arr,n,name,-1,false,true);
            }else{
                cout<<"Enter id: ";
                cin>>s;
                find(arr,n,"",s,true,true);
            }
            break;
        case 1:
            display(arr,n,false);
            break;
        case 3:
            cout<<"to sort by id Enter 1\nto sort by name Enter 2\nto sort by salary Enter 3\n";
            cin>>s;
            sort(arr,n,s);
            break;
        case 4:
            cout<<"to find by id Enter 1\nto find by name Enter 2\n";
            cin>>s;
            if(s==1){
                cout<<"Enter id: ";cin>>s;
                s=find(arr,n,"",s,true,false);
            }else{
                cin.clear();
                cin.sync();
                getline(cin,name);
                s=find(arr,n,name,-1,false,false);
            }
            if(s!=-1){
                del(arr,n,s);
                n--;
            }
            break;
        case 5:
            cout<<"Enter id, name, salary\n";
            cin>>id;
            cin.ignore();
            getline(cin,name);
            cin>>salary;
            arr[n++] = new Employee(id,name,salary);
            break;
        default:
            choice =0;
            break;
        }
        if(!choice) break;
    }
    return 0;
}