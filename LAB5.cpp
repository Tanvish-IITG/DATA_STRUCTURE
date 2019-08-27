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
				swap(parent_pt->color, grand_parent_pt->color); 
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
				swap(parent_pt->color, grand_parent_pt->color); 
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
//red black tree all functions end here

struct node
{
    node* left;
    node* right;
    string data;
    node* parent;
};

//this node is used in evaluation tree





int is_assignment(string s)
{
    for(auto X:s)
    {
        if(X>='a'&&X<='z'||X>='A'&&X<='Z'||X>='1'&&X<='9') 
        continue;
        else if(X=='=') return 1;


    }
    return 0;
}


int toint(string s)
{   
    if(s[0]=='-')

    {
        int num = 0;
        int l = s.size()-1;
        for(int i = 1; s[i]!='\0';i++)
        {
            num += (s[i]-'0')*pow(10,l-i);
        }
    num = num*-1;
    return num;
    }

    else
    {
        
        int num = 0;
        int l = s.size();
        for(int i = 0; s[i]!='\0';i++)
        {
            num += (s[i]-'0')*round(pow(10,l-i-1));
        }
    return num;
    }
}

vector<string> parse_string(string s)
{
    
    int l = s.size();
    vector<string> arr;
    string number = "";
    for(int j = 0;j < l;j++)
    {   
        if(s[j]=='+'||
        (s[j]=='-'&& (j!=0&&(s[j-1]<='9'&&s[j-1]>='0') ))||
        s[j]=='*'||
        s[j]=='/'||
        s[j]=='('||
        s[j]==')'||
        s[j]=='^')
        {   
            arr.push_back(number);  
            number = "";
            string str = { s[j] , '\0'};
            arr.push_back(str);
        }
        else
        {
            number.push_back(s[j]);
        }
        
    }
    if(number.compare("")) arr.push_back(number);
    auto it = arr.begin();
    int l1 = arr.size();
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]=="") 
        {
            arr.erase(it+i);
            i--;
        }
    }
    return arr;
}

void make_tree(node*left,node* root,node* right)
{
    root->left = left;
    root->right = right;
}


node * built_tree(vector<string> s)
{   
    stack<node *> st;   
    int l = s.size();
    for(int i = 0;i<l;i++)
    {
        if((s[i][0]<='9'&&s[i][0]>='0')||(s[i].size()>1&&(s[i][0]=='-')&&s[i][1]<='9'&&s[i][1]>='0'))
        {
            node *ptr = new node;
            ptr->data = s[i];
            ptr->right = NULL;
            ptr->left = NULL;
            ptr->parent = NULL;
            st.push(ptr);
        }
        else
        {
            node *ptr = new node;
            ptr->data = s[i];
            ptr->right = NULL;
            ptr->left = NULL;
            ptr->parent = NULL;
            node *ptr1 = st.top();
            st.pop();
            node *ptr2 = st.top();
            st.pop();
            make_tree(ptr2,ptr,ptr1);
            st.push(ptr);
        }
        
    }
    return st.top();
}

int eval(node* root)
{
    if(root->left==NULL||root->right==NULL)
    return toint(root->data);

    else
    {
        int l_value = eval(root->left);
        int r_value = eval(root->right);
        if((root->data[0])=='+') return l_value + r_value;
        if((root->data[0])=='-') return l_value - r_value;
        if((root->data[0])=='*') return l_value * r_value;
        if((root->data[0])=='/') return l_value / r_value;
        if((root->data[0])=='^') return pow(l_value,r_value);
        cout<<"operator not found";

        return 0;
    }
    
    
}

bool isOperator(string s)
{
    switch(s[0])
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        case '(': return true;
        default: return false;
    }
}

bool isOperant(string s)
{
    if((s[0]<='9'&&s[0]>='0')||((s[0]=='-')&&(s.size()>1)&&s[1]<='9'&&s[1]>='0'))  return true;
    else return false;
}

