#include<bits/stdc++.h>

using namespace std;



vector<pair<int,int>> find_neighbour(int **ar,int **mark, int i, int j,int m,int n)
{
    vector<pair<int,int>> neighbour;
    int c = ar[i][j];
    if((i < n-1) && (ar[i+1][j] == c) && mark[i+1][j] == 0) neighbour.push_back(make_pair(i+1,j));
    if((i > 0) &&(ar[i-1][j] == c) && mark[i-1][j] == 0) neighbour.push_back(make_pair(i-1,j));
    if((j < m-1) &&(ar[i][j+1] == c) && mark[i][j+1] == 0) neighbour.push_back(make_pair(i,j+1));
    if((j > 0) &&(ar[i][j-1] == c) && mark[i][j-1] == 0) neighbour.push_back(make_pair(i,j-1));
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
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            cin>>k;
            ar[i][j] = k;
        }
    }
    int size = 0;
    int color = 0;
     for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(mark[i][j] == 1)
            {
                continue;
            }
            mark[i][j] = 1;
            int new_size = size_block(ar,mark,m,n,i,j);
            if(new_size > size)
            {
                size = new_size;
                color = ar[i][j];
            }
        }
    }
    cout<<size+1<<" "<<color<<"\n";
}