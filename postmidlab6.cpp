#include<bits/stdc++.h>

using namespace std;

int primes = 555557;
int rand_arr[1000];
void randomize_rand()
{
    for(int i = 0;i<1000;i++)
        rand_arr[i] = rand()%1000;
}

// list of primes
int fun(char a)
{
    if(a>='a' && a<='z')
    {
        return a-'a';
    }
    if(a>='A' && a<='Z')
    {
        return a-'A'+26;
    }
    return 0;
}
int hashing_function(string s,int n)
{
    int answer = 0;
    int i = 0;
    for(auto X:s)
    {
        i=(i+1)%1000;
        answer += rand_arr[i]*fun(X);
    }
    return ((answer%primes+primes)%primes)%n;
}
struct Node
    {
        string s;
        Node* next;
        Node* prev;
        Node(string s)
        {
            this->s = s;
            this->next = NULL;
            this->prev = NULL;
        }
    };

class HashingTable
{
    int bucket;
    Node** arr;
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
    void insert(string s)
    {
        int index = hashing_function(s,bucket);
        if(arr[index] == NULL)
        {
            Node* newnode = new Node(s);
            arr[index] = newnode;
        }
        else
        {
            Node* temp = arr[index];
            while(temp->next!=NULL)
            {
                if(temp->s == s)
                {
                    return;
                }
                temp = temp->next;
            }
            if(temp->s == s) return;
            Node* newnode = new Node(s);
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
    void delete_element(string s)
    {
            int index = hashing_function(s,bucket);
            Node* start = arr[index];
             if(start == NULL)
            {
            cout<<-1<<"\n";
            return;
            }
            Node* temp=start;
            if(temp->s==s)
            {
                start = temp->next;
                if(temp->next != NULL)
                temp->next->prev = NULL;
                arr[index] = start;
                return;
            }
            while(temp->next!=NULL)
            {
                    if(temp->s==s)
                {
                    (temp->prev)->next = temp->next;
                    (temp->next)->prev = temp->prev;
                    delete temp;
                    return;
                }
                temp = temp->next;
            }
            if(temp->s==s)
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
                cout<<temp->s<<"->";
                temp = temp->next;
            }
            cout<<temp->s;
        }
        cout<<"\n";
        }
    }
    bool search(string s)
    {
        int i = hashing_function(s,bucket);
        if(arr[i] == NULL)
            return false;
        else
        {
            Node* temp = arr[i];
            while(temp->next!=NULL)
            {
                if(temp->s==s) return true;
                temp = temp->next;
            }
            if(temp->s==s) return true;
            return false;
        }
    }
};

bool is_palindrome(string s)
{
    string t = s;
    reverse(s.begin(),s.end());
    if(s==t) return true;
    else return false;


}

int main()
{
    int n;
    cin>>n;
    HashingTable H(n);
    randomize_rand();
    for(int i = 0;i<n;i++)
    {
        string s;
        cin>>s;
        if(is_palindrome(s)) continue;
        string r = s;
        reverse(r.begin(),r.end());
        if(H.search(r))
        {
            cout<<"YES\n";
            exit(0);
        }
        H.insert(s);
    }
    cout<<"NO\n";
}
