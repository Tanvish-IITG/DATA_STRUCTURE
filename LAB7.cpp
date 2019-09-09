#include<bits/stdc++.h>

using namespace std;

bool compare(string,string);
void insertion_sort(string a[],int low,int high)
{
    for(int i=low+1;i<=high;i++)
    {
        int j = i-1;
        string temp = a[i];
                while(j>=0&&compare(a[j],temp))
                {   
                    a[j+1] = a[j];
                    j--;

                }
        a[j+1] = temp;
    }

    
}

bool compare(string a,string b)
{
        string temp = a.append(b);
        string temp2 = b.append(a);
        if(temp < temp2) return true;
        else return false;
}

int partition(string a[],int low,int high)
{
    string pivot = a[high];
    int i = low-1;
    int j = low;
    for(int t = low;t<high;t++)
    {
        if(compare(pivot,a[t]))
        {
            swap(a[i+1],a[j]);
            i++;
        }
        j++;


    }
    swap(a[i+1],a[high]);
    return i+1;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
}

void quick_sort(string a[],int low,int high)
{ 
    if(high-low<20)
    {
       insertion_sort(a,low,high);
        return;
    }
    int q = partition(a,low,high);
    quick_sort(a,q+1,high);
    quick_sort(a,low,q-1);
    return;


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

        static int max = array_of_inputs[0].length();

        for(int t = 0;t<number_of_inputs;t++)
        {
            
            if(max < array_of_inputs[t].length()) max = array_of_inputs[t].length();
        }

        quick_sort(array_of_inputs,0,number_of_inputs-1);
        for(int i = 0;i<number_of_inputs;i++)
        {
            cout<<array_of_inputs[i];
        }
        cout<<"\n";
        
    }


    return 0;
}