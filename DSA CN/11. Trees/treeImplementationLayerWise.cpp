#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>

class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    // default constructor
    TreeNode(int data)
    {
        this->data = data;
    }
};

TreeNode<int> *takeInput()
{
    int data{0};
    cout << "Enter the data: ";
    cin >> data;

    TreeNode<int> *root = new TreeNode<int>(data);
    queue<TreeNode<int> *> q;
    q.push(root);

    while (q.size() != 0)
    {
        TreeNode<int> *front = q.front();
        q.pop();
        int number_of_child{0};
        cout << "Enter the Number of children of " << front->data << " node: ";
        cin >> number_of_child;
        for (int i{0}; i < number_of_child; i++)
        {
            cout << "Enter the " << i + 1 << "th child of " << front->data << ": ";
            int child_data{0};
            cin >> child_data;
            TreeNode<int> *child = new TreeNode<int>(child_data);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode<int> *> nodes;
    nodes.push(root);

    while (nodes.size() != 0)
    {
        TreeNode<int> *front = nodes.front();
        nodes.pop();
        cout<<front->data<<": ";
        for (int i{0}; i < front->children.size(); i++)
        {
            cout<<front->children[i]->data<<", ";
            nodes.push(front->children[i]);
        }
        cout<<endl;
    }
}

int main()
{
    TreeNode<int> *root = takeInput();
    printTree(root);
}