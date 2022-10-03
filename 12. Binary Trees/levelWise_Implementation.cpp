#include <iostream>
#include <queue>

using namespace std;

template <typename T>

class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left == NULL;
        right == NULL;
    }
};

BinaryTreeNode<int> *takeInput()
{
    int rootData{0};
    cout << "Enter Root data: ";
    cin >> rootData;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        int leftChildData{0};
        cout << "Enter the left child of " << front->data << ": ";
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *leftChild = new BinaryTreeNode<int>(leftChildData);
            q.push(leftChild);
            front->left = leftChild;
        }

        int rightChildData{0};
        cout << "Enter the right child of " << front->data << ": ";
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *rightChild = new BinaryTreeNode<int>(rightChildData);
            q.push(rightChild);
            front->right = rightChild;
        }
    }
    return root;
}

void printBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << ":";
        if (front->left != NULL)
        {
            cout << "L" << front->left->data;
            q.push(front->left);
        }
        if (front->right != NULL)
        {
            cout << "R" << front->right->data;
            q.push(front->right);
        }
        cout << endl;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printBinaryTree(root);
    return 0;
}