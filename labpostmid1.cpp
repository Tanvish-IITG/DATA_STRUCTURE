#include<bits/stdc++.h>

using namespace std;

int partition(int ar[],int n,int s,int l)
{
    int i = -1;
    int j = 0;
    for(int t =s;t<=l;t++)
    {
        if(ar[t] == n)
        {
            swap(ar[t],ar[l]);
            break;
        }
    }
    for(int k = s;k<=l;k++)
    {
        if(ar[k] < n)
        {
            swap(ar[k],ar[i+1]);
            i++;
        }
    }
    swap(ar[l],ar[i+1]);

    return i+1;
    
}

int blumb_selection(int ar[],int s,int l,int pos)
{
    if((l-s)<5)
    {
        int ar_temp[(l-s)+1];
        for(int j=s,i=0;j<=l;j++,i++)
        {
            ar_temp[i] = ar[j];
        }
        sort(ar_temp,ar_temp+l-s+1);
        return ar_temp[s+pos-1];
    }
    int ar_temp[(l-s)/5 + 1][5];
    int t=s;
    for(int i=0;i<(l-s)/5;i++)
    {
        for(int j=0;j<5;j++)
        {
            ar_temp[i][j] = ar[t];
            t++; 
        }
    }
    int i = 0;
    for(;t<=l;t++)
    {
        ar_temp[(l-s)/5][i] = ar[t];
        i++;
    }
    for(;i<5;i++)
    {
        ar_temp[(l-s)/5][i] = int(INFINITY);
    }
    for(int i=0;i<=(l-s)/5;i++)
    {
        sort(ar_temp[i],ar_temp[i]+5);
    }


    int ar_new[(l-s)/5 + 1];
    for(int x=0;x<(l-s)/5;x++)
    {
        ar_new[x] = ar_temp[x][2];
    }
    int no_of_elements_in_the_last_array = (l-s+1)%5;
    if(no_of_elements_in_the_last_array!=0)
    {
        if(no_of_elements_in_the_last_array%2==0)
         ar_new[(l-s)/5] = ar_temp[(l-s)/5][no_of_elements_in_the_last_array/2 - 1];
        else
        {
            ar_new[(l-s)/5] = ar_temp[(l-s)/5][no_of_elements_in_the_last_array/2];
        }
        
    }
    else
    {
        ar_new[(l-s)/5] = ar_temp[(l-s)/5][2];
    }
    
    /*for(int i=0;i<=(l-s)/5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<ar_temp[i][j]<<" ";
        }
        cout<<"\n";
    }
     for(int i=0;i<=(l-s)/5;i++)
    {
        cout<<ar_new[i]<<" ";
    }
    */
    int size_of_medians = (l-s)/5 + 1;
    int median_of_medians;
    if(size_of_medians%2!=0)
        median_of_medians = blumb_selection(ar_new,0,(l-s)/5, ((l-s)/5+1)/2 + 1);
    else
    {
        median_of_medians = blumb_selection(ar_new,0,(l-s)/5, ((l-s)/5+1)/2);
    }
    int p = partition(ar,median_of_medians,s,l);
    //for(int z = s;z<=l;z++){
    //    cout<<ar[z]<<" ";
    //}
    //cout<<"\n"<<p;
    if(p == pos) return ar[p];
    else if(p>pos)  return blumb_selection(ar,s,p-1,pos);
    else return blumb_selection(ar,p+1,l,pos-p+1);
    

    

}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no_of_points;
        cin>>no_of_points;
        int ar[no_of_points][2];
        int ar_dis[no_of_points];
        for(int j=0;j<no_of_points;j++)
        {
            cin>>ar[j][0]>>ar[j][1];
            ar_dis[j] = ar[j][0]*ar[j][0] + ar[j][1]*ar[j][1];

        }
        cout<<"\n"<<blumb_selection(ar_dis,0,no_of_points-1,8);
    }
}