int inPrec(string s) 
{ 
    char input = s[0];
    switch (input) { 
    case '+': 
    case '-': 
        return 2; 
    case '*': 
    case '%': 
    case '/': 
        return 4; 
    case '^': 
        return 5; 
    case '(': 
        return 0; 
    default: return -1;
    } 
} 

int outPrec(string s) 
{ 
    char input = s[0];
    switch (input) { 
    case '+': 
    case '-': 
        return 1; 
    case '*': 
    case '%': 
    case '/': 
        return 3; 
    case '^': 
        return 6; 
    case '(': 
        return 100; 
    default: return -1;
    } 
} 


string substitude(RBTree &memory,string key)
{
    return memory.search(key);
}

bool isVariable(string s)
{
    if (s[0]>='a'&&s[0]<='z'||s[0]<='A'&&s[0]>='Z') return true;
    else return false;
}

vector<string> intToPost(vector<string> s,RBTree& memory)
{

    stack<string> st;
    vector<string> ans;
    int l = s.size();
    for(int i = 0;i<l;i++)
    {
        if(isOperant(s[i]))   ans.push_back(s[i]);
        else if(isVariable(s[i])) ans.push_back(substitude(memory,s[i]));
        else if(isOperator(s[i])) 
        {
            if(st.empty()||outPrec(s[i]) > inPrec(st.top()))  st.push(s[i]);
            else 
            {
                while( (!st.empty()) && (inPrec(st.top())  > outPrec(s[i])) )
                {
                ans.push_back(st.top());
                st.pop();
                }
                st.push(s[i]);
            }

        }
        else if(s[i][0]==')')
        {
         while(st.top()[0]!='(')
         {
             ans.push_back(st.top());
             st.pop();

             if(st.empty())
             {
                 indicator = 1;
                 return ans;
             }

         }
         st.pop();

        }

    }

     while (!st.empty()) { 
        if (st.top()[0] == '(') { 
            indicator = 1;
            return ans;
        } 
        ans.push_back(st.top());
        st.pop(); 
    }
    return ans;
}



void print_tree(node * root)
{
    if(root==NULL)  return;
    else{
        print_tree(root->left);
        cout<<root->data<<",";
        print_tree(root->right);

    }
}

void parse_assignment_statement(RBTree &memory,string input)
{
    int found = input.find("=");
    string variable = "";
    for(int i = 0;i < found;i++)
    {
        variable.push_back(input[i]);
    }
    string output = "";
    int size = input.length();
    for(int i = found+1;i<size;i++)
    {
        output.push_back(input[i]);
    }
    vector<string> output_1 = parse_string(output);
    indicator = 0;
    vector<string> output_2 = intToPost(output_1,memory);
    if(indicator ==  0)       
    {   
        int ans;
        node* root = built_tree(output_2);
        ans = eval(root);
        memory.insert(variable,to_string(ans));
        return;
    }
    return ;
}


int main(void)
{
    int n;
    cin>>n; //no of test case
    RBTree memory;
    for(int i = 0;i<n;i++)
    {
        int k;
        cin>>k; //no of line in each test case
        
        
        for(int j = 0;j<k;j++)
        {
            string s;
            cin>>s;
            if(is_assignment(s))
            {
                indicator = 0;
                parse_assignment_statement(memory,s);
                if(indicator == 1)
                {
                    cout<<"CANT BE EVALUATED\n";
                    continue;
                }
                continue;
            }

            vector<string> output = parse_string(s);
            indicator = 0;
        
            vector<string> output2 = intToPost(output,memory);
            if(indicator == 1) 
            {
                cout<<"CANT BE EVALUTED\n";
                continue;
            }
            
            node* root = built_tree(output2);
            cout<<eval(root)<<"\n";
            
        }

        memory.clear_all(); //free all the node
        memory.reuse();// make root null so that memory can be reused
    }
    return 0;
}


