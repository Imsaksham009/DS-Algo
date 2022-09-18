#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class QueueUsingLL {
	// Define the data members
    private:
    	Node* head;
    	Node* tail;
    	int size;
   public:
    QueueUsingLL() {
		// Implement the Constructor
        head = NULL;
        tail = NULL;
        size = 0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		// Implement the getSize() function
        return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() 
        return size == 0;
	}

    void enqueue(int data) {
		// Implement the enqueue() function
        Node* temp = new Node(data);
        if(head == NULL){
            head = temp;
            tail = temp;
            size++;
            return;
        }
        tail->next = temp;
        tail = temp;
        size++;
	}

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()){
            return -1;
        }
        int ans = head->data;
        head = head->next;
        size--;
        return ans;
    }

    int front() {
        // Implement the front() function
        if(isEmpty())
            return -1;
        return head->data;
    }
};

int main() {
    QueueUsingLL q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}