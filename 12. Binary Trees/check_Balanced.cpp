/*
    Input:-
    8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

    Ouptut:-
    False
*/



#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

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



int height(BinaryTreeNode<int>* root){
    if(root == NULL)
        return 0;
    return 1 + height(root->left) + height(root->right);
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL || (root->left == NULL && root->right == NULL))
        return true;
   	bool ans = false;
    
    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    if((std::abs(leftHeight - rightHeight) <=1) && leftAns && rightAns)
        ans = true;
    
    return ans;
    
}


int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");
}