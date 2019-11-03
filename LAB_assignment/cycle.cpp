#include<bits/stdc++.h>

using namespace std;


struct node
{
    node* parent;
    int data;
    int rank;
    node(int data_)
    {
        data = data_;
        parent = NULL;
        rank = 0;
    }
};
typedef vector<pair<node* ,node* >> Graphs;

node* make_set(int data)
{
    node* newnode = new node(data);
    return newnode;
}

node* which_set(node* given_node)
{
    if(given_node->parent == NULL)
    {
        return given_node;
    }
    else
    {
        node* parent = which_set(given_node->parent);
        given_node->parent = parent;
        return parent; 
    }
}

void union_set(node* node1,node* node2)
{
    if(node1->rank > node2->rank)
    {
        node2->parent = node1;
    }
    else if(node1->rank < node2->rank)
    {
        node1->parent = node2; 
    }
    else
    {
        node1->parent = node2;
        node2->rank++;
    }
    
}

bool is_cycle_comonent(Graphs &graph)
{
    for(auto X:graph)
    {
        node* a = which_set(X.first);
        node* b = which_set(X.second);
        if(a==b)
        {
            return true;
        }
        else{
            union_set(a,b);
        }
    }
    return false;
}

int main(void)
{
    int n,m ; // number of vertices and number of edges
    cin>>n>>m;
    Graphs graph;
    node* arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = make_set(i);
    }

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        graph.push_back(make_pair(arr[a],arr[b]));
    }
    if(is_cycle_comonent(graph))
    cout<<"cycle found";
    else
    {
        cout<<"not found";
    }

}
    
