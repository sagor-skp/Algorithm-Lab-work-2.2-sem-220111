#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
//Creates an array of vectors
//to represent the adjacency
//list of the graph. Each node
// will have a list of its adjacent nodes stored in g[node].
int vis[N]={0};
//int level[N];
void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source]=1;//source is index

    while(!q.empty()){
        int cur_v=q.front();
        q.pop();
        cout<<cur_v<<" ";
        for(int child:g[cur_v]){
            if(!vis[child]){
                q.push(child);//value
                vis[child]=1;
            }
        }
    }
}
int main(){
    int n;
    cin>>n;//node,not take edge because edge fix=n-1
    for(int i=0;i<n-1;i++){//n-1 edge
        int x,y;
        cin>>x>>y;
        //connecting edge
        g[x].push_back(y);
        g[y].push_back(x);

    }
    bfs(1);//source
}
/*
g[x].push_back(y);
g[y].push_back(x);

n = 4
Edges: 1-2, 1-3, 2-4

g[x].push_back(y);
g[y].push_back(x);

represents adding an undirected edge between two nodes x and y in the adjacency list representation of a graph. Here�s how it works:

Explanation:
g[x] is the list of neighbors for node x.
g[y] is the list of neighbors for node y.
The call g[x].push_back(y) adds y to x's adjacency list, meaning there is an edge from x to y.
Similarly, g[y].push_back(x) adds x to y's adjacency list, indicating an edge from y to x.
Since the graph is undirected, we must add the connection in both directions.

Example:
Input:

makefile
Copy
Edit
n = 4
Edges: 1-2, 1-3, 2-4
Adjacency list construction:

For edge 1-2:
g[1].push_back(2) adds 2 to g[1].
g[2].push_back(1) adds 1 to g[2].

For edge 1-3:
g[1].push_back(3) adds 3 to g[1].
g[3].push_back(1) adds 1 to g[3].

For edge 2-4:
g[2].push_back(4) adds 4 to g[2].
g[4].push_back(2) adds 2 to g[4].

g[1] = {2, 3}
g[2] = {1, 4}
g[3] = {1}
g[4] = {2}

*/
