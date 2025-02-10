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

//heapsort
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
}