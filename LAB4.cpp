#include<bits/stdc++.h>

using namespace std;

struct node
{
    string data;
    node* left;
    node* right;
    node* parent;
};

int indicator = 0; 

node* insert(string data,node * point,bool left)
{
    node * newnode = new node;
    newnode->right = NULL;
    newnode->left = NULL;
    newnode->parent = point;
    newnode->data = data;
    if(left) point->left = newnode;
    else point->right = newnode; 
    return newnode;
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
        if(s[j]=='+'||s[j]=='-'||s[j]=='*'||s[j]=='/'||s[j]=='('||s[j]==')'||s[j]=='^')
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
        if(s[i][0]<='9'&&s[i][0]>='0')
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
    if(s[0]<='9'&&s[0]>='0')  return true;
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

vector<string> intToPost(vector<string> s)
{

    stack<string> st;
    vector<string> ans;
    int l = s.size();
    for(int i = 0;i<l;i++)
    {
        if(isOperant(s[i]))   ans.push_back(s[i]);
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


int main(void)
{
    int n;
    cin>>n; //no of test case
    for(int i = 0;i<n;i++)
    {
        int k;
        cin>>k; //no of line in each test case
        for(int j = 0;j<k;j++)
        {
            string s;
            cin>>s;
            vector<string> output = parse_string(s);
            indicator = 0;
            vector<string> output2 = intToPost(output);
            if(indicator == 1) 
            {
                cout<<"CANT BE EVALUTED\n";
                continue;
            }
            node* root = built_tree(output2);
            cout<<eval(root)<<"\n";
        }
    }
    return 0;
}


