#include<bits/stdc++.h>

using namespace std;

struct Node
    {
        int n;
        Node* next;
        Node* prev;
        Node(int n)
        {
            this->n = n;
            this->next = NULL;
            this->prev = NULL;
        }
    };

class HashingTable
{
    int bucket;
    Node** arr;
    int hashing_function(int n)
    {
    return n%bucket;
    }
    public:
    HashingTable(int n)
    {
        this->bucket = n;
        arr = new Node*[bucket];
        for(int i = 0;i<n;i++)
        {
            arr[i] = NULL;
        }

    }
    void insert(int n)
    {
        int index = hashing_function(n);
        if(arr[index] == NULL)
        {
            Node* newnode = new Node(n);
            arr[index] = newnode;
        }
        else
        {
            Node* temp = arr[index];
            while(temp->next!=NULL)
            {
                if(temp->n == n)
                {
                    return;
                }
                temp = temp->next;
            }
            if(temp->n == n) return;
            Node* newnode = new Node(n);
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
    void delete_element(int n)
    {
            int index = hashing_function(n);
            Node* start = arr[index];
             if(start == NULL)
            {
            cout<<-1<<"\n";
            return;
            }
            Node* temp=start;
            if(temp->n==n)
            {
                start = temp->next;
                if(temp->next != NULL)
                temp->next->prev = NULL;
                arr[index] = start;
                return;
            }
            while(temp->next!=NULL)
            {
                    if(temp->n==n)
                {
                    (temp->prev)->next = temp->next;
                    (temp->next)->prev = temp->prev;
                    delete temp;
                    return;
                }
                temp = temp->next;
            }
            if(temp->n==n)
            {
                (temp->prev)->next = NULL;
                delete temp;
                return;
            }
        cout<<-1<<"\n";

    }
    void display()
    {
        for(int i=0;i<bucket;i++)
        {
            if(arr[i] == NULL)
                cout<<"NULL";
        else
        {
            Node* temp = arr[i];
            while(temp->next!=NULL)
            {
                cout<<temp->n<<"->";
                temp = temp->next;
            }
            cout<<temp->n;
        }
        cout<<"\n";
        }
    }
    bool search(int n)
    {
        int i = hashing_function(n);
        if(arr[i] == NULL)
            return false;
        else
        {
            Node* temp = arr[i];
            while(temp->next!=NULL)
            {
                if(temp->n==n) return true;
                temp = temp->next;
            }
            if(temp->n==n) return true;
            return false;
        }
    }
};

int main()
{
    int bucket,c,e;
    cin>>bucket;
    HashingTable hash(bucket);
    cout<<"1.insert\n2.delete\n3.display\n4.search\n";
    while(1)
    {
    cin>>c;
    switch(c)
    {
        case 1:cin>>e; hash.insert(e); break;
        case 2:cin>>e; hash.delete_element(e); break;
        case 3:cout<<"\n";hash.display();break;
        case 4:cin>>c;if(hash.search(c)) cout<<"element found\n"; else cout<<"not found\n"; break;
        default: exit(0);
    }
    }
    return 0;
}