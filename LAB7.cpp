#include<bits/stdc++.h>

using namespace std;

bool compare(int,string,string);
void insertion_sort(string a[],int low,int high,int index)
{
    for(int i=low+1;i<high;i++)
    {
        int j = i-1;
        string temp = a[i];
                while(j>=0&&compare(index,a[j],temp))
                {   
                    a[j+1] = a[j];
                    j--;

                }
        a[j+1] = temp;
    }

    
}

bool compare(int i,string a,string b)
{
    if(a.size() >= i && b.size() >= i)
    {
        if(a[i]>=b[i]) return false;
        else return true;
    }
    else if(a.size() >= i)
    {
        if(a[i]>=b[b.size()-1]) return false;
        else return true;
    }
    else if(a.size() >= i)
    {
        if(b[i]>=a[a.size()-1]) return false;
        else return true;
    }
    return false;
}

int partition(string a[],int low,int high,int index)
{
    string pivot = a[high];
    int i = low-1;
    int j = low;
    for(int t = low;t<high;t++)
    {
        if(compare(index,pivot,a[t]))
        {
            swap(a[i+1],a[j]);
            i++;
        }
        j++;


    }
    swap(a[i+1],a[high]);
    return i+1;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
}

void quick_sort(string a[],int low,int high,int index)
{ 
    if(low-high<20)
    {
       insertion_sort(a,low,high,index);
        return;
    }
    int q = partition(a,low,high,index);
    quick_sort(a,q+1,high,index);
    quick_sort(a,low,q-1,index);
    return;


}
void radix_sort_reverse(string a[],int size,int max)
{
    for(int i = 0;i<max;i++)
    {
        quick_sort(a,0,size-1,i);

    }
}
int main(void)
{
    int number_of_test_cases;
    cin>>number_of_test_cases;
    for(int i = 0;i<number_of_test_cases;i++)
    {
        int number_of_inputs;
        cin>>number_of_inputs;
        string array_of_inputs[number_of_inputs];

        for(int j=0;j<number_of_inputs;j++)
        {
            cin>>array_of_inputs[j];
        }


        partition(array_of_inputs,0,number_of_inputs-1,0);
        static int max = array_of_inputs[0].length();

        for(int t = 0;t<number_of_inputs;t++)
        {
            
            if(max < array_of_inputs[t].length()) max = array_of_inputs[t].length();
        }

        radix_sort_reverse(array_of_inputs,number_of_inputs,max);
        for(int temp = 0;temp<number_of_inputs;temp++)
        {
            cout<<array_of_inputs[temp];
        }
        
    }


    return 0;
}