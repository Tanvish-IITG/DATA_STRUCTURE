#include<bits/stdc++.h>

using namespace std;



vector<pair<int,int>> find_neighbour(int **ar,int **mark, int i, int j,int m,int n)
{
    vector<pair<int,int>> neighbour;
    if((i < n-1) && (ar[i+1][j] == 1) && mark[i+1][j] == 0) neighbour.push_back(make_pair(i+1,j));
    if((i > 0) &&(ar[i-1][j] == 1) && mark[i-1][j] == 0) neighbour.push_back(make_pair(i-1,j));
    if((j < m-1) &&(ar[i][j+1] == 1) && mark[i][j+1] == 0) neighbour.push_back(make_pair(i,j+1));
    if((j > 0) &&(ar[i][j-1] == 1) && mark[i][j-1] == 0) neighbour.push_back(make_pair(i,j-1));
    return neighbour;
}

int size_block(int ** ar,int ** mark,int m,int n,int i ,int j)
{
    vector<pair<int,int>> neighbour = find_neighbour(ar,mark,i,j,m,n);
    if(neighbour.size() == 0)
    {
        return 0;
    }
    int size = neighbour.size();
    for(auto X:neighbour)
    {
        int x = X.first;
        int y = X.second;
        mark[x][y] = 1;
    }
    for(auto X:neighbour)
    {
        int x = X.first;
        int y = X.second;
        size += size_block(ar,mark,m,n,x,y);
    }
    return size;



}




int main()
{
    int m,n,k;
    cin>>n>>m;
    int** ar = new int*[n];
    for(int i = 0; i < n; ++i)
        ar[i] = new int[m];
    int** mark = new int*[n];
    for(int i = 0; i < n; ++i)
        mark[i] = new int[m];
    cin>>k;
    int x,y; // coordinate of points
    vector<pair<int,int>> node_to_be_transersed;
    for(int i = 0;i<k;i++)
    {
        cin>>x>>y;
        node_to_be_transersed.push_back(make_pair(x,y));
        ar[x][y] = 1;
    }
    int size = 0;
    for(auto X:node_to_be_transersed)
        {
            int i = X.first;
            int j = X.second;
            if(mark[i][j] == 1)
            {
                continue;
            }
            // find the neighbour
                mark[i][j] = 1;
                size = max(size,size_block(ar,mark,m,n,i,j));
    }
    cout<<size+1<<"\n";
}