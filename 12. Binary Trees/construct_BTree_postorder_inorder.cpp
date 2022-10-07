/*
Input:-
7
4 5 2 6 7 3 1 
4 2 5 1 6 3 7 

output:-
1 
2 3 
4 5 6 7 
*/


#include <iostream>
#include <queue>

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

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

BinaryTreeNode<int>* helper(int *postorder, int *inorder, int postS, int postE, int inS, int inE)
{
    if(postS > postE || inS > inE)
        return NULL;
    
    int rootData = postorder[postE];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    
    int index = -1;
    for(int i{inS};i<=inE;i++){
        if(inorder[i] == rootData)
        {
            index = i;
            break;
        }
    }
    
    int linEnd = index - 1;
    int lpostEnd = postS + (linEnd - inS);
    
    
    root->left = helper(postorder,inorder,postS,lpostEnd,inS,linEnd);
    root->right = helper(postorder,inorder,lpostEnd + 1,postE - 1,index + 1,inE);
    
    return root;
}



BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return helper(postorder,inorder,0,postLength - 1,0,inLength - 1);
}

int main() {
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}