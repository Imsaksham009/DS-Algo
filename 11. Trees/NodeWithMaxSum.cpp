#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    // Write your code here
    TreeNode<int> *ans = root;
    int ansCount = ans->data;
    for (int i{0}; i < ans->children.size(); i++)
    {
        ansCount = ansCount + ans->children[i]->data;
    }

    for (int i{0}; i < root->children.size(); i++)
    {

        TreeNode<int> *potentialMax = maxSumNode(root->children[i]);
        int potentialMaxCount = potentialMax->data;

        for (int i{0}; i < potentialMax->children.size(); i++)
        {
            potentialMaxCount = potentialMaxCount + potentialMax->children[i]->data;
        }

        if (potentialMaxCount > ansCount)
            ans = potentialMax;
    }

    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();

    TreeNode<int> *ans = maxSumNode(root);

    if (ans != NULL)
    {
        cout << ans->data;
    }
}