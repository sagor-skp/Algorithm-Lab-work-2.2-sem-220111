#include<bits/stdc++.h>
using namespace std;
int solve(vector<pair<int,int>>&item,int n,int w){
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
    for(int i=1;i<=n;i++){
        int weight=item[i-1].first;
        int profit=item[i-1].second;
        for(int j=0;j<=w;j++){
            if(j<weight){
                dp[i][j]=dp[i-1][j];//cannot take
            }
            else{
                dp[i][j]=max(dp[i-1][j],profit+dp[i-1][j-weight]);//take or not take
            }

        }
    }
    return dp[n][w];
}
int main(){
    int n;
    cout<<"Enter number of item: ";
    cin>>n;
    vector<pair<int,int>>item(n);
    cout<<"Enter item weight and value: "<<endl;
    for(int i=0;i<n;i++){
        cin>>item[i].first>>item[i].second;
    }

    int w;
    cout<<"Enter maximum weight ";
    cin>>w;
    cout<<"Profit ="<<solve(item,n,w);
}