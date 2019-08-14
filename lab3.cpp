#include<bits/stdc++.h>

using namespace std;

int main(void)
{


    string str;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        stack<char> s;
        cin>>str;
        int counter = 1;
        int l = str.length();
        for(int j = 0;j < l;j++)
        {
            char t = str[j];
            if(t=='['||t=='{'||t=='('||t=='<') s.push(t);
            else if(t=='|'&&(!s.empty())&&s.top()=='|') s.pop();
            else if(t=='|') s.push('|');
            else if(t==']'&&(!s.empty())&&s.top()=='[') s.pop();
            else if(t=='}'&&(!s.empty())&&s.top()=='{') s.pop();
            else if(t==')'&&(!s.empty())&&s.top()=='(') s.pop();
            else if(t=='>'&&(!s.empty())&&s.top()=='<') s.pop();
            else 
            {
                cout<<"NO\n";
                counter = 0;
                break;
            }

        }
        if(counter == 0)
            continue;
        if(s.empty()) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
    return 0;
    


}