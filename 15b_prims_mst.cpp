#include<bits/stdc++.h>
using namespace std;
#define v 6

int selectminvertex(vector<int>&value,vector<bool>&setmst){
    int min=INT_MAX;
    int vertex;
    for(int i=0;i<v;i++){
        if(setmst[i]==false && value[i]<min){
            vertex=i;
            min=value[i];
        }
    }
    return vertex;
}
void findmst(int graph[v][v]){
    int parent[v];
    vector<int>value(v,INT_MAX);
    vector<bool>setmst(v,false);
    parent[0]=-1;//starting node
    value[0]=0;

    for(int i=0;i<v-1;i++){
        int u=selectminvertex(value,setmst);
        setmst[u]=true;
        for(int j=0;j<v;j++){
            if(graph[u][j]!=0 && setmst[j]==false && graph[u][j]<value[j]){//techdose 28.24min explanation
                value[j]=graph[u][j];
                parent[j]=u;
            }
        }
    }
    //print
    int totalweight=0;
    for(int i=1;i<v;i++){
        cout<<"u->v: "<<parent[i]<<"->"<<i<<" wt = "<<graph[parent[i]][i]<<endl;
        totalweight+=graph[parent[i]][i];
    }
    cout<<"Totalweight= "<<totalweight;
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
}