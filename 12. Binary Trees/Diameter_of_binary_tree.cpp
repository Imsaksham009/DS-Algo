/*
Input:- 
1 2 3 4 5 -1 -1 6 -1 -1 8 7 -1 -1 9 10 -1 -1 11 -1 -1 -1 -1 

output:-
8
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
/*
 ******************* TC:- O(n * h) **********************
int height(BinaryTreeNode<int> *root)
{
    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight,rightHeight);
    
}

int getDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int option1 = height(root->left) + height(root->right);
    int option2 = getDiameter(root->left);
    int option3 = getDiameter(root->right);

    return max(option1, max(option2, option3));
}
*/


//**********TC:- O(n) n = number of nodes *************

pair<int,int> get_diameter_height(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        pair<int,int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int,int> leftAns = get_diameter_height(root->left);
    pair<int,int> rightAns = get_diameter_height(root->right);

    int leftHeight = leftAns.first;
    int rightHeight = rightAns.first;
    
    int leftDia = leftAns.second;
    int rightDia = rightAns.second;


    pair<int,int> ans;
    ans.first = max(leftHeight,rightHeight) + 1;
    ans.second = max(leftHeight + rightHeight,max(leftDia,rightDia));

    return ans;
}

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    cout<<"Height: "<<get_diameter_height(root).first<<"\n Diameter: "<<get_diameter_height(root).second<<endl;

    return 0;
}

