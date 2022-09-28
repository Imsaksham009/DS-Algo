#include<iostream>
#include<vector>
using namespace std;

template<typename T>


class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*> children;

        //default constructor
        TreeNode(int data){
            this->data = data;
        }
};

TreeNode<int>* takeInput(){
    int data{0};
    cout<<"Enter the Data: ";
    cin>>data;

    TreeNode<int> *root = new TreeNode<int>(data);

    int number_of_children{0};
    cout<<"Enter the number of children of "<<data<<": ";
    cin>>number_of_children;

    for(int i{0};i<number_of_children;i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<": ";
    for(int i{0};i<root->children.size();i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;
    for(int i{0};i<root->children.size();i++){
        printTree(root->children[i]);
    }
}




int main(){
    TreeNode<int>* root = takeInput();
    printTree(root);
}