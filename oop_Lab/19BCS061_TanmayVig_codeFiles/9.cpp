#include <iostream>
using namespace std;

class Stak_Node {
private:
	int data;
	Stak_Node* next;
public:	
    Stak_Node* newNode(int);
    void push(Stak_Node**, int);
    int pop(Stak_Node**);
    int isempty(Stak_Node*);
    int front(Stak_Node*);
    void print(Stak_Node*);
};

Stak_Node* Stak_Node::newNode(int data){
	Stak_Node* stackNode = new Stak_Node();
	stackNode->data = data;
	stackNode->next = NULL;
	return stackNode;
}


void Stak_Node::push(Stak_Node** root, int data){
	Stak_Node* stackNode = newNode(data);
	stackNode->next = *root;
	*root = stackNode;
    cout<<data<<" pushed to the stack";
}

int Stak_Node::pop(Stak_Node** root){
	if (isempty(*root))
		return INT_MIN;
	
	Stak_Node* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	return popped;
}

int Stak_Node::isempty(Stak_Node* root){
	return !root;
}

int Stak_Node::front(Stak_Node* root){
	if (isempty(root))
		return INT_MIN;
	return root->data;
}

void Stak_Node::print(Stak_Node* root){
    cout<<"Elements present in stack are (top to bottom) : ";
    while(!isempty(root)) {
        cout<<front(root)<<"\t";
		pop(&root);
	}
}

int main(){
	Stak_Node* root = NULL;
    int choice,item;

    while(1){
        cout<<"\n\n1.To Push\n2.To Pop\n3.To Display the top element\n4.To Display all stack elements\n5.To Quit\n\nEnter your choice : ";
        cin>>choice;
        switch(choice){
         case 1 :
                cout<<"\nEnter data for the stack element: ";
                cin>>item;
                root->push(&root, item);
                break;
         case 2:
                cout<<root->pop(&root)<<" is popped from stack\n";
                break;
         case 3:
                cout<<"\n"<<root->front(root)<<" is on the top\n"<<endl;
                break;
         case 4:
                root->print(root);
                break;
         case 5:
                exit(1);
         default:
                cout<<"\nINCORRECT INPUT\n";
        }
    }

	return 0;
}