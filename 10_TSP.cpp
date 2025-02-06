#include<bits/stdc++.h>
using namespace std;

int totalcost(int m,int pos,int n,vector<vector<int>> &cost){
    // Base case: if all cities are visited, return the 
   // cost to return to the starting city (0)
    if(m==(1<<n)-1){
        return cost[pos][0];
    }

    int ans=INT_MAX;
    // Try visiting every city that has not been visited yet
    for(int i=0;i<n;i++){
        //check visited or not
        if((m & (1<<i))==0){
            ans=min(ans,cost[pos][i]+ 
            totalcost((m | (1<<i)),i,n,cost));
        }
    }
    return ans;
}
int tsp(vector<vector<int>> &cost){
    int n=cost.size();
    // Start from city 0, and only city 0 is visited initially (mask = 0001)

    return totalcost(1,0,n,cost);
}
int main(){
    vector<vector<int>> cost={{0,10,15,20},
    {10,0,35,25},
    {15,35,0,30},
    {20,25,30,0}};
    int res= tsp(cost);
    cout<<res<<" ";
    return 0;
}
/*
if(mask==(1<<n)-1){
        return cost[pos][0];
    }
    1 << n shifts 1 left by n bits, giving 2^n.
Subtracting 1 gives a binary number with n ones, meaning all n cities have been visited.
For example, if n = 4, then:
1 << 4  =  10000 (16 in decimal)
(1 << 4) - 1 =  01111 (15 in decimal)
So, mask == 15 (01111 in binary) means all 4 cities (0, 1, 2, and 3) have been visited.


if((mask & (1<<i))==0){
            ans=min(ans,cost[pos][i]+ 
            totalcost((mask | (1<<i)),i,n,cost));
        }

   if ((mask & (1 << i)) == 0)
   checks if city i has been visited using bitwise AND.

mask keeps track of visited cities using bits.
1 << i shifts 1 left by i positions, creating a bitmask where only the i-th bit is set.
(mask & (1 << i)) == 0 checks if the i-th bit is unset (i.e., city i is not yet visited).

 mask       = 0011  (Cities 0 and 1 visited)
1 << 2     = 0100  (Checking City 2)
--------------------
mask & (1 << 2) = 0011 & 0100 = 0000  →  0  (City 2 is NOT visited)
 

 totalcost((mask | (1<<i))
is used to mark city i as visited by setting the i-th bit to 1 in mask.

mask keeps track of visited cities using bits.
1 << i creates a binary number with only the i-th bit set.
mask | (1 << i) performs a bitwise OR, ensuring the i-th bit is set to 1.

mask       = 0011  (Cities 0 and 1 visited)
1 << 2     = 0100  (Marking City 2)
--------------------
mask | (1 << 2) = 0011 | 0100 = 0111  (Cities 0, 1, and 2 visited)


*/