#include<bits/stdc++.h>

using namespace std;

struct TRI_NODE
{
    map<char,TRI_NODE*>  children;
    char a;
    TRI_NODE(char c)
    {
        a=c;
    }


};

class Trie
{
    TRI_NODE* root;

    public:
    Trie()
    {
        root = new TRI_NODE('#');
    }
    void insert(string a)
    {
        TRI_NODE* TEMP = root;
        for(auto X:a)
        {
            if(!( TEMP->children.find(X) ==  TEMP->children.end()))
            {
                TEMP = TEMP->children[X];
            }
            else
            {
                TEMP->children.insert(pair<char,TRI_NODE*> (X,new TRI_NODE(X)));
                TEMP = TEMP->children[X];
            }
        }
    }  
    bool search(string a)
    {
        TRI_NODE* TEMP = root;
        for(auto X:a)
        {
            if(!( TEMP->children.find(X) ==  TEMP->children.end()))
            {
                TEMP = TEMP->children[X];
            }
            else
            {
                return false;
            }
        }
        return true;
    } 
};

int main()
{
    int n;
    cin>>n;
    Trie t;
    for(int i =0;i<n;i++)
    {
        string s,r;
        cin>>s;
        r=s;
        reverse(r.begin(),r.end());
        r.push_back('$');
        s.push_back('$');
        if(s==r) continue;
        else if(t.search(r))  
        {
            cout<<"TRUE\n";
            exit(0);
        }

        else
        {
            t.insert(s);
        }
        
        
    }
    cout<<"FALSE\n";
    return 0;
}