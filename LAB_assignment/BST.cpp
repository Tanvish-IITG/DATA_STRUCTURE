#include<bits/stdc++.h>

using namespace std;

struct NODE
{
    int data;
    NODE* parent;
    NODE* right;
    NODE* left;
    NODE(int data)
    {
        this->data = data;
        this->parent = NULL;
        this->right = NULL;
        this->left = NULL;
    }
};
NODE * Root = NULL;
NODE * create(int data)
{
    NODE* temp;
    temp = new NODE(data);
    return temp;
}
void insert(NODE* &root,NODE* temp,NODE* parent)
{
    if(root==NULL)
    {
        root = temp;
        temp->parent = parent;
        return;
    }
    else if(root->data == temp -> data)
    {
        return;
    }
    else if(root->data > temp->data)
    {
        insert(root->left, temp,root);
    }
    else if(root->data < temp -> data)
    {
        insert(root->right, temp,root);
    }
    else
    {
        return;
    }
}
void insert_value(int data)
{
    NODE* temp = create(data);
    insert(Root,temp,NULL);
}
void in_order(NODE* root)
{
    if(root == NULL) return;
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);

}
NODE * search(NODE * root,int data)
{
    if(root == NULL) return NULL;
    else if(root->data==data) return root;
    else if(root->data<data){
        return search(root->right,data);
    }
    else if(root->data>data){
        return search(root->left,data);
    }
    else
    {
        return NULL;
    }
    
}

void Delete(NODE* node)
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
        NODE* temp = node->right;
        while(temp->left!=NULL)
        {
            temp=temp->left;
        }
        swap(temp->data,node->data);
        Delete(temp);
        return;
    }
    
}
void Delete_index(int data)
{
    NODE* del = search(Root,data);
    Delete(del);
}
void rotate_left(NODE* node,NODE* &Root)
{
    NODE* top = node->right; // this node will come at top
    NODE* buf = top->left; 
    NODE* grand_parent = node->parent;
    if(grand_parent!=NULL)
    {
        if(grand_parent->left==node) grand_parent->left=top;
        if(grand_parent->right==node) grand_parent->right=top;
    }
    else{
        Root = top;
    }
    top->parent = grand_parent;
    top->left = node;
    node->parent = top;
    node -> right = buf;
    if(buf!=NULL)
    buf->parent = node; 
}

int main(void)
{
    insert_value(12);
    insert_value(13);
    insert_value(11);
    insert_value(20);
    insert_value(11);
    in_order(Root);
    rotate_left(Root,Root);
    NODE* temp = search(Root,11);
    int c,v;
    while(1)
    {
    cin>>c;
    switch(c)
    {
        case 1:cin>>v;insert_value(v);break;
        case 2:cin>>v;Delete_index(v);break;
        case 3:cin>>v;if(search(Root,v)) cout<<"present"; else cout<<"absent";break;
        case 4:in_order(Root);cout<<"\n";break;
        default:exit(0);
    }
    }
    

    in_order(Root);
}