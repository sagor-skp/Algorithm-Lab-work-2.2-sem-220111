/*
//Kruskal
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int size[N];
void make(int v){
    parent[v]=v;
    size[v]=1;
}
int find(int v){
    if(v=parent[v]) return v;
    return parent[v]=find(parent[v]);
}

int Union(int a,int b){
    int aa=find(a);
    int bb=find(b);
    if(aa!=bb){
        if(size[aa]<size[bb]){
            swap(aa,bb);
        }
        parent[bb]=aa;
        size[aa]+=size[bb];
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>edge;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edge.push_back({wt,{u,v}});
    }
    sort(edge.begin(),edge.end());
    for(int i=1;i<=n;i++){
        make(i);
    }
    int totalcost=0;
    for(auto &it:edge){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        totalcost+=wt;
        cout<<u<<" "<<v<<endl;

    }
    cout<< totalcost<<endl;
}
*/

/*
//travelling tsp
#include<bits/stdc++.h>
using namespace std;
int totalcost(int mask,int pos,int n,vector<vector<int>>&cost){
    //base case
    if(mask==(1<<n)-1){
        return cost[pos][0];
    }
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if((mask & (1<<i))==0){
            ans=min(ans,cost[pos][i]+
            totalcost((mask | (1<<i)),i,n,cost));
        }
    }
    return ans;
}
int tsp(vector<vector<int>>&cost){
    int n=cost.size();
    return totalcost(1,0,n,cost);
}
int main(){
    vector<vector<int>>cost={{0,10,15,20},
    {10,0,35,25},
    {15,35,0,30},
    {20,25,30,0}};
    int ans=tsp(cost);
    cout<<ans;
}*/

/*//heapsort
#include<bits/stdc++.h>
using namespace std;
void heapyfi(vector<int>&arr,int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[largest]<arr[l]){
        largest=l;
    }
    if(r<n && arr[largest]<arr[r]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapyfi(arr,n,largest);
    }
}
void heapsort(vector<int>&arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapyfi(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapyfi(arr,i,0);//vv not use n use i because heap size reduce
    }
}
void print(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heapsort(arr);
    cout<<"sorted array is \n";
    print(arr);
}*/

/*//dfs
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
bool vis[N];
void dfs(int vertex){
    cout<<vertex<<" ";
    vis[vertex]=true;
    for(auto child:g[vertex]){
        if(vis[child]) continue;
        dfs(child);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int v1,v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(1);
}*/
//bfs
/*#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>g[N];
bool vis[N];
void bfs(int vertex){
    queue<int>q;
    q.push(vertex);
    vis[vertex]=true;
    while(!q.empty()){
        int cur_v=q.front();
        q.pop();
        cout<<cur_v<<" ";
        for(auto child:g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child]=true;
            }
        }
    }
 }
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
}*/
/*//primsalgo

#include<bits/stdc++.h>
using namespace std;
#define v 6
int findmin_vertex(vector<int>&value,vector<bool>&setmst){
    int min=INT_MAX;
    int vertex;
    for(int i=0;i<v;i++){
        if(setmst[i]==false && value[i]<min){
            min=value[i];
            vertex=i;
        }
    }
    return vertex;
}
void findmst(int graph[v][v]){
    int parent[v];
    vector<int>value(v,INT_MAX);
    vector<bool>setmst(v,false);
    parent[0]=-1;
    value[0]=0;
    for(int i=0;i<v-1;i++){
        int u=findmin_vertex(value,setmst);
        setmst[u]=true;
        for(int j=0;j<v;j++){
            if(graph[u][j]!=0 && setmst[j]==false && graph[u][j]<value[j]){
                value[j]=graph[u][j];
                parent[j]=u;
            }
        }
    }
    //print
    int totalweight=0;
    for(int i=1;i<v;i++){
        
        cout<<"U->V: "<<parent[i]<<"->"<<i<<" WT = "<<graph[parent[i]][i]<<endl;
        totalweight+=graph[parent[i]][i];
    }
    cout<<"Total weight ="<<totalweight;
}
int main(){
    int graph[v][v]={{0,4,6,0,0,0},
    {4,0,6,3,4,0},
    {6,6,0,1,8,0},
    {0,3,1,0,2,3},
    {0,4,8,2,0,7},
    {0,0,0,3,7,0}};
    findmst(graph);
    return 0;
}*/

/*//prims
#include<bits/stdc++.h>
using namespace std;
#define v 6
int selectminvertex(vector<int>&value,vector<bool>&setmst){
    int min=INT_MAX;
    int vertex;
    for(int i=0;i<v;i++){
        if(setmst[i]==false && value[i]<min){
            min=value[i];
            vertex=i;
        }
    }
    return vertex;
}
void primsalgo(int graph[v][v]){
    vector<int>value(v,INT_MAX);
    vector<bool>setmst(v,false);
    int parent[v];
    parent[0]=-1;
    value[0]=0;
    
    for(int i=0;i<v-1;i++){
        int u=selectminvertex(value,setmst);
        setmst[u]=true;
        for(int j=0;j<v;j++){
            if(graph[u][j]!=0 && setmst[j]==false && graph[u][j]<value[j]){
                value[j]=graph[u][j];
                parent[j]=u;
            }
        }
       
    }
    int totalw=0;
    for(int i=1;i<v;i++){
        cout<<"U->V : "<<parent[i]<<"->"<<i<<" wt :"<<graph[parent[i]][i]<<endl;
        totalw+=graph[parent[i]][i];
    }
    cout<<"total weight="<<totalw;
}
int main(){
    int graph[v][v]={{0,4,6,0,0,0},
    {4,0,6,3,4,0},
    {6,6,0,1,0,0},
    {0,3,1,0,2,3},
    {0,4,0,2,0,7},
    {0,0,0,3,7,0}};
    primsalgo(graph);
    return 0;
}*/

//kruskal
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int size[N];
void make(int m){
    parent[m]=m;
    size[m]=1;
}
int find(int c){
    if(parent[c]==c) return c;
    return parent[c]=find(parent[c]);
}
int Union(int a,int b){
    int aa=find(a);
    int bb=find(b);
    if(aa!=bb){
        if(size[aa]<size[bb]){
            swap(aa,bb);
        }
        parent[bb]=aa;//aa big
        size[aa]+=size[bb];
    }

}
int main(){
    int n,e;
    cin>>n>>e;
    vector<pair<int,pair<int,int>>>edge;
    for(int i=0;i<e;i++){
        int wt,u,v;
        cin>>u>>v>>wt;
        edge.push_back({wt,{u,v}});
    }
    sort(edge.begin(),edge.end());
    for(int i=1;i<=n;i++){
        make(i);
    }
    int totalweight=0;
    for(auto &it:edge){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(find(u)==find(v))continue;
        Union(u,v);
        totalweight+=wt;
        cout<<u<<"   "<<v<<endl;
    }
    cout<<totalweight;
    return 0;
}