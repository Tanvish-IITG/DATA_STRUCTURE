#include<bits/stdc++.h>

using namespace std;
typedef deque<int> num;

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
bool compare(num a,num b)
{
    int la = a.size();
    int lb = b.size();
    if(la>lb) return true;
    if(lb>la) return false;
    for(int i= 0;i<la;i++)
    {
        if(a[i]>b[i]) return true;
        if(a[i]<b[i]) return false;

    }
    return true;
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

{   
    num temp = b;
    for(int i = 0;i<(a.size()-b.size());i++)

        {

            temp.push_front(0);

        }

    deque<int> b1 = complement(temp);

    deque<int> b2 = addnum(b1,{1});

    deque<int> b3 = addnum(b1,a);

    b3 = addnum(b3,{1});
    b3.pop_front();
    while(true){
    if((b3[0]==0)&&(b3.size()!=1)) 
    {
        b3.pop_front();
        continue;
    }
    break;
    }
    return b3;



}
num subtract_num(num a,num b)
{
    if(compare(a,b))
    {
        num ans = sub(a,b);
        return ans;
    }
    else
    {
        num ans = sub(b,a);
        ans[0] = ans[0]*(-1);
        return ans;
    }
}
int q = 0;
num div(num a,num b)
{   
    num temp = a;
    num b_tem = subtract_num(b,{1});
    if(compare(b_tem,a)) 
    {
        q = 0;
        return a;
    }
    q = 0;
    while(compare(temp,b)) 
    {
        q++;
        temp = sub(temp,b);
    }
    while(true){
    if((temp[0]==0)&&(temp.size()!=1)) 
    {
        temp.pop_front();
        continue;
    }
    break;
    }

    return temp;


}

vector<num> division(num a,num b)
{
    if(compare(a,b))
    {
        int la = a.size();
        int lb = b.size();

    
    int count = 0;
    num temp_divisor={};
    for(auto X:a)
    {   
        if(compare(b,temp_divisor))
        {
            temp_divisor.push_back(X);
            count++;
        }
        else
        {
            break;
        }
        

    }
    int limit = la - count + 1;
    num q_final;
    num r;
    num b_temp = subtract_num(b,{1});
    for(int i = 0;i<limit;i++)
    {
        q = 0;
        r = div(temp_divisor,b);
        q_final.push_back(q);
        temp_divisor = r;
        temp_divisor.push_back(a[count]);
        
        count++;

    }
    //display(q_final);
    //display(r);
    vector<num> w = {q_final,r};
    return w;
    
}

else {
    q = 0;
    num ans = div(a,b);
    
    //cout<<q;
    //display(ans);
    vector<num> w = {{0},ans};
    return w;
}

}
bool find_abs(num a,num b)
{
    num temp = subtract_num(a,b);
    if(temp[0]<0) temp[0]= temp[0]*-1;
    if(compare(temp,{2})) return true;
    return false;

}
num evaluate(num r1,num a)
{
    auto temp = division(a,r1);
    num temp1 = temp[0];
    num temp3 = addnum(temp1,r1);
    temp = division(temp3,{2});
    return temp[0];
}



num sqrt_(num a)
{
    auto temp = division(a,{2});
    num r1 = temp[0];
    num r2 = r1;
    do
    {
        r1 = r2;
        r2 = evaluate(r1,a);
        
    } while (find_abs(r2,r1));
    return r2;
    
}

bool is_prime(num a)
{
    if(compare({1},a)) return false;
    if(compare({3},a)) return true;
    auto temp1 = division(a,{2});
    if(temp1[1][0]==0) return false;
    temp1 = division(a,{3});
    if(temp1[1][0]==0) return false;
    num limit = sqrt_(a);
    limit = addnum(limit,{6});
    for(num i = {6};compare(limit,i);i = addnum(i,{6}))
    {
        num check1 = sub(i,{1});
        auto temp = division(a,check1);
        if(temp[1][0]==0) return false;
        num check2 = addnum(i,{1});
        temp = division(a,check2);
        if(temp[1][0]==0) return false;
    }
    return true;

}






int main(void)
{
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
    deque<int> a = input();
    //deque<int> b = input();
    //display(a);
    //display(b);
    if(is_prime(a)) cout<<"Prime"<<"\n";
    else cout<<"not Prime"<<"\n";
    }
    return 0;

}
