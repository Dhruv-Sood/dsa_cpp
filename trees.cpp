#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <class T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode(){
        for(int i = 0 ; i<children.size() ; i++){
            delete children[i];
        }
    }
};

template <class T>
TreeNode<T> *takeInput()
{
    T rootData;
    cout << "Enter Data: ";
    cin >> rootData;

    TreeNode<T> *root = new TreeNode<T>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << ": ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<T> *child = takeInput<T>();
        root->children.push_back(child);
    }
    return root;
}

template <class T>
void printTree(TreeNode<T> *root)
{

    //!!EDGE CASE!! (NOT BASE CASE)
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ":  ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data;
        if (i != root->children.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

template <class T>
TreeNode<T> *takeInputLevelWise()
{
    T rootData;
    cout << "Enter root data : ";
    cin >> rootData;

    TreeNode<T> *root = new TreeNode<T>(rootData);

    queue<TreeNode<T> *> pendingNodes;

    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        TreeNode<T> *frontNode = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter Number of children of " << frontNode->data << " : ";
        int numChild;
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            T childData;
            cout << "Enter " << i << "th child of " << frontNode->data << " : ";
            cin >> childData;
            TreeNode<T> *child = new TreeNode<T>(childData);
            frontNode->children.push_back(child);

            pendingNodes.push(child);
        }
    }

    return root;
}


template <class T>
int numNodes(TreeNode<T>* root){
    int ans = 1;

    for(int  i = 0 ; i<root->children.size() ; i++){
        ans += numNodes(root->children[i]);
    }

    return ans;
}

template <class T>
void printAtlevelK (TreeNode<T>* root , int  k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout<<root->data<<endl;
    }

    for(int  i = 0 ; i<root->children.size() ; i++){
        printAtlevelK(root->children[i] , k-1);
    }

    return;

}

template <class T>
void preOrder(TreeNode<T> * root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    for(int i = 0 ; i<root->children.size() ; i++){
        preOrder(root->children[i]);
    }
}

template <class T>
void postOrder(TreeNode<T>* root){
    if(root == NULL){
        return;
    }
    if( !root->children.empty() ){
        for (int i = 0; i <= root->children.size(); i++)
        {
            postOrder(root->children[i]);
        }
    }
    
    cout<<root->data<<" ";
}

int main()
{
    /*
    TreeNode<int>* root = new TreeNode<int>(5);
    TreeNode<int> *child0 = new TreeNode<int>(6);
    TreeNode<int> *child1 = new TreeNode<int>(7);
    TreeNode<int> *child2 = new TreeNode<int>(8);

    root->children.push_back(child0);
    root->children.push_back(child1);
    root->children.push_back(child2);

    printTree(root);
    */

    //    TreeNode<char>* newTree = takeInput<char>();

    // TreeNode<char> *chrTree = takeInputLevelWise<char>();

    // printTree(chrTree);

    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

    TreeNode<int>* newTree = takeInputLevelWise<int>();

    // printAtlevelK(newTree , 3);

    // printTree(newTree);
    cout<<endl;
    postOrder(newTree);

    cout << endl<< endl;
    return 0;
}