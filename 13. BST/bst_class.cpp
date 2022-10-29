#include <iostream>
using namespace std;

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

class BST {
    // Define the data members
    private:
    	BinaryTreeNode<int>* root;
    
    	//search
    	bool search(int data, BinaryTreeNode<int>* node)
        {
            if(node == NULL)
                return false;
            if(node->data == data) return true;
            else if(data > node->data) return search(data,node->right);
            else return search(data,node->left);
        }
    //insertion
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node)
    {
        if(node == NULL)
        {
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data>node->data)
            node->right = insert(data,node->right);
        else
            node->left = insert(data,node->left);
        
        return node;
        
    }
    
    //deletion
    BinaryTreeNode<int>* remove(int data,BinaryTreeNode<int>* node)
    {
		if(node == NULL)
            return node;
        if(data>node->data)
            node->right = remove(data,node->right);
        else if(data<node->data)
            node->left = remove(data,node->left);
        else
        {
            if(node->left == NULL && node->right == NULL){
                delete node;
                return NULL;
            }
            else if(node->left == NULL)
            {
                BinaryTreeNode<int>* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == NULL)
            {
               	BinaryTreeNode<int>* temp = node->left;
              	delete node;
                return temp; 
            }
            else
            {
                BinaryTreeNode<int>* rmin = node->right;
                while(rmin->left!=NULL)
                    rmin = rmin->left;
                node->data = rmin->data;
                node->right = remove(rmin->data,node->right);
                return node;
            }
        }
    }
    
    //printing
    void print(BinaryTreeNode<int>* node)
    {
        if(node== NULL)
            return;
        cout<<node->data<<":";
        if(node->left) cout<<"L:"<<node->left->data<<",";
        if(node->right) cout<<"R:"<<node->right->data;
        cout<<endl;
        print(node->left);
        print(node->right);
        
    }
   public:
    BST() { 
        // Implement the Constructor
        root = NULL;
    }

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        // Implement the remove() function 
        this->root = remove(data,this->root);
    }

    void print() { 
        // Implement the print() function
        print(this->root);
    }

    void insert(int data) { 
        // Implement the insert() function 
        this->root = insert(data,this->root);
    }

    bool search(int data) {
		// Implement the search() function 
        return search(data,this->root);
    }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}