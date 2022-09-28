#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // default constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *head)
{
    while (head != NULL)
    {

        cout << head->data << " ";
        head = head->next;
    }
}

/*
O(n^2) VERY BAD TIME COMPLEXITY
Node *input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    while (data != -1)
    {
        if (head == NULL)
        {
            Node *node = new Node(data);
            head = node;
        }
        else
        {
            Node *node = new Node(data);
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = node;
        }
        cin >> data;
    }

    return head;
}
*/
// Better Solution for input
Node *input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *node = new Node(data);
        if (head == NULL)
        {

            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        cin >> data;
    }
    return head;
}

// print data at ith pos
void printAtI(Node *head, int i)
{
    // Write your code here
    if (head == NULL)
        return;
    else
    {
        Node *temp = head;
        for (int j{0}; j < i; j++)
        {
            temp = temp->next;
            if (temp == NULL)
                break;
        }
        if (temp != NULL)
            cout << temp->data << endl;
        else
            return;
    }
}

// insert data at ith position
Node* insert(Node *head, int i, int data)
{
    Node *newNode = new Node(data);

    if(head == 0){
        head = newNode;
        return head;
    }
    
    if(i == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *temp = head;
    for (int j{0}; j < i - 1; j++)
    {
        temp = temp->next;
        if (temp == NULL)
            break;
    }
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }
    return head;

}

//delete ith Node
Node* deleteNode(Node* head,int i){

    if(head == NULL)
        return head;

    if(i == 0){
        return (head->next);
    }
    Node* temp = head;
    for(int j{0};j<i-1;j++){
        temp = temp->next;
        if (temp == NULL || temp->next == NULL)
            break;
    }
    if(temp != NULL && temp->next != NULL){
    temp->next = (temp->next)->next;
    return head;
    }
    return head;

}


int getSize(Node *head){
    if(head == 0)
        return 0;
    else
        return 1 + getSize(head->next);
}

Node *removeDuplicates(Node *head)
{
    //Write your code here
    if(head == NULL)
        return head;
    if(head->data == (head->next)->data){
        Node* temp = removeDuplicates((head->next)->next);
        (head->next)->next = temp;
        return head->next;
    }
    Node* temp = removeDuplicates(head->next);
    head->next = temp;
    return head;
}

Node *fun(Node *head, int n)
{
    //Write your code here
    if(n == 0 || head == NULL)
        return head;


	int size = getSize(head);

    if(size == n){
        return 0;
    }
    int num = size - n;
    
    Node* temp = head;
    
    for(int i{0};i<num;i++){
        temp = temp->next;
    }
    
    Node* temp1 = head;
    head = temp;
    
    Node* temp2 = temp;
    for(int i{0};i<n-1;i++){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    for(int i{0};i<num - 1;i++){
        temp1= temp1->next;
    }
    temp1->next = 0;
    
    return head;

}

Node* reverse(Node* head){
    if(head->next == NULL || head == NULL){
        return head;
    }
    Node* smallHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}

int main()
{

    Node *head = input();
    Node* head1 = reverse(head);

    print(head1);


    return 0;
}