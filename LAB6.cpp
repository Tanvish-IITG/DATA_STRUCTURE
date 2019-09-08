#include<bits/stdc++.h>

using namespace std;

typedef int input;
bool comp(pair<int,int> a1,pair<int,int> a2)
{
    if(a1.first>a2.first) return false;
    else return true;
}


int binary_search(vector<pair<int,int>> v,int l,int r,int n)
{
    int mid = (l+r)/2;
    if(v[mid].first == n)
    {
        return mid;
    }
    else if(v[mid].first<n)
    {
        l=mid+1;
        return binary_search(v,l,r,n);
    }
    else if(v[mid].first > n)
    {
        r=mid-1;
        return binary_search(v,l,r,n);
    }
    return mid;
}


int main()
{
    int n;
    int no_test_cases;
    cin>>no_test_cases>>n;
    int arr[no_test_cases][3];
    vector<pair<int,int>> memory;
    int c;
    int user_id;
    for(input i=0;i<no_test_cases;i++)
    {
        cin>>c;
        if(c==1)
        {
            int balance;
            cin>>user_id;
            cin>>balance;
            pair<int,int> user = make_pair(user_id,0);
            memory.push_back(user);
            arr[i][0] = 1;
            arr[i][1] = user_id;
            arr[i][2] = balance;

        }
        else if(c==2)
        {
            arr[i][0] = 2;
            arr[i][1] = 0;
            arr[i][2] = 0;
        }
    }
    int max = 0;
    int winner = -1;

    sort(memory.begin(),memory.end(),&comp);

    for(int i=0;i<no_test_cases;i++)
    {
        if(arr[i][0]==1)
        {
            int x = binary_search(memory,0,memory.size()-1,arr[i][1]);
            if(x!=-1)
            memory[x].second+=arr[i][2];
            if(memory[x].second > max)
            {
                max = memory[x].second;
                winner = x;
            }
        }
        else if(arr[i][0]==2)
        {
            if(winner!=-1)
            cout<<winner<<"\n";
            else
            {
                cout<<"data unavailable\n";
            }
            
        }
    }



return 0;
        
}

