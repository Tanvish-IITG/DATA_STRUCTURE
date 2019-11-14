
#include <bits/stdc++.h> 
using namespace std; 


#define INF 99999

void printSolution(int **dist,int V);


void floydWarshall (int ** dist,int V) 
{ 

	for (int k = 0; k < V; k++) 
	{ 
		for (int i = 0; i < V; i++) 
		{ 
		
			for (int j = 0; j < V; j++) 
			{ 
				if (dist[i][k] + dist[k][j] < dist[i][j]) 
					dist[i][j] = dist[i][k] + dist[k][j]; 
			} 
		} 
	} 

	// Print the shortest distance matrix 
	printSolution(dist,V); 
} 

/* A utility function to print solution */
void printSolution(int **dist,int V) 
{ 
	cout<<"The following matrix shows the shortest distances"
			" between every pair of vertices \n"; 
	for (int i = 0; i < V; i++) 
	{ 
		for (int j = 0; j < V; j++) 
		{ 
			if (dist[i][j] == INF) 
				cout<<"INF"<<"	 "; 
			else
				cout<<dist[i][j]<<"	 "; 
		} 
		cout<<endl; 
	} 
} 

// Driver code 
int main() 
{ 
    int n;
    cin>>n;
    int ** dist = new int*[n];
    for(int i= 0;i<n;i++)
    {
        dist[i] = new int[n];
    }
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j) dist[i][j] = 0;
            else
            dist[i][j] = INF;
        }
    }
	int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int s,e,w;
        cin>>s>>e>>w;
        dist[s][e] = w;
        dist[e][s] = w;
     }

	// Print the solution 
	floydWarshall(dist,n); 
	return 0; 
} 

// This code is contributed by rathbhupendra 
