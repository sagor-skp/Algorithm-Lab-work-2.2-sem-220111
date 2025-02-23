#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&arr,int low,int mid,int high){
    vector<int>temp;
    int left=low;
    int right=mid+1;
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
    //[1,2,3] [1 2 3 4,5] for this condition handel
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    // transfering all elements from temporary to arr //
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}
void mergesort(vector<int>&arr,int low,int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);

    merge(arr,low,mid,high);
}
int main(){
    int n;
    cout<<"Enter number of element:"<<endl;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter element :"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    cout<<"Sorted array "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}