#include<bits/stdc++.h>

using namespace std;

vector<int> add(int a,int b, int c)
{
    vector<int> v = {(a+b+c)%10,(a+b+c)/10};
    return v;
}

deque<int> addnum(deque<int> a,deque<int> b)
{
    int la = int(a.size());
    int lb = int(b.size());;
     int l = max(la,lb);
    
    if(l == la)
    {
        for(int i = 0;i<(l-lb);i++)
        {
            b.push_front(0);
        }
    }
    else
    {
        for(int i = 0;i<(l-la);i++)
        {
            a.push_front(0);
        }
    }
    int c = 0;
    deque<int> ans;
    for(int i = l-1;i>=0;i--)
    {   
        
        vector<int> v = add(a[i],b[i],c);
        ans.push_back(v[0]);
        c = v[1];
        
    }
    if(c!=0)
    {
        ans.push_back(c);
    }
    reverse(begin(ans),end(ans));
    return ans;

   
}

deque<int> input()
{
    deque<int> num;
    string s;
    cin>>s;
    int i = 0;
    while(s[i]!='\0')
    {
        num.push_back(s[i]-'0');
        i++;
    }
    return num;


}

deque<int> complement(deque<int> a)
{
    deque<int> b;
    for(auto X:a)
    {
        b.push_back(9-X);
    }
    return b;
}

deque<int> sub(deque<int> a,deque<int> b)
{   for(int i = 0;i<(a.size()-b.size());i++)
        {
            b.push_front(0);
        }
    deque<int> b1 = complement(b);
    deque<int> b2 = addnum(b1,{1});
    deque<int> b3 = addnum(b1,a);
    b3 = addnum(b3,{1});
    b3.pop_front();
    return b3;

}

void display(deque<int> v)
{
    for(auto X:v)
    {
        cout<<X;
    }
    cout<<"\n";
}

int main(void)
{
    deque<int> a = input();
    deque<int> b = input();
    //display(a);
    //display(b);
    deque<int> c = sub(a,b);
    display(c);
    return 0;

}