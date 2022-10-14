// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data; // in every binary tree there should be node of <=2 and data.
    node *left;
    node *right;
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *root)
{
    cout << "Enter the data" << endl; // using this function we build a tree with recursive function.
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
        return NULL;
    cout << "Enter the data to insert at left" << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data to insert at right" << endl;
    root->right = buildTree(root->right);
    return root;
}
// Comment
void inorderTraversal(node *root)
{                     // *******LNR********
    if (root == NULL) // In this traversal we traverse the tree by following LNR model.
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(node *root)
{                     // *****NLR******
    if (root == NULL) // In this traversal we traverse the tree by following NLR model.
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void postorderTraversal(node *root)
{ // ****LRN****
    if (root == NULL)
        return;
    postorderTraversal(root->left); // In this traversal we traverse the tree by following LRN model.
    postorderTraversal(root->right);
    cout << root->data << " ";
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;   // In this traversal we traverse the tree level wise.
    q.push(root);      //            1  first this will print
    q.push(NULL);      //            2   3 2nd we will print this line
    while (!q.empty()) //     4  5 6  7  3rd we will print this line
    {                  // output -> 1 2 3 4 5 6 7
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void buildFromLevelOrder(node *&root)
{
    queue<node *> q;
    cout << "Enter data for the root" << endl; // here we will create a tree level wise.. Like we will create step by step...
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter data for the left node of " << temp->data << endl;
        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout << "Enter data for the right node of " << temp->data << endl;
        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
}
int main()
{
    // Write C++ code here
    node *root = NULL;
    // input-> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    buildFromLevelOrder(root);
    levelOrderTraversal(root);
    // root=buildTree(root);
    // cout<<"inorderTraversal"<<endl;
    // inorderTraversal(root);
    // cout<<"preorderTraversal"<<endl;
    // preorderTraversal(root);
    // cout<<"postorderTraversal"<<endl;
    // postorderTraversal(root);

    cout << "run successfully" << endl;

    return 0;
}