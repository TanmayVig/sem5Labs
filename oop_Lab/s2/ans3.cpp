#include<iostream>
#include<string>
using namespace std;

template <class T>
class Node{
	public: 
	
		T data;
		Node<T> *next; // points to next node
		
		Node(T d)
		{
			data = d;
			next = NULL;
		}
		
};

template <class T>
class Queue{
	
	Node<T> *start;
	Node<T> *end; 
	
	public:
		
		Queue()
		{
			start = end = NULL;
		}
		
		bool empty() // checks if Queue is empty and returns true if yes
		{
			return start==NULL;
		}
		
		void push(T v) // pushing element at the end of the Queue
		{
			Node<T> *temp = new Node<T>(v);
			if(empty())
			{
				start = end = temp;
			}
			else
			{
				end->next = temp;
				end = temp;
			}
			
		}
		
		T face() // returns element at first position
		{
			if(empty())
				return NULL;
			else
				return start->data;	
		} 
	
		
		void pop()// removes the first element of the Queue
		{
			if(empty())
			{
				cout<<"Queue is Empty"<<endl;
			}
			else if(start==end)
			{
				delete start;
				start = end = NULL;
			}
			else
			{
				Node<T> *temp = start;
				start = start->next;
				delete temp;
			}
		}
		
	
};
int main()
{
	Queue<string> q;
    if(q.empty()) cout<<"Queue is empty\n";
    else cout<<"Queue have some elements\n";

	q.push("Tanmay Vig");
	q.push("Rishabh");
	
	cout<<"Queue Front: "<<q.face()<<endl;
	
	q.push("How");
	q.push("are");
	q.push("you?");

    if(q.empty()) cout<<"Queue is empty\n";
    else cout<<"Queue have some elements\n";
	
	
	while(!q.empty()){
		cout<<q.face()<<endl;
		q.pop();
	}



}