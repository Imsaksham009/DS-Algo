// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

class Pair{
    public:
    	Node* head;
    	Node* tail;
    
    	Pair(){
            head = NULL;
            tail = NULL;
        }
};

Pair reverse(Node* head){
    Pair reverseNode;
    Node* prev = NULL;
    Node *curr = head;
    Node* nextCurr = head->next;

    while(nextCurr != NULL){
        curr->next = prev;
        prev = curr;
        curr = nextCurr;
        nextCurr = nextCurr->next;
    }
    curr->next = prev;
    reverseNode.tail = head;
    reverseNode.head = curr;
    return reverseNode;

}


int main(){
    
    Node *head = takeinput();
    
    Pair rn = reverse(head);
    print(rn.head);

    return 0;
    
}