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

/*//kruskal
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
}*/

/*//nqueen
#include<bits/stdc++.h>
using namespace std;
void solve(int col,int n,vector<int>&leftrow,vector<int>&upperdiagonal,
    vector<int>&lowerdiagonal,vector<string>&board,vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(board);
            return; 
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && upperdiagonal[n-1+col-row]==0 && lowerdiagonal[row+col]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                upperdiagonal[n-1+col-row]=1;
                lowerdiagonal[row+col]=1;
                solve(col+1,n,leftrow,upperdiagonal,lowerdiagonal,board,ans);
                board[row][col]='.';
                leftrow[row]=0;
                upperdiagonal[n-1+col-row]=0;
                lowerdiagonal[row+col]=0;
            }
        }
    }
vector<vector<string>> sloution(int n){
    vector<vector<string>> ans;
    vector<string>board(n,string(n,'.'));
    vector<int>leftrow(n,0),upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
    solve(0,n,leftrow,upperdiagonal,lowerdiagonal,board,ans);
    return ans;
}
int main(){
    int n;
    cout << "Enter the value of N: ";
    cin>>n;
    vector<vector<string>>ans=sloution(n);
    for(int i=0;i<ans.size();i++){
        cout << "Arrangement " << i + 1 << ":\n";
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
}*/
/*//01 napsac
#include<bits/stdc++.h>
using namespace std;
int solve(vector<pair<int,int>>&item,int n,int w){
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++){
        int weight=item[i-1].first;
        int profit=item[i-1].second;
        for(int j=0;j<=w;j++){
            if(j<weight){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],profit+dp[i-1][j-weight]);
            }
        }
    }
    return dp[n][w];
}
int main(){
    int n;
    cout<<"Enter number of item :"<<endl;
    cin>>n;
    vector<pair<int,int>>item(n);
    cout<<"Enter weight and profit"<<endl;
    for(int i=0;i<n;i++){
        cin>>item[i].first>>item[i].second;
    }
    int w;
    cout<<"Enter maximum weight :"<<endl;
    cin>>w;
    cout<<"maximum profit : "<<solve(item,n,w)<<endl;
}
*/

/*//01_napsac
#include<bits/stdc++.h>
using namespace std;
int sovle(vector<pair<int,int>>&item,int w,int n){
    vector<vector<int>>dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++){
        int weight=item[i].first;
        int profit=item[i].second;
        for(int j=0;j<=w;j++){
            if(j<weight){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],profit+dp[i-1][j-weight]);
            }
        }
    }
    return dp[n][w];
}
int main(){
    int n;
    cout<<"Enter number of item:"<<endl;
    cin>>n;
    cout<<"Enter item weight and profit:"<<endl;
    vector<pair<int,int>>item(n);
    for(int i=1;i<=n;i++){
        cin>>item[i].first>>item[i].second;
    }
    int w;
    cout<<"Enter total maximum weight :"<<endl;
    cin>>w;
    cout<<"MAximum profit ="<<sovle(item,w,n);
    return 0;
}
*/
/*//lcs
#include<bits/stdc++.h>
using namespace std;
int solve(string s1,string s2){
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
int main(){
    string s1;
    string s2;
    cout<<"Enter two string :"<<endl;
    cin>>s1>>s2;
    cout<<"Longest common subsequence is : "<<solve(s1,s2)<<endl;
    return 0;
}
*/

/*//bfs
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
//vector<int>g[N];//vector<vector<int>g(n);
vector<vector<int>>g(N);
int vis[N]={0};
void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source]=1;
    while(!q.empty()){
        int cur_v=q.front();
        q.pop();
        cout<<cur_v<<" ";
        for(int child:g[cur_v]){
            if(!vis[child]){
                q.push(child);
                vis[child]=1;
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter number of node :"<<endl;
    cin>>n;
    for(int i=0;i<n-1;i++){//edge n-1 ta
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    bfs(1);
}
*/

/*//dfs
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<vector<int>>g(N);//vector<int>g[N]
int vis[N]={0};

void dfs(int source){
    cout<<source<<" ";
    vis[source]=1;
    for(int child:g[source]){
        if(vis[child]==1) continue;
        dfs(child);
    }
}
int main(){
    int n,m;
    cout<<"Enter node and edge :"<<endl;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
}*/

/*//fractional napsac
#include<bits/stdc++.h>
using namespace std;
double sovle(vector<pair<int,int>>&item,int w,int n){
    sort(item.begin(),item.end(),[](pair<int,int>a,pair<int,int>b){
        return (double)a.second/a.first>(double)b.second/b.first;
    });
    double totalprofit=0.0;
    for(int i=0;i<n;i++){
        int weight=item[i].first;
        int profit=item[i].second;
        if(w>weight){
            totalprofit+=profit;
            w-=weight;
        }
        else{
            totalprofit+=(double)w/weight*profit;
            break;
        }
    }
    return  totalprofit;  
}
int main(){
    int n;
    cout<<"Enter number of item:"<<endl;
    cin>>n;
    cout<<"Enter item weight and profit:"<<endl;
    vector<pair<int,int>>item(n);
    for(int i=0;i<n;i++){
        cin>>item[i].first>>item[i].second;
    }
    int w;
    cout<<"Enter total maximum weight :"<<endl;
    cin>>w;
    cout<<"MAximum profit ="<<sovle(item,w,n);
    return 0;
}*/

