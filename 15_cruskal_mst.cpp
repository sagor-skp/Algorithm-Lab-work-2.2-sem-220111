//Kruskal Algorithm
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int size[N];
void make(int v){
    parent[v]=v;
    //single node itself parent
    size[v]=1;
}
int find(int v){
    if(v==parent[v]) return v;
    //1
    return parent[v]=find(parent[v]);
    //1->2->3->4
}
int Union(int a,int b){
    a=find(a);
    b=find(b);

    if(a!=b){
        //union by size
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;//a big
        size[a]+=size[b];
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int, pair<int,int>>> edge;
    for(int i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edge.push_back({wt,{u,v}});
    }
    sort(edge.begin(),edge.end());

    for(int i=1;i<=n;i++) make(i);

    int total_cost=0;
    
    for(auto &it:edge){
        int wt=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(find(u)==find(v)) continue;
        Union(u,v);
        total_cost+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<total_cost<<endl;
}
