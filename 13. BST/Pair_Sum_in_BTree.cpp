/*
    Input:
    5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
    11

    Output:
    2 9
    5 6
*/


#include <iostream>
#include <queue>
#include<algorithm>

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
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
void fillNodes(BinaryTreeNode<int> *root, vector<int> &nodes)
{
    if (root == NULL)
        return;
    nodes.push_back(root->data);
    fillNodes(root->left, nodes);
    fillNodes(root->right, nodes);
}

void pairSum(BinaryTreeNode<int> *root, int sum)
{
    // Write your code here
    vector<int> nodes;

    fillNodes(root, nodes);

    sort(nodes.begin(), nodes.end());

    int i = 0;
    int j = nodes.size() - 1;

    while (i < j)
    {
        if (nodes[i] + nodes[j] == sum)
        {
            cout << nodes[i] << " " << nodes[j];
            cout << endl;
            i++;
            j--;
        }
        else if (nodes[i] + nodes[j] > sum)
            j--;
        else
            i++;
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}