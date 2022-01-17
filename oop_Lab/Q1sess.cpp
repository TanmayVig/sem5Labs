#include <iostream>
#include <string>
using namespace std;

// Employee class to represent
// a node of the linked list.
class Employee {
public:
    string name;
	int salary;
    int id;
	Employee* next;

	// Default constructor
	Employee()
	{
		salary = 0;
        name="";
        id=0000;
		next = NULL;
	}

	// Parameterised Constructor
	Employee(int salary,string name,int id)
	{
		this->salary = salary;
        this->name=name;
        this->id=id;
		this->next = NULL;
	}
};

// Linked list class to
// implement a linked list.
class Linkedlist {
	Employee* head;

public:
	// Default constructor
	Linkedlist() { head = NULL; }

	// Function to insert a
	// node at the end of the
	// linked list.
	void insertNode(int,string,int);

	// Function to print the
	// linked list.
	void printList();

	// Function to delete the
	// node at given position
	void deleteNode(int);
    
    // Function to update the
	// node at given position
    void updateNode(int, string,int);
};

// Function to delete the
// node at given position
void Linkedlist::deleteNode(int id)
{
	Employee *temp1 = head, *temp2 = NULL;
	int ListLen = 0;

	if (head == NULL) {
		cout << "List empty." << endl;
		return;
	}

	// Find length of the linked-list.
	while (temp1 != NULL) {
		temp1 = temp1->next;
		ListLen++;
	}
	// Declare temp1
	temp1 = head;

	// Deleting the head.
    bool f=false;
	// Traverse the list to
	// find the node to be deleted.
	while (temp1->next!=NULL) {

        if(temp1->next->id==id){
            cout<<"found\n";
            f=true;
            break;
        }

		// Update temp1
		temp1 = temp1->next;
	}

	// Change the next pointer
	// of the previous node.
    if(f) 
    {
        temp2=temp1;
        temp2->next = temp1->next->next;

        // Delete the node
        delete temp1;
    }
    else cout<<"Not found";
}

void Linkedlist::updateNode(int id,string name, int salary)
{
	Employee *temp1 = head, *temp2 = NULL;
	int ListLen = 0;

	if (head == NULL) {
		cout << "List empty." << endl;
		return;
	}

	// Find length of the linked-list.
	while (temp1 != NULL) {
		temp1 = temp1->next;
		ListLen++;
	}
	// Declare temp1
	temp1 = head;

	// Deleting the head.
	if (id == 1) {

		// Update head
		head = head->next;
		delete temp1;
		return;
	}
    bool f=false;
	// Traverse the list to
	// find the node to be deleted.
	while (temp1->next!=NULL) {

        if(temp1->next->id==id){
            f=true;
            break;
        }
		// Update temp2
		temp2 = temp1;

		// Update temp1
		temp1 = temp1->next;
	}

	// Change the next pointer
	// of the previous node.
    if(f) 
    {
        temp1=temp1->next;
        temp1->name=name;
        temp1->salary=salary;
    }
    else cout<<"Not found";
}

// Function to insert a new node.
void Linkedlist::insertNode(int data, string name,int id)
{
	// Create the new Employee.
	Employee* newNode = new Employee(data, name,id);

	// Assign to head
	if (head == NULL) {
		head = newNode;
		return;
	}

	// Traverse till end of list
	Employee* temp = head;
	while (temp->next != NULL) {

		// Update temp
		temp = temp->next;
	}

	// Insert at the last.
	temp->next = newNode;
}

// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
	Employee* temp = head;

	// Check for empty list.
	if (head == NULL) {
		cout << "List empty" << endl;
		return;
	}

	// Traverse the list.
	while (temp != NULL) {
		cout <<"ID: "<<temp->id<<" Name: "<< temp->name <<" Salary:"<<temp->salary << endl;
		temp = temp->next;
	}
}

// Driver Code
int main()
{
	Linkedlist list;
    while(1){
        string name;
        int salary,id;
        cout<<"To add Employee Enter 1\nTo delete Employee Enter 2\nTo update Employee Enter 3\nEnter 4 to print list\nEnter 0 to Exit\n";
        int choose=0;
        cout<<"  Enter your choice: ";
        cin>>choose;
        if(choose==0) break;
        switch (choose)
        {
        case 1:
            cout<<"enter id: ";
            cin>>id;
            cout<<"enter name: ";
            cin>>name;
            cout<<"enter salary: ";
            cin>>salary;
            list.insertNode(salary,name,id);
            break;
        case 2:
            cout<<"enter id to delete: ";
            cin>>id;
            list.deleteNode(id);
            break;
        case 3:
            cout<<"enter id: ";
            cin>>id;
            cout<<"enter name: ";
            cin>>name;
            cout<<"Enter salary: ";
            cin>>salary;
            list.updateNode(id,name,salary);
        case 4:
            list.printList();
            break;
        
        default:
            cout<<"invalid input\n";
            break;
        }
    }


	// Delete node at position 2.
	list.deleteNode(2);

	cout << "Elements of the list are: ";
	list.printList();
	cout << endl;
	return 0;
}