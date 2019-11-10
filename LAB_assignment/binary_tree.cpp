#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* parent,*left, *right;
    Node(int data)
    {
        this->data = data;
        parent = left = right = NULL;
    }
};

void insert(Node* pos,int left,int data)
{
    Node* newnode = new Node(data);
    if(left==1)
    {
        pos->left = newnode;
        newnode->parent = pos;
    }
    else
    {
        pos->right = newnode;
        newnode->parent = pos;
    }
    
}
void Delete(Node* node)
{
    if(node == NULL) return;
    // node has no child
    else if(node->right==NULL&&node->left==NULL)
    {
        //node is left child of its parent
        if((node->parent)->left == node)
        {
            (node->parent)->left = NULL;
            delete node;
            return;
        }
        //node is right child
        else
        {
            (node->parent)->right = NULL;
            delete node;
            return;
        }
        
    }
    //node has only left child
    else if(node->right==NULL)
    {
        //node is left child of its parent
        if((node->parent)->left == node)
        {
            (node->parent)->left = node->left;
            (node->left)->parent = node->parent; 
            delete node;
            return;
        }
        //node is right child
        else
        {
            (node->parent)->right=node->left;
            (node->left)->parent=node->parent;
            delete node;
            return;
        }

    }
    //node has only right child
    else if(node->left==NULL)
    {
        //node is left child of its parent
        if((node->parent)->left == node)
        {
            (node->parent)->left = node->right;
            (node->right)->parent = node->parent; 
            delete node;
            return;
        }
        //node is right child
        else
        {
            (node->parent)->right=node->right;
            (node->right)->parent=node->parent;
            delete node;
            return;
        }

    }
    //node has both the children
    else
    {
        // find the min element greather than node
        Node* temp = node->right;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        swap(temp->data,node->data);
        Delete(temp);
        return;
    }
    
}

void in_order(Node* root)
{
    if(root == NULL) return;
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);

}