#include<bits/stdc++.h>

using namespace std;

typedef deque<int> num;
void display(deque<int> v)

{

    for(auto X:v)

    {

        cout<<X;

    }

    cout<<"\n";

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
    num tem_b = subtract_num(b,{1});
    if(compare(tem_b,a)) 
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
    while(1){
    if((temp[0]==0)&&(temp.size()!=1)) 
    {
        temp.pop_front();
        continue;
    }
    break;
    }

    return temp;


}

num division(num a,num b)
{
    if(compare(a,b))
    {
        int la = a.size();
        int lb = b.size();

    
    int count = 0;
    num temp_divisor={};
    num temp_b = subtract_num(b,{1}); 
    for(auto X:a)
    {   
        if(compare(temp_b,temp_divisor))
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
    for(int i = 0;i<limit;i++)
    {
        q = 0;
        r = div(temp_divisor,b);
        q_final.push_back(q);
        temp_divisor = r;
        temp_divisor.push_back(a[count]);
        
        count++;

    }
    display(q_final);
    display(r);
    return r;
    
}

else {
    q = 0;
    num ans = div(a,b);
    
    cout<<q<<"\n";
    display(ans);
    return ans;
}

}
int main(void)
{
    int n;

    cin>>n;

    for(int i = 0;i<n;i++)

    {
    num a = input();
    num b = input();
    num c = division(a,b);
    }
    return 0;
}
