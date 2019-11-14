#include<bits/stdc++.h>

using namespace std;


struct Edges
{
    int weight;
    int start;
    int end;
};
struct compare_weight
{
    bool operator()(Edges const& p1, Edges const& p2) 
    { 
        // return "true" if "p1" is ordered  
        // before "p2", for example: 
        return p1.weight > p2.weight; 
    } 
};
typedef priority_queue<Edges,vector<Edges>,compare_weight> Data;

void showpq(Data gq) 
{ 
    Data g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.top().weight; 
        g.pop(); 
    } 
    cout << '\n'; 
} 


int main()
{
    int m,n;
    cin>>n>>m;
    int graph[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            graph[i][j] = 0;
            else
            {
                graph[i][j] = INT_MAX;
            }
            
        }
    }
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        graph[a][b] = w;
        graph[b][a] = w;
    }
    Data p;
    bool visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }
    for(int i=0;i<n;i++)
    {
        if(graph[0][i]!=INT_MAX && i!=0)
        {
        p.push(Edges {graph[0][i],0,i});
        }
    }
    visited[0] = true;
    for(int i=1;i<n;i++)
    {
        Edges e = p.top();
        cout<<e.start<<"  "<<e.end<<" "<<e.weight<<"\n";
        p.pop();
        int a;
        if(visited[e.start] == false)
        {
            a = e.start;
        }
        else
        {
            a = e.end;
        }
        visited[a] = true;
        for(int i=0;i<n;i++)
        {
            if(graph[a][i]!=INT_MAX && visited[i] == false && i!=a)
        {
            p.push(Edges {graph[a][i],a,i});

        }
        }
    }
    

}