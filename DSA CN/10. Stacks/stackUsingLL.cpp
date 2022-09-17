#include <bits/stdc++.h>

using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int data = 0)
    {
        this->data = data;
        next = NULL;
    }
};

class StackUsingLL
{
    // Define the data members
private:
    Node *head;
    int size;

public:
    StackUsingLL()
    {
        // Implement the Constructor
        head = NULL;
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return size == 0;
    }

    void push(int element)
    {
        // Implement the push() function
        Node *newNode = new Node(element);
        if (head == NULL)
        {
            head = newNode;
            size++;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            size++;
        }
    }

    int pop()
    {
        // Implement the pop() function
        if (head == NULL)
        {
            return -1;
        }
        int ans = head->data;
        head = head->next;
        size--;
        return ans;
    }

    int top()
    {
        // Implement the top() function
        if (head == NULL)
            return -1;
        return head->data;
    }
};

int main()
{

    // inbuilt stack
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout << s.top();
    cout << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.size() << endl;

    return 0;
}