/*//heap sort
#include<bits/stdc++.h>
using namespace std;
void heapyfy(vector<int>&arr,int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(i!=largest){
        swap(arr[i],arr[largest]);
        heapyfy(arr,n,largest);
    }
}
void heap(vector<int>&arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapyfy(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[0]);
        heapyfy(arr,i,0);
    }
}
int main(){
    int n;
    cout<<"Enter array size :"<<endl;
    cin>>n;
    cout<<"Enter element :"<<endl;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    heap(arr,n);
    cout<<"Sorting element :"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}*/

/*//mergesort
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void merge(vector<int>&arr,int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector<int>temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    //transfer all element from temp to arr
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergesort(vector<int>&arr,int low,int high){
    int mid=(low+high)/2;
    if(low>=high)return;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main()
{
    int n;
    cout<<"Enter number of element:"<<endl;
    cin>>n;
    cout<<"Enter  element:"<<endl;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    cout<<"sorted  element:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}*/

/*/quick sort
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int partition(vector<int>&arr,int low,int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    while(true){
        while(i<=high && arr[i]<=pivot){
            i++;
        }
        while(j>=low && arr[j]>pivot){
            j--;
        }
        if(i>j)break;
        swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;
}
void quicksort(vector<int>&arr,int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main(){
    int n;
    cout<<"Enter array size :"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter array element :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    cout<<"Sorted array element :"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}*/
