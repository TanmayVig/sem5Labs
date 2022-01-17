#include<iostream>
#include<string>
#define M 10

using namespace std;


class Account{
    private:
        long long int account_number;
        string name;
        string account_type;
        int balance;

    public:
        void putDetails(){
            cout<<"Enter Account Number:\t";
            cin>>account_number;
            cin.ignore();
            cout<<"Enter Name of depositor:\t";
            getline(cin, name);
            cout<<"Enter Type of Account(Current, Saving, Salary):\t";
            getline(cin, account_type);
            cout<<"Enter Balance amount in the account:\t";
            cin>>balance;
        }

        void deposite(int amt){
            balance=balance+amt;
            cout<<"Amount deposited: "<<amt<<". Total balance: "<<balance<<endl;
        }

        void withdraw(int amt){
            if(balance<amt) cout<<"Error: please input Valid amount.\nYour current balance is: "<<balance<<endl;
            else{
                balance=balance-amt;
                cout<<"Amount withdraw: "<<amt<<". Total balance: "<<balance<<endl;
            }
        }
        void display(){
            cout<<"Name: "<<name<<".\nAccount Type: "<<account_type<<".\nBalance: "<<balance<<endl;
        }
        int getbalance(){
            return balance;
        }
        long long int getAccNum(){
            return account_number;
        }
};

int findAcc(Account arr[],long long int num) {
    for(int i=0;i<M;i++) {
        if(arr[i].getAccNum()==num) return i;
    }
    return -1;
}

int main(){
    Account arr[M];
    int n;
    long long int accNum;
    for(int i=0;i<M;i++){
        cout<<"Enter Details of Account "<<i+1<<endl;
        arr[i].putDetails();
    }
    do{
        cout<<"Enter 1 to Deposit. \nEnter 2 to Withdraw. \nEnter 3 to see your Details.\nEnter 0 to exit.\n";
        cin>>n;
        if(n){
            cout<<"Enter Account Number:\t";
            cin>>accNum;
        }
        int index=findAcc(arr,accNum),amt;
        if(index!=-1){
            switch (n)
            {
            case 1:
                cout<<"Enter Amount to Deposite:\t";
                cin>>amt;
                cout<<endl;
                arr[index].deposite(amt);
                break;
            case 2:
                cout<<"Enter Amount to withdraw:\t";
                cin>>amt;
                cout<<endl;
                arr[index].withdraw(amt);
                break;
            case 3:
                cout<<endl;
                arr[index].display();
                break;
            default:
                cout<<"Enter valid input or 0 to Exit\n";
                break;
            }
        }else if(index==-1){
            cout<<"\nError: no account found.\n";
        }
    }while(n!=0);
    cout<<"Enter 1 to see all account details in sorted order\nEnter 2 to see all details in unsorterd order\n";
    cin>>n;
    if(n==1){
        int i,j;
        for(i=0;i<M-1;i++){
            for(j=0;j<M-i-1;j++){
                if(arr[j].getbalance()>arr[j+1].getbalance()){
                    Account temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
        cout<<"Showing Details in unsorted order:\n";
        cout<<"____________"<<endl;
        for(int i=0;i<M;i++){
            arr[i].display();
            cout<<"____________"<<endl;
        }
    }else{
        cout<<"Showing Details in unsorted order:\n";
        cout<<"____________"<<endl;
        for(int i=0;i<M;i++){
            arr[i].display();
            cout<<"____________"<<endl;
        }
    }
    return 0;
}