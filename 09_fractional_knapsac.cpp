#include<bits/stdc++.h>
using namespace std;
double maxprofit(vector<pair<int,int>>&item,int n,int w){
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
    return totalprofit;
}
int main(){
    cout<<"Enter number of item :";
    int n;
    cin>>n;
    vector<pair<int,int>>item(n);
    cout<<"every item weight and profit : ";
    for(int i=0;i<n;i++){
        cin>>item[i].first>>item[i].second;
    }
    cout<<"Enter weifgt: ";
    int w;
    cin>>w;
    cout<<"MAXimum profit="<<maxprofit(item,n,w)<<endl;

}