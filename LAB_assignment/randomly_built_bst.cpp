#include<bits/stdc++.h>

using namespace std;

struct TreapNode{
    int data;
    int priority;
    TreapNode *left;
    TreapNode *right;
    TreapNode(int data,int priority)
    {
        this->data = data;
        this->priority = priority;
        left = NULL;
        right = NULL;
    }
};
TreapNode *rightRotate(TreapNode *y) 
{ 
    TreapNode *x = y->left,  *T2 = x->right;  
    x->right = y; 
    y->left = T2;  
    return x; 
}
TreapNode *leftRotate(TreapNode *x) 
{ 
    TreapNode *y = x->right, *T2 = y->left;  
    y->left = x; 
    x->right = T2;  
    return y; 
} 
class treap
{
    TreapNode* Root;
    public:
    treap()
    {
        this->Root = NULL;
    }
    TreapNode* help_insert(TreapNode* root,int d,int p)
    {
        if (root==NULL) 
        {
            TreapNode* newnode = new TreapNode(d,p);
            return newnode; 
        }
        if (d <= root->data) 
    {  
        root->left = help_insert(root->left, d,p); 
        if (root->left->priority > root->priority) 
            root = rightRotate(root);

    }
    else   
    {  
        root->right = help_insert(root->right, d,p); 
        if (root->right->priority > root->priority) 
            root = leftRotate(root); 
    } 
    return root; 
    }
    void insert(int d,int p)
    {
        Root = help_insert(Root,d,p);
    }
    TreapNode* help_delete(TreapNode* root,int d)
    {
        if(root==NULL) return root;
        else if(root->data < d ) root->right =  help_delete(root->right,d);
        else if(root->data > d)  root->left =    help_delete(root->left,d);
        else
        {
            if(root->left == NULL)
            {
                TreapNode* temp = root;
                delete root;
                root = temp->right;
            }
            else if(root->right == NULL)
            {
                TreapNode* temp = root;
                delete root;
                root = temp->left;
            }
            else
            {
                if(root->left->priority > root->right->priority)
                {
                    root = rightRotate(root);
                    root->right = help_delete(root->right,d);
                }
                else
                {
                    root = leftRotate(root);
                    root->left = help_delete(root->left,d);
                }
            }
            
        }
        return root;
        
    }
    void delete_node(int k)
    {
        Root = help_delete(Root,k);
    }
    bool help_search(TreapNode* root,int d)
    {
        if(root==NULL) return false;
        else if(root->data < d ) return help_search(root->right,d);
        else if(root->data > d)  return  help_search(root->left,d);
        else return true;
    }
    bool search(int d)
    {
        return help_search(Root,d);
    }
    void help_inorder(TreapNode* root) 
{ 
    if (root) 
    { 
        help_inorder(root->left); 
        cout << "key: "<< root->data;
        if (root->left) 
            cout << " | left child: " << root->left->data; 
        if (root->right) 
            cout << " | right child: " << root->right->data; 
        cout << endl; 
        help_inorder(root->right); 
    }

} 
    void inorder()
    {
        help_inorder(Root);
    }
};
int main()
{
    int c,key,priority;
    cout<<"1. insert\n2. delete\n3. display\n";
    treap t;
    while(1)
    {
        cin>>c;
        switch(c)
        {
            case 1: cin>>key; priority = rand()%1000;t.insert(key,priority); break;
            case 2: cin>>key; t.delete_node(key); break;
            case 3: t.inorder(); break;
            default: exit(0);
        }
    }
    return 0;
}