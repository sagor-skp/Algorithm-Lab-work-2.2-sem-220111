#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int selectminv(vector<int>&value,vector<bool>&proshed,int v){
    int min=INT_MAX;
    int vertex;
    for(int i=0;i<v;i++){
        if(proshed[i]==false && value[i]<min){
            min=value[i];
            vertex=i;
        }
    }
    return vertex;
}
void digestra(vector<vector<int>>&graph,int v){
    int parent[v];
    vector<int>value(v,INT_MAX);
    vector<bool>proshed(v,false);
    value[0]=0;
    parent[0]=-1;

    for(int i=0;i<v-1;i++){
        int u=selectminv(value,proshed,v);
        proshed[u]=true;
        for(int j=0;j<v;j++){
            if(graph[u][j]!=0 && proshed[j]==false&&
            value[u]!=INT_MAX && value[u]+graph[u][j]<value[j]){
                value[j]=value[u]+graph[u][j];
                parent[j]=u;
            }
        }
    }
    int maxw=0;
    for(int i=1;i<v;i++){
        cout<<"u->v"<<parent[i]<<"-> "<<i<<"wt= "<<graph[parent[i]][i]<<endl;
        maxw+=graph[parent[i]][i];
    }
    cout<<"MAXIMUM WEIght="<<maxw;
}
int main()
{
    int v;
    cout<<"Enter number of vertex:"<<endl;
    cin>>v;
    vector<vector<int>>graph(v,vector<int>(v));
    cout<<"Enter adjancy matrix:"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>graph[i][j];
        }
    }
    digestra(graph,v);
    return 0;
}