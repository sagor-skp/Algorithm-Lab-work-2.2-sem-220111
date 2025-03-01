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
#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>& arr,int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);//after max heap porer portion see 131 to 144
    }
}
void heapsort(vector<int>& arr){
    int n=arr.size();
    //build max heap
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);//heapyfi reduce heap ***i not n
    }
}
void print(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main()
{
    vector<int>arr={9,4,3,8,10,2,5};
    heapsort(arr);
    cout<<"sorted array is \n";
    print(arr);
}
/*
Heap Sort is a comparison-based sorting technique based on the Binary Heap data structure. It works in two main phases:

Building a Max Heap: The input array is converted into a Max Heap (a complete binary tree where each parent node is greater than or equal to its children).
Sorting the Heap: The largest element (root) is swapped with the last element, and the heap size is reduced. The heap is then heapified again to maintain the heap property. This process is repeated until all elements are sorted.
Step-by-step Execution of Heap Sort
Given the input array:
arr = [9, 4, 3, 8, 10, 2, 5]

1. Build the Max Heap
We start heapifying from the last non-leaf node (index = n/2 - 1) and move up to the root.

Step 1: Heapify node at index 2 (value = 3)
markdown
Copy
Edit
        9
       /   \
      4     3
     / \   / \
    8  10 2   5
Left child = 2 × 2 + 1 = index 5 (value = 2)
Right child = 2 × 2 + 2 = index 6 (value = 5)
3 < 5, so swap 3 and 5.
markdown
Copy
Edit
        9
       /   \
      4     5
     / \   / \
    8  10 2   3
Step 2: Heapify node at index 1 (value = 4)
markdown
Copy
Edit
        9
       /   \
      4     5
     / \   / \
    8  10 2   3
Left child = index 3 (value = 8)
Right child = index 4 (value = 10)
10 > 4, swap 4 and 10.
markdown
Copy
Edit
        9
       /   \
     10     5
     / \   / \
    8   4 2   3
Step 3: Heapify root node (index 0, value = 9)
markdown
Copy
Edit
        9
       /   \
     10     5
     / \   / \
    8   4 2   3
Left child = index 1 (value = 10)
Right child = index 2 (value = 5)
10 > 9, swap 9 and 10.
markdown
Copy
Edit
       10
       /   \
      9     5
     / \   / \
    8   4 2   3
Now, the max heap is built.

2. Heap Sort Process
We now extract the largest element (root) and heapify the remaining part.

Step 1: Swap root (10) with last element (3), heapify
markdown
Copy
Edit
        3
       /   \
      9     5
     / \   /  
    8   4 2   
Heapify index 0 → Swap 3 and 9.
markdown
Copy
Edit
        9
       /   \
      3     5
     / \   /  
    8   4 2   
Heapify index 1 → Swap 3 and 8.
markdown
Copy
Edit
        9
       /   \
      8     5
     / \   /  
    3   4 2   
Step 2: Swap root (9) with last element (2), heapify
markdown
Copy
Edit
        2
       /   \
      8     5
     / \     
    3   4    
Heapify index 0 → Swap 2 and 8.
markdown
Copy
Edit
        8
       /   \
      2     5
     / \     
    3   4    
Heapify index 1 → Swap 2 and 4.
markdown
Copy
Edit
        8
       /   \
      4     5
     / \     
    3   2    
Step 3: Swap root (8) with last element (2), heapify
markdown
Copy
Edit
        2
       /   \
      4     5
     /      
    3       
Heapify index 0 → Swap 2 and 5.
markdown
Copy
Edit
        5
       /   \
      4     2
     /      
    3       
Step 4: Swap root (5) with last element (3), heapify
markdown
Copy
Edit
        3
       /   \
      4     2
Heapify index 0 → Swap 3 and 4.
markdown
Copy
Edit
        4
       /   \
      3     2
Step 5: Swap root (4) with last element (2), heapify
markdown
Copy
Edit
        2
       /   
      3    
Heapify index 0 → Swap 2 and 3.
markdown
Copy
Edit
 
*/