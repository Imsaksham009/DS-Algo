#include <iostream>
#include <queue>
#include <bits/stdc++.h>

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
    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
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

pair<pair<int, int>, pair<int, bool>> helper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<pair<int, int>, pair<int, bool>> ans;
        ans.first.first = INT_MAX;
        ans.first.second = INT_MIN;
        ans.second.first = 0;
        ans.second.second = true;
        return ans;
    }
    pair<pair<int, int>, pair<int, bool>> left = helper(root->left);
    pair<pair<int, int>, pair<int, bool>> right = helper(root->right);

    pair<pair<int, int>, pair<int, bool>> ans;

    if (root->data > left.first.second && root->data <= right.first.first && left.second.second && right.second.second)
    {
        ans.second.second = true;
        ans.second.first = 1 + max(left.second.first, right.second.first);
        ans.first.first = min(root->data, min(left.first.first, right.first.first));
        ans.first.second = max(root->data, max(left.first.second, right.first.second));
    }
    else
    {
        ans.second.second = false;
        ans.second.first = max(left.second.first, right.second.first);
        ans.first.first = min(root->data, min(left.first.first, right.first.first));
        ans.first.second = max(root->data, max(left.first.second, right.first.second));
    }

    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    // Write your code here
    pair<pair<int, int>, pair<int, bool>> ans = helper(root);
    return ans.second.first;
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}