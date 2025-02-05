#include<bits/stdc++.h>
using namespace std;
struct item{
    int profit,weight;
    //constructor
    item(int profit,int weight){
        this->profit=profit;
        this->weight=weight;
    }
};
static bool cmp(struct item a,struct item b){
    double r1=(double)a.profit/(double)a.weight;
    double r2=(double)b.profit/(double)b.weight;
    return r1>r2;
}
double fractionalnapsac(int w,struct item arr[],int n){
    sort(arr,arr+n,cmp);//decreasing order profit/weight
    double finalvalue=0;
    for(int i=0;i<n;i++){
        if(arr[i].weight<w){
            w-=arr[i].weight;
            finalvalue+=arr[i].profit;
        }
        else{
            finalvalue+=((double)w/(double)arr[i].weight)*arr[i].profit;
            break;
        }
    }
    return finalvalue;
}
int main()
{
    int w=50;
    item arr[]={{60,10},{100,20},{120,30}};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<fractionalnapsac(w,arr,n);
    return 0;
}
/*
The cmp function is a comparison function used in the sort 
function to sort items based on their profit-to-weight ratio in descending order
static bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;
    return r1 > r2;
}
It calculates the profit-to-weight ratio (profit/weight) for two items, a and b.
If the ratio of a is greater than that of b, it returns true, meaning a should come before b in sorted order.
Otherwise, b comes first.

60/10 = 6.0  →  100/20 = 5.0  →  120/30 = 4.0
(Item 1)      (Item 2)         (Item 3)

*/