/*//kruskal
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int parent[N];
int size[N];
void make(int v){
    parent[v]=v;
    size[v]=1;
}
int find(int v){
    if(v==parent[v]) return v;//root
    return parent[v]=find(parent[v]);
}
void Union(int a,int b){
    int n=find(a);
    int m=find(b);
    if(n!=m){
        if(size[n]<size[m]){
            swap(n,m);
        }
        parent[m]=n;//n big
        size[n]+=size[m];
    }
    

}
int main()
{
    int n,e;
    cout<<"Enter number of node and edge :"<<endl;
    cin>>n>>e;
    vector<pair<int,pair<int,int>>>edge;
    for(int i=0;i<e;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edge.push_back({wt,{u,v}});//single element
    }
    sort(edge.begin(),edge.end());
    for(int i=0;i<n;i++){
        make(i);
    }
    int totalweight=0;
    for(auto &it:edge){
        int weight=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(find(u)==find(v))continue;
        Union(u,v);
        totalweight+=weight;
        cout<<u<<"   "<<v<<endl;
    }
    cout<< "totalweight"<<totalweight;
    return 0;
}*/
/*//tower of hanoi
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void tower(int n,char s,char h,char d){
    if(n==0)return;
    tower(n-1,s,d,h);
    cout<<"move "<<s<<" to "<<d<<endl;
    tower(n-1,h,s,d);

}
int main()
{
    int n;
    cout<<"Enter number of disk:"<<endl;
    cin>>n;
    tower(n,'A','B','C');
    return 0;
}*/
/*// tree traversal
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
node* createnode(int data){
    node* n=new node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void preorder(node* root){
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
void postorder(node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}
int main()
{
    node* p=createnode(1);
    node* p1=createnode(2);
    node* p2=createnode(3);
    node* p3=createnode(4);
    node* p4=createnode(5);
    p->left=p1;
    p->right=p2;
    p->left->left=p3;
    p->left->right=p4;
    preorder(p);
    cout<<endl;
    inorder(p);
    cout<<endl;
    postorder(p);
    cout<<endl;
    return 0;
}*/
/*//tsp
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int tsp(vector<vector<int>>&nodes){
    int n=nodes.size();
    vector<int>tnode;
    for(int i=1;i<n;i++){
        tnode.push_back(i);
    }
    int mincost=INT_MAX;
    do{
        int curentcost=0;
        int currentnode=0;
        for(int i=0;i<n;i++){
            curentcost+=nodes[currentnode][tnode[i]];
            currentnode=tnode[i];
        }
        curentcost+=nodes[currentnode][0];
        mincost=min(mincost,curentcost);
    }while(next_permutation(tnode.begin(),tnode.end()));
    return mincost;
}
int main()
{
    int n;
    cout<<"Enter number of cities:"<<endl;
    cin>>n;
    vector<vector<int>>nodes(n,vector<int>(n));
    cout<<"Enter cost of matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>nodes[i][j];
        }
    }
    cout<<"minimum cost of tsp = "<<tsp(nodes);
    return 0;
}*/
/*#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int findminvertex(vector<int>&value,vector<bool>setmst,int v){
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
void findmst(vector<vector<int>>&graph,int v){
    vector<int>value(v,INT_MAX);
    vector<int>parent(v);
    vector<bool>setmst(v,false);
    value[0]=0;
    parent[0]=-1;
    for(int i=0;i<v-1;i++){
        int u=findminvertex(value,setmst,v);
        setmst[u]=true;
        for(int j=0;j<v;j++){
            if(graph[u][j]!=0 && setmst[j]==false && graph[u][j]<value[j]){
                value[j]=graph[u][j];
                parent[j]=u;
            }
        }
    }
    //print
    cout<<"MINimun spaning tree :"<<endl;
    int mintweight=0;
    for(int i=1;i<v;i++){
        cout<<"U->V : "<<parent[i]<<" -> "<<i<<" Wt ="<<graph[parent[i]][i]<<endl;
        mintweight+=graph[parent[i]][i];
    }
    cout<<"minweight ="<<mintweight<<endl;
}
int main()
{
    int v;
    cout<<"Enter number of node:"<<endl;
    cin>>v;
    vector<vector<int>>graph(v,vector<int>(v));
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin>>graph[i][j];
        }
    }
    findmst(graph,v);
    return 0;
}*/
/*#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(int col,vector<string>&board,vector<vector<string>> &ans,vector<int>&leftrow,
    vector<int>&upperdiognal,vector<int>&lowerdiagonal,int n){
        //base
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && upperdiognal[n-1+col-row]==0 && lowerdiagonal[row+col]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                upperdiognal[n-1+col-row]=1;
                lowerdiagonal[row+col]=1;
                solve(col+1,board,ans,leftrow,upperdiognal,lowerdiagonal,n);
                board[row][col]='.';
                leftrow[row]=0;
                upperdiognal[n-1+col-row]=0;
                lowerdiagonal[row+col]=0;
            }
        }
    }
vector<vector<string>> solvenqueen(int n){
    vector<vector<string>> ans;
    vector<string>board(n,string(n,'.'));
    vector<int>leftrow(n,0),upperdiognal(2*n-1,0),lowerdiagonal(2*n-1,0);
    solve(0,board,ans,leftrow,upperdiognal,lowerdiagonal,n);
    return ans;
}
int main()
{
    int n;
    cout<<"Enter number of queen: "<<endl;
    cin>>n;
    vector<vector<string>>ans=solvenqueen(n);
    cout<<"Board are :"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<"Arrangement "<<i+1<<endl;
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<endl;
        }
    }
    return 0;
}*/
/*//binary search
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of element :"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter element :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int f;
    cout<<"Enter number you want :"<<endl;
    cin>>f;
    int temp=-1;
    int low=0,high=n-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(f==mid){
            temp=1;
            break;
        }
        if(arr[mid]<f){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(temp!=-1){
        cout<<"Element found "<<f<<endl;
    }
    else{
        cout<<"Element not found";
    }
    return 0;
}*/
/*//max min
#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of element :"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter element :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int max=arr[0];
    int min=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    cout<<"max "<<max<<" min "<<min;
    return 0;
}*/
/*#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int linearSearch(vector<int>& arr, int t) {
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == t) return i;
    return -1;
}

int binarySearch(vector<int>& arr, int t) {
    int l = 0, h = arr.size() - 1;
    while (l <= h) {
        int m = (l + h) / 2;
        if (arr[m] == t) return m;
        (arr[m] > t) ? h = m - 1 : l = m + 1;
    }
    return -1;
}

int main() {
    int n, t;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    cin >> t;

    auto s1 = high_resolution_clock::now();
    cout << "Linear: " << linearSearch(arr, t) << '\n';
    auto e1 = high_resolution_clock::now();
    
    sort(arr.begin(), arr.end());
    
    auto s2 = high_resolution_clock::now();
    cout << "Binary: " << binarySearch(arr, t) << '\n';
    auto e2 = high_resolution_clock::now();

    cout << "L Time: " << duration<double, micro>(e1 - s1).count() << " µs\n";
    cout << "B Time: " << duration<double, micro>(e2 - s2).count() << " µs\n";
}*/
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

int linearSearch(vector<int>& arr, int t) {
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] == t) return i;
    return -1;
}

int binarySearch(vector<int>& arr, int t) {
    int l = 0, h = arr.size() - 1;
    while (l <= h) {
        int m = (l + h) / 2;
        if (arr[m] == t) return m;
        (arr[m] > t) ? h = m - 1 : l = m + 1;
    }
    return -1;
}

int main() {
    int n, t;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    cin >> t;
    auto s1=high_resolution_clock::now();
    cout << "Linear: " << linearSearch(arr, t) << '\n';
    auto e1=high_resolution_clock::now();

    sort(arr.begin(),arr.end());
    auto s2=high_resolution_clock::now();
    cout << "Binary: " << binarySearch(arr, t) << '\n';
    auto e2=high_resolution_clock::now();
    cout<<"L time "<<duration<double,micro>(e1-s1).count()<<endl;
    cout<<"B time "<<duration<double,micro>(e2-s2).count()<<endl;
    
}