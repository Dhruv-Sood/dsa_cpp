#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode
{
public:
    int data;
    vector<TreeNode *> children;

    TreeNode(int data)
    {
        this->data = data;
    }
};

// Taking input level-wise

TreeNode *takeInput()
{
    cout << "Enter root: ";
    int rootData;
    cin >> rootData;
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> pending;
    pending.push(root);

    while (!pending.empty())
    {
        TreeNode *frontNode = pending.front();

        cout << "Enter number of children of " << frontNode->data << " ";
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter " << i << "th child of " << frontNode->data << " : ";
            int childData;
            cin >> childData;
            TreeNode *child = new TreeNode(childData);

            frontNode->children.push_back(child);

            pending.push(child);
        }
        pending.pop();
    }

    return root;
}

void printTree(TreeNode* root)
{
    cout << root->data << " : ";

    for(int i = 0 ; i<root->children.size() ; i++){
        cout<<root->children[i]->data<<" ";
    }
    cout<<endl;

    for(int i = 0 ; i<root->children.size() ; i++){
        printTree(root->children[i]);
    }
    
}

int main()
{

    TreeNode *newtree = takeInput();

    printTree(newtree);

    cout << endl
         << endl;

    return 0;
}
