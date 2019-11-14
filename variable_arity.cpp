#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* parent,*left,*right_sibling;
    Node(int data)
    {
        this->data = data;
        parent = left = right_sibling = NULL;
    }
};

Node* insert(Node* parent,int data)
{
    Node* newnode = new Node(data);
    if(parent == NULL)
    {
        return newnode;
    }
    Node* temp = parent->left;
    if(temp == NULL)
    {
        parent->left = newnode;
        newnode->parent = parent;
        return newnode;
    }
    else
    {
        while(temp->right_sibling != NULL)
        {
            temp = temp->right_sibling;
        }
        temp->right_sibling = newnode;
        newnode->parent = parent;
        return newnode;
    }
    
}


void Print_children(Node* root)
{
    Node* temp = root->left;
    while(temp->right_sibling != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->right_sibling;
        }
        cout<<temp->data<<" ";

}

int main()
{
    Node* root = insert(NULL,1);
    Node* sibling1 = insert(root,2);
    Node* sibling2 = insert(root,3);
    Node* sibling3 = insert(root,4);
    Node* sibling4 = insert(root,5);
    Node* sibling21 = insert(sibling2,21);
    Node* sibling22 = insert(sibling2,22);
    Node* sibling23 = insert(sibling2,23);
    Node* sibling24 = insert(sibling2,24);
    Print_children(root);
    cout<<"\n";
    Print_children(sibling2);
    return 0;
}