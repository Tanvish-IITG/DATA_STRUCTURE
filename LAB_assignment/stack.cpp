#include<bits/stdc++.h>

using namespace std;

struct NODE
{
    int x;
    NODE * next;
    NODE * prev;
};
class Stack
{
NODE* start = NULL;
public:

void push(int x)
{
    NODE* ptr = new NODE;
    ptr->x = x;
    ptr->next = NULL;
    ptr->prev = NULL;
    if(start == NULL)
    {
        start = ptr;
    }
    else
    {
        ptr->next = start;
        start->prev = ptr;
        start = ptr;
    }
}
void pop()
{
    if(start==NULL) return;
    else if(start->next==NULL)
    {
        delete start;
        start = NULL;
    }
    else
    {
        NODE* temp = start;
        start = start->next;
        start->prev = NULL;
        delete temp;
    }
}
int peek()
{
    return start->x;
}
bool empty()
{
    return (start == NULL);
}
};
typedef vector<pair<vector<int>,int>> Graphs;

bool is_bipartite(Graphs &graph, int start)
{
    int color = 1;
    Stack st;
    vector<int> v = graph[start].first;
    graph[start].second = 1;
    if(v.size() == 0)
    {
        return true;
    }
    for(auto X:v)
    {
        graph[X].second = 2;
        st.push(X);
    }
    while(!st.empty())
    {
        int node = st.peek();
        st.pop();
        color = graph[node].second;
        if(color == 1) color = 2;
        else if(color == 2) color = 1;
        vector<int> neighbour = graph[node].first;
        for(auto X:neighbour)
        {
            if(graph[X].second == 0)
            {
                graph[X].second = color;
                st.push(X);
            }
            else if(graph[X].second != color)
            {
                return false;
            }
        }

    }
    return true;
}


int main(void)
{
    int n,m ; // number of vertices and number of edges
    cin>>n>>m;
    Graphs graph;
    for(int i=0;i<n;i++)
    {
        graph.push_back(make_pair(vector<int>{},0));
    }
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].first.push_back(b);
        graph[b].first.push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        if(graph[i].second == 0)
        {
            bool val = is_bipartite(graph,i);
            if(val==false)
            {
                cout<<"NO\n";
                exit(0);
            }
        }
    }
    cout<<"YES\n";
    return 0;
    
}