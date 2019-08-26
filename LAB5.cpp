#include<bits/stdc++.h>

using namespace std;

struct node
{
    node* left;
    node* right;
    string data;
    node* parent;
};

int indicator = 0; 

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

struct tree_node{
    string variable ;
    string number;
    tree_node* right;
    tree_node* left;
};

tree_node* initialize(string var,string no)
{
    tree_node * newnode = new tree_node;
    newnode->right = NULL;
    newnode->left = NULL;
    newnode->variable = var;
    newnode->number = no;
    return newnode;

}

void insert_m(tree_node** root,tree_node* insert)
{
    if(root==NULL) *root = insert;
    else if(insert->variable>(*root)->variable) insert_m(&((*root)->right),insert);
    else if(insert->variable<(*root)->variable) insert_m(&((*root)->left),insert);
    else (*root)->number = insert->number;

}

string search_m(tree_node* root,string var)
{
    if(root==NULL) 
    {
        indicator = 1;
        return "0";
    }
    if(!(root->variable.compare(var))) return root->number;
    else if(var>(root)->variable) search_m(root->right,var);
    else if(var<(root)->variable) search_m(root->left,var);
    
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


string substitude(vector<pair<string,int>> &memory,string key)
{
    int length = memory.size(); 
    for(int i = length-1;i>=0;i--)
    {
        if(!key.compare(memory[i].first))  return to_string(memory[i].second);
    }
    indicator = 1;
    return "0";
}

bool isVariable(string s)
{
    if (s[0]>='a'&&s[0]<='z'||s[0]<='A'&&s[0]>='Z') return true;
    else return false;
}

vector<string> intToPost(vector<string> s,vector<pair<string,int>> &memory)
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

void parse_assignment_statement(vector<pair<string,int>> &memory,string input)
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
        pair<string,int> temp = make_pair(variable, ans);
        memory.push_back(temp);
        return;
    }
    return ;
}


int main(void)
{
    int n;
    cin>>n; //no of test case
    for(int i = 0;i<n;i++)
    {
        int k;
        cin>>k; //no of line in each test case
        vector<pair<string,int>> memory;
        
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
    }
    return 0;
}


