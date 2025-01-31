/*#include <bits/stdc++.h>

using namespace std;
class Solution {
  public:
    void solve(int col, vector < string > & board, vector < vector < string >> & ans, vector < int > & leftrow, vector < int > & upperDiagonal, vector < int > & lowerDiagonal, int n) {
      if (col == n) {
        ans.push_back(board);
        return;
      }
      for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
          board[row][col] = 'Q';
          leftrow[row] = 1;
          lowerDiagonal[row + col] = 1;
          upperDiagonal[n - 1 + col - row] = 1;
          solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
          board[row][col] = '.';
          leftrow[row] = 0;
          lowerDiagonal[row + col] = 0;
          upperDiagonal[n - 1 + col - row] = 0;
        }
      }
    }

  public:
    vector < vector < string >> solveNQueens(int n) {
      vector < vector < string >> ans;
      vector < string > board(n);
      string s(n, '.');
      for (int i = 0; i < n; i++) {
        board[i] = s;
      }
      vector < int > leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
      solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
      return ans;
    }
};
int main() {
  int n = 4; // we are taking 4*4 grid and 4 queens
  Solution obj;
  vector < vector < string >> ans = obj.solveNQueens(n);
  for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{

    void solve(int col,vector<string>&board,vector<vector<string>>&ans,
               vector<int>&leftrow,vector<int>&upperdiagonal,
               vector<int>&lowerdiagonal,int n){
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
                        solve(col+1,board,ans,leftrow,upperdiagonal,lowerdiagonal,n);
                        board[row][col]='.';
                        leftrow[row]=0;
                        upperdiagonal[n-1+col-row]=0;
                        lowerdiagonal[row+col]=0;

                    }
                   }

    }
public:
    vector<vector<string>>solveNQueens(int n){
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>leftrow(n,0),upperdiagonal(2*n-1,0),lowerdiagonal(2*n-1,0);
        solve(0,board,ans,leftrow,upperdiagonal,lowerdiagonal,n);
        return ans;
    }
};
int main()
{
    int n=4;
    Solution obj;
    vector<vector<string>>ans=obj.solveNQueens(n);
    for(int i=0;i<ans.size();i++){
        cout<<"arrangement "<<i+1<<endl;
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j];
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
