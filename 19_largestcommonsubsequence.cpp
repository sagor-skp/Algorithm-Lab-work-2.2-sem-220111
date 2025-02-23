#include<bits/stdc++.h>
using namespace std;
int lcs(string s1,string s2){
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
    cout<<"Enter two string:"<<endl;
    string s1;
    string s2;
    cin>>s1>>s2;
    
    cout<<"the length of lcs : "<<lcs(s1,s2)<<endl;
    return 0;
}
/*
dp table
i/j	0	C	E	D
0	0	0	0	0
A	0	0	0	0
C	0	1	1	1
D	0	1	1	2
*/
/*#include<bits/stdc++.h>
using namespace std;
int lcs(string& s1,string& s2,int ind1,int ind2,vector<vector<int>>&dp){
    if(ind1<0 || ind2<0){
        return 0;
    }
    //If the result for the subproblem is already
    // calculated and stored in dp[ind1][ind2],
    // return it directly to avoid redundant calculations.
    if(dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
    }
    if(s1[ind1]==s2[ind2]){
        return dp[ind1][ind2]=1+lcs(s1,s2,ind1-1,ind2-1,dp);
    }
    else{
        return dp[ind1][ind2]=max(lcs(s1,s2,ind1-1,ind2,dp),lcs(s1,s2,ind1,ind2-1,dp));
    }
}
int main(){
    cout<<"Enter two string:"<<endl;
    string s1;
    string s2;
    cin>>s1>>s2;
    int n=s1.size();
    int m=s2.size();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    cout<<"The length of lcs is "<<lcs(s1,s2,n-1,m-1,dp);
} */