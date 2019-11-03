#include<bits/stdc++.h>

using namespace std;

struct NODE
{
    int x;
    int y;
    NODE * next;
    NODE * prev;
};
NODE* start = NULL;

void AddFirst(int x,int y)
{
    NODE* ptr = new NODE;
    ptr->x = x;
    ptr->y = y;
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
void DelFirst()
{
    if(start==NULL) cout<<-1<<"\n";
    else if(start->next==NULL)
    {
        delete start;
        start = NULL;
    }
    else
    {
        NODE* temp = start;
        start = start->next;
        start->prev == NULL;
        delete temp;
    }
    

}

void Del(int x,int y)
{
    if(start == NULL)
    {
        cout<<-1<<"\n";
        return;
    }
    NODE* temp=start;
    if(temp->x==x&&temp->y==y)
    {
        DelFirst();
        return;
    }
    if(temp->next!=NULL) temp = temp->next;
    while(temp->next!=NULL)
    {
        if(temp->x==x&&temp->y==y)
        {
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            delete temp;
            return;
        }
        temp = temp->next;
    }
    if(temp->x==x&&temp->y==y)
        {
            (temp->prev)->next = NULL;
            delete temp;
            return;
        }
    cout<<-1<<"\n";


}
void search(float d)
{
    int is_found = 0;
    if(start == NULL)
    {
        cout<<-1<<"\n";
        return;
    }
    NODE* temp=start;
    while(temp->next!=NULL)
    {
        int x = temp->x;
        int y = temp->y;
        if(x*x+y*y<=d*d)
        {
            is_found++;
            cout<<"("<<x<<","<<y<<")  ";
        }
        temp = temp->next;
    }
    int x = temp->x;
    int y = temp->y;
    if(x*x+y*y<=d*d)
        {
            is_found++;
            cout<<"("<<x<<","<<y<<") ";
            
        }
    if(!is_found) cout<<-1;
    else cout<<is_found;
    cout<<"\n";



}
int search(int x,int y)
{
    if(start == NULL)
    {
        return false;
    }
    NODE* temp=start;
    while(temp->next!=NULL)
    {
        
        if((temp->x==x)&&(temp->y==y))
        {
            return true;
        }
        temp = temp->next;
    }
    if((temp->x==x)&&(temp->y==y))
        {
            return true;
        }
    return false;


}
int length()
{
    if(start == NULL)
    {
        return 0;
    }
    NODE* temp=start;
    int count = 1;
    while(temp->next!=NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;


}

int main(void)
{
    int n,c,a,b;
    float d;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c;
        switch(c)
        {
            case 1:cin>>a>>b;AddFirst(a,b);break;
            case 2:DelFirst();break;
            case 3:cin>>a>>b;Del(a,b);break;
            case 4:cin>>d;search(d);break;
            case 5:cin>>a>>b;cout<<(search(a,b)?"True":"False")<<"\n";break;
            case 6:cout<<length()<<"\n";break;
            default:cout<<"\nunexpected input terminating programme \n ";exit(0);break;

        }
    }
    return 0;

}