#include <iostream>
#include <queue>
using namespace std;

template <class T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

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

template <class T>
void printTree(BinaryTreeNode<T> *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " : ";

    if (root->left != NULL)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right != NULL)
    {
        cout << "R" << root->right->data << " ";
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

template <class T>
BinaryTreeNode<T>* takeInput(){
    int rootData;
    cout<<"Enter root data : ";
    cin>>rootData;

    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<T>* root = new BinaryTreeNode<T>(rootData);
    BinaryTreeNode<T> *leftChild = takeInput<T>();
    BinaryTreeNode<T> *rightChild = takeInput<T>();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}


template <class T>
BinaryTreeNode<T>* takeInputLevelWise(){
    T rootData;
    cout<<"Enter the root data : ";
    cin>>rootData;

    if(rootData == -1){
        return NULL;
    }

    queue<BinaryTreeNode<T>*> pending;
    BinaryTreeNode<T>* root = new BinaryTreeNode<T>(rootData);
    pending.push(root);

    while(!pending.empty()){
        BinaryTreeNode<T>* frontNode = pending.front();

        cout<<"Enter left child of "<<frontNode->data<<" : ";
        T leftData;
        cin>>leftData;
        if(leftData != -1){
            BinaryTreeNode<T>* leftNode = new BinaryTreeNode<T>(leftData);
            frontNode->left = leftNode;
            pending.push(leftNode);
        }

        cout << "Enter right child of " << frontNode->data << " : ";
        T rightData;
        cin >> rightData;
        if(rightData != -1){
            BinaryTreeNode<T> *rightNode = new BinaryTreeNode<T>(rightData);
            frontNode->right = rightNode;
            pending.push(rightNode);
        }

        pending.pop();

    }
    return root;
}

int numNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int ans = 1;

    return 1 + numNodes(root->left) + numNodes(root->right);
}


void inOrder(BinaryTreeNode<int>* root){
    if(root == NULL ){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}

int main()
{
    /*
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *left = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *right = new BinaryTreeNode<int>(3);

    root->left = left;
    root->right = right;
    */

   BinaryTreeNode<int>* root = takeInputLevelWise<int>();
   cout<<endl<<endl;
    cout<<"Number of nodes : "<<numNodes(root);
    return 0;
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1