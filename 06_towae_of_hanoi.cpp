#include<bits/stdc++.h>
using namespace std;
void tower(int n,char s,char h,char d){
    if(n==0) return;
    tower(n-1,s,d,h);// Move n-1 disks from source to helper pole
    cout<<"Move disk from "<<s<<" to "<<d<<endl;
    tower(n-1,h,s,d);// Move n-1 disks from helper to destination pole
    //return;
}
int main(){
    int n;
    cout<<"Enter number of disk:"<<endl;
    cin>>n;
    tower(n,'A','B','C');
    return 0;
}
/*
tower(n-1,s,d,h);// Move n-1 disks from source to helper pole
    cout<<"Move disk from "<<s<<" to "<<d<<endl;
    tower(n-1,h,s,d);// Move n-1 disks from helper to destination pole
*/