#include<bits/stdc++.h>

using namespace std;
// red black tree
enum Color {RED, BLACK}; 
int indicator = 0; //this becomes 1 whenever we can,t evaluate a function

struct Node 
{ 
	string data; 
    string value;
	bool color; 
	Node *left, *right, *parent; 
 
	Node(string data,string value) 
	{ 
	this->data = data; 
    this->value = value;
	left = right = parent = NULL; 
	this->color = RED; 
	} 
}; 

bool same = false;



class RBTree 
{ 
private: 
	Node *root; 
protected: 
	void rotateLeft(Node *&, Node *&); 
	void rotateRight(Node *&, Node *&); 
	void fixViolation(Node *&, Node *&); 
public:
	RBTree() { root = NULL; } 
	void insert(string data,string value);
    void reuse()
    {
        root=NULL;
    }
    void clear_all();
    Node* Root()
    {
        return root;
    }
    string search(string data);
}; 
void clear_helper(Node* root)
{
    if(root==NULL) return;
    clear_helper(root->left);
    clear_helper(root->right);
    delete root;
}

void RBTree::clear_all()
{
    clear_helper(root);
}

Node* BSTInsert(Node* root, Node *pt) 
{ 
	/* If the tree is empty, return a new node */
	if (root == NULL) 
	return pt; 

	/* Otherwise, recur down the tree */
	if (pt->data < root->data) 
	{ 
		root->left = BSTInsert(root->left, pt); 
		root->left->parent = root; 
	} 
	else if (pt->data > root->data) 
	{ 
		root->right = BSTInsert(root->right, pt); 
		root->right->parent = root; 
	} 
    else if(!((pt->data).compare(root->data)))
        {
            root->value = pt->value;
            same = true;
        }

	return root; 
} 



Node* Search_tree(Node* root, string data)
{
    if(root==NULL)  return root;
    if(root->data==data) return root;
    if(root->data < data) return Search_tree(root->right,data);
    if(root->data > data) return Search_tree(root->left,data);
    return NULL;
}

void RBTree::rotateLeft(Node *&root, Node *&pt) 
{ 
	Node *pt_right = pt->right; 

	pt->right = pt_right->left; 

	if (pt->right != NULL) 
		pt->right->parent = pt; 

	pt_right->parent = pt->parent; 

	if (pt->parent == NULL) 
		root = pt_right; 

	else if (pt == pt->parent->left) 
		pt->parent->left = pt_right; 

	else
		pt->parent->right = pt_right; 

	pt_right->left = pt; 
	pt->parent = pt_right; 
} 

void RBTree::rotateRight(Node *&root, Node *&pt) 
{ 
	Node *pt_left = pt->left; 

	pt->left = pt_left->right; 

	if (pt->left != NULL) 
		pt->left->parent = pt; 

	pt_left->parent = pt->parent; 

	if (pt->parent == NULL) 
		root = pt_left; 

	else if (pt == pt->parent->left) 
		pt->parent->left = pt_left; 

	else
		pt->parent->right = pt_left; 

	pt_left->right = pt; 
	pt->parent = pt_left; 
} 

 
void RBTree::fixViolation(Node *&root, Node *&pt) 
{ 
	Node *parent_pt = NULL; 
	Node *grand_parent_pt = NULL; 

	while ((pt != root) && (pt->color != BLACK) && 
		(pt->parent->color == RED)) 
	{ 

		parent_pt = pt->parent; 
		grand_parent_pt = pt->parent->parent; 

		
		if (parent_pt == grand_parent_pt->left) 
		{ 

			Node *uncle_pt = grand_parent_pt->right; 

			
			if (uncle_pt != NULL && uncle_pt->color == RED) 
			{ 
				grand_parent_pt->color = RED; 
				parent_pt->color = BLACK; 
				uncle_pt->color = BLACK; 
				pt = grand_parent_pt; 
			} 

			else
			{ 
				
				if (pt == parent_pt->right) 
				{ 
					rotateLeft(root, parent_pt); 
					pt = parent_pt; 
					parent_pt = pt->parent; 
				} 

				rotateRight(root, grand_parent_pt); 
				parent_pt->color = BLACK;
                grand_parent_pt->color = RED;
				pt = parent_pt; 
			} 
		} 

		
		else
		{ 
			Node *uncle_pt = grand_parent_pt->left; 

			
			if ((uncle_pt != NULL) && (uncle_pt->color == RED)) 
			{ 
				grand_parent_pt->color = RED; 
				parent_pt->color = BLACK; 
				uncle_pt->color = BLACK; 
				pt = grand_parent_pt; 
			} 
			else
			{ 
				
				if (pt == parent_pt->left) 
				{ 
					rotateRight(root, parent_pt); 
					pt = parent_pt; 
					parent_pt = pt->parent; 
				} 

				
				rotateLeft(root, grand_parent_pt); 
				parent_pt->color = BLACK;
                grand_parent_pt->color = RED; 
				pt = parent_pt; 
			} 
		} 
	} 

	root->color = BLACK; 
} 


void RBTree::insert(string data,string value) 
{ 
	Node *pt = new Node(data,value);
    same = false;
 
	root = BSTInsert(root, pt); 

    if(!(same))   fixViolation(root, pt); 
} 

string RBTree::search(string data)
{
    Node* ptr = Search_tree(root,data);
    if(ptr!=NULL)
    return ptr->value;
    indicator = 1; // if ptr is null implies nothing is found
    return "0";
}
int main()
{
    RBTree t;
    int c;
    string key,value;
    while(1)
    {
    cin>>c;
    switch(c)
    {
        case 1:cin>>key>>value;t.insert(key,value);break;
        case 2:cin>>key;cout<<t.search(key)<<"\n";break;
        default:exit(0);
    }
    }
return 0;
}