#include<bits/stdc++.h>

using namespace std;

//we are implementing kruskal algorithm
long long int MAX = 1000000007;
struct Edges{
    int start;
    int end;
    long long int  weight;
};

bool comp(Edges e1,Edges e2)
{
    if(e1.weight > e2.weight)
    return true;
    else
    {
        return false;
    }
    
}

int find_parent(int i,int ar[][2])
{
    if(ar[i][0] == -1) return i;
    else{
        ar[i][0] = find_parent(ar[i][0],ar);
        return ar[i][0];
    }
}
void Union_set(int r1,int r2, int ar[][2])
{
    if(ar[r1][1] > ar[r2][1])
    ar[r2][0] = r1;
    else if(ar[r1][1] < ar[r2][1])
    ar[r1][0] = r2;
    else
    {
        ar[r1][0] = r2;
        ar[r1][1]++;
    }
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    int ar[n+1][2];
    Edges edges[m];
    for(int i = 0;i<=n;i++)
    {
        ar[i][0] = -1; //parent
        ar[i][1] =  0; //rank
    }
    for(int i = 0;i<m;i++)
    {
        cin>>edges[i].start>>edges[i].end>>edges[i].weight;
    }
    long long product = 1;
    sort(edges,edges+m,&comp);
    for(auto e:edges)
    {
        int p1 = find_parent(e.start,ar);
        int p2 = find_parent(e.end,ar);
        if(p1 != p2)
        {
            product = ((product*e.weight)%MAX+MAX)%(MAX);
            Union_set(p1,p2,ar);
        }
    }
    cout<<product<<"\n";
    return 0;
}