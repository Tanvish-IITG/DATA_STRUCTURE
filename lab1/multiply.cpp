#include<bits/stdc++.h>

using namespace std;

vector<int> add(int a,int b, int c)
{
    vector<int> v = {(a+b+c)%10,(a+b+c)/10};
    return v;
}
void display(deque<int> v)
{
    for(auto X:v)
    {
        cout<<X;
    }
    cout<<"\n";
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

vector<int> mult(int a,int b,int c)
{
    vector<int> v = {(a*b + c)%10,(a*b + c)/10};
    return v;

}

deque<int> multnum(deque<int> a,deque<int> b)
{
    int la = a.size();
    int lb = b.size();
    int c = 0;
    deque<int> ans = {0};
    for(int i = la - 1;i>=0;i--)
    {   deque<int> sum;
        for(int j = lb - 1;j>=0;j--)
        {
            vector<int> v = mult(a[i],b[j],c);
            c = v[1];
            sum.push_front(v[0]);



        }
        sum.push_front(c);
        for(int k = 0;k<la-i-1;k++)
        sum.push_back(0);
        ans = addnum(ans,sum);
    
    }
    if(ans[0]==0)
    {
        ans.pop_front();
    }
    return ans;
    
}




int main(void)
{
    int n;

    cin>>n;

    for(int i = 0;i<n;i++)

    {
    deque<int> a = input();
    deque<int> b = input();
    //display(a);
    //display(b);
    deque<int> c = multnum(a,b);
    display(c);
    }
    return 0;

}
