/*
    Input:
        10 9 -1 8 -1 7 -1 6 -1 -1 -1
        11 -1 12 -1 13 -1 14 -1 15 -1 -1

    Output:
        6->7->8->9->10
        11->12->13->14->15
*/



#include <iostream>
#include <queue>
#include<algorithm>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

pair<Node<int>*,Node<int>*> helper(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        pair<Node<int>*,Node<int>*> ans;
        ans.first = NULL;
        ans.second = NULL;
        return ans;
    }
    
    pair<Node<int>*,Node<int>*> leftAns = helper(root->left);
    Node<int>* newNode = new Node<int>(root->data);
    if(leftAns.first == NULL)
    {
        leftAns.first = newNode;
        leftAns.second = newNode;
    }
    else{
    	leftAns.second->next = newNode;
        leftAns.second = newNode;
    }
    
    pair<Node<int>*,Node<int>*> rightAns = helper(root->right);

    leftAns.second->next = rightAns.first;

    if(rightAns.first != NULL)
        leftAns.second = rightAns.second;

    return leftAns;
    
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
	pair<Node<int>*,Node<int>*> out = helper(root);
    return out.first;
    
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}