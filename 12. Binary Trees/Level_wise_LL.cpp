/*
Input:-
10 9 11 8 -1 -1 12 7 -1 -1 13 -1 -1 -1 -1

Ouput:-
10 
9 11 
8 12 
7 13 
*/


#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL)
    {
        vector<Node<int>*> ans;
        ans.push_back(NULL);
        return ans;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    vector<Node<int>*> ans;
    while(q.size()!=0)
    {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        
        int rootData = front->data;
        
        Node<int>* head = new Node<int>(rootData);
        
        if(front->left!=NULL)
            q.push(front->left);
        if(front->right!=NULL)
            q.push(front->right);
        
        
        Node<int>* temp = head;
        
        
        while(q.front()!=NULL){
            
            front = q.front();
            q.pop();
            
            rootData = front->data;
            
            Node<int>* newNode = new Node<int>(rootData);
            
            temp->next = newNode;
            temp = temp->next;
            
            if(front->left!=NULL)
                q.push(front->left);
			if(front->right!=NULL)
            	q.push(front->right);
            
        }
        q.pop();
        if(q.size() != 0)
            q.push(NULL);
        temp->next = NULL;
        
        ans.push_back(head);
        
    }
    return ans;
}


int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}