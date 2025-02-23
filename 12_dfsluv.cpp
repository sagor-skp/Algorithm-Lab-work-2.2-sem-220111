#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
bool vis[N];

void dfs(int vertex){
    //take action on vertex after
    //entering the vertex
    cout<<vertex<<" ";
    vis[vertex]=true;
    for(int child:g[vertex]){
            //cout<<"PAR"<<vertex<<",child "<<child<<endl;
            if(vis[child])continue;
            //take action on child before
            //entering the child node
        dfs(child);
         //take action on child after
         //exiting the child node
    }
    //take action on vertex before
         //exiting the vertex
}
int main()
{
    int n,m;//n->node,m->edge can varry
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
}
/*
vector<int> g[N];
N is defined as 1e5 + 10, which is 100010.
This line creates an array of 100010 vectors, where each vector can store a list of integers.

This structure is used to store the adjacency list of a graph.
Each index in the array represents a node in the graph.
g[i] contains a vector of all the nodes connected to node i.

Example: Consider the input:
5 4
1 2
1 3
2 4
3 5

The adjacency list representation will be:

g[1] = [2, 3]
g[2] = [1, 4]
g[3] = [1, 5]
g[4] = [2]
g[5] = [3]

bool vis[N];
It creates an array of 100010 boolean values, all initially set to false by default in global scope.

BFS Implementation:

Assumes a tree structure where m = n-1.
Only needs n because the edges are implicitly n-1.
DFS Implementation:

Handles a general graph where m can be any value.
Needs both n and m to fully describe the graph's connectivity.

*/
