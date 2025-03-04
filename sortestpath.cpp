#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int>dijkstra(vector<vector<pair<int,int>>>&adj,int n,int src){
    vector<int>distarr(n,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    distarr[src]=0;
    pq.push({0,src});
    while(!pq.empty()){
        int dis=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for(auto it:adj[node]){
            int adgenode=it.first;
            int edgeweight=it.second;
            if(dis+edgeweight<distarr[adgenode]){
                distarr[adgenode]=dis+edgeweight;
                pq.push({distarr[adgenode],adgenode});
            }
        }
    }
    return distarr;
}
int main()
{
    int n,e;
    cout<<"Enter node edge:"<<endl;
    cin>>n>>e;
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int src;
    cout<<"Enter source:"<<endl;
    cin>>src;
    vector<int>res=dijkstra(adj,n,src);
    for(int i=0;i<n;i++){
        cout<<0<<"->"<<i<<"->"<<res[i]<<endl;
    }
    return 0;
}