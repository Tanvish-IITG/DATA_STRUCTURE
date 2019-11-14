#include<bits/stdc++.h>

using namespace std;

struct NODE
{
    int x;
    NODE * next;
    NODE * prev;
};

class que
{
NODE* start = NULL;
NODE *last = NULL;

public:
void push(int x)
{
    NODE* ptr = new NODE;
    ptr->x = x;
    ptr->next = NULL;
    ptr->prev = NULL;
    if(start == NULL && last == NULL)
    {
        start = ptr;
        last = ptr;
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
        last = NULL;
        return;
    }
    else
    {
        NODE* temp = last;
        last->prev->next = NULL;
        last = last->prev;
        delete temp;
    }
}
int peek()
{
    return last->x;
}
bool empty()
{
    if( start == NULL) return true;
    else return false;
}
void print()
{
    auto temp = start;

    while(temp!=NULL)
    {
        cout<<temp->x<<" ";
        temp = temp->next;
    }
}
};
typedef vector<pair<vector<int>,int>> Graphs;

void BFS(Graphs &graph, int start)
{
    int color = 1;
    que q;
    vector<int> v = graph[start].first;
    graph[start].second = 1;
    cout<<start<<" ";
    if(v.size() == 0)
    {
        cout<<start<<" ";
        return;
    }
    for(auto X:v)
    {
        graph[X].second = 1;
        q.push(X);
    }
    while(!q.empty())
    {
        int node = q.peek();
        cout<<node<<" ";
        q.pop();
        color = 1;
        vector<int> neighbour = graph[node].first;
        for(auto X:neighbour)
        {
            if(graph[X].second == 0)

            {
                graph[X].second = color;
                q.push(X);
            }
            else if(graph[X].second != color)
            {
                continue;
            }
        }

    }
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
    BFS(graph,0);
    return 0;
    
}