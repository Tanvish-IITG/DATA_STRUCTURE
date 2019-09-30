#include<bits/stdc++.h>

using namespace std;

struct point{
    long int x;
    long int y;
}p0;

point next_to_top(stack<point> s)
{
    if(s.size()>=2)
    {
        point temp = s.top();
        s.pop();
        point ans = s.top();
        s.push(temp);
        return ans;
    }
    else
    {
        point temp = {0,0};
        return temp;
    }
}
int distsquare(point p1,point p2)
{
    return (p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y);
}

int orientation(point p1,point p2,point p3)
{
    int o = (p2.y-p1.y)*(p3.x-p2.x) - (p2.x-p1.x)*(p3.y-p2.y);
    if(o==0) return 0;
    return o>0?1:2;
    //0 for linear
    //1 for clockwise
    //2 for counterclockwise
}
bool compare(point p1,point p2)
{
    int o = orientation(p0,p1,p2);
    if(o==0)
    {
        return (distsquare(p0,p1) >= distsquare(p0,p2)) ? 0:1;
    }
    return (o==2)?1:0;
}





int main(void)
{
    int n;
    cin>>n;
    point ar[n];
    for(int i = 0;i < n;i++)
    {
        cin>>ar[i].x>>ar[i].y;
    }
    int min =  0 ;
    long int ymin = ar[0].y;
    for(int i = 1;i<n;i++)
    {
        long int ytemp = ar[i].y;
        if(ytemp < ymin || ytemp==ymin && ar[i].x < ar[min].x)
        {
            ymin = ytemp;
            min = i;
        }
    }
    swap(ar[0],ar[min]);
    p0 = ar[0];
    sort(ar+1,ar+n,compare);
    vector<point> newarr;
    newarr.push_back(ar[0]);
    for(int i = 1;i<n;i++)
    {
        if(i<n-1 && orientation(p0,ar[i],ar[i+1])==0)
        {
            continue;
        }
        newarr.push_back(ar[i]);
    } 
    int size = newarr.size();
    if(size<3) {
        cout<<"no convex hull possible";
        exit(0);
    }
    stack<point> s;
    s.push(newarr[0]);
    s.push(newarr[1]);
    s.push(newarr[2]);
    for(int i=3;i<size;i++)
    {
        while(orientation(next_to_top(s),s.top(),newarr[i])!=2)
        {
            s.pop();
        }
        s.push(newarr[i]);
    }
    cout<<s.size()<<"\n";
    vector<point>  output;
    while(!s.empty())
    {
        point outputpoint = s.top();
        s.pop();
        output.push_back(outputpoint);
    }
    int l= output.size();
    long int min_x = output[0].x;
    int pos = 0;

    for(int i = 0;i<l;i++)
    {
        if(output[i].x < min_x)
        {
            min_x = output[i].x;
            pos = i;
        }
    }
    for(int i = pos;i<l;i++)
    {
        cout<<output[i].x<<" "<<output[i].y<<"\n";
    }
    for(int i = 0;i<pos;i++)
    {
        cout<<output[i].x<<" "<<output[i].y<<"\n";
    }
    return 0;

    
}