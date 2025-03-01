/*
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];

    int i = low + 1;
    int j = high;

    while (true)
    {
        while (i <= j && arr[i] <= pivot)
        {
            i++;
        }
        while (i <= j && arr[j] > pivot)
        {
            j--;
        }
        if (i >= j) break;

        swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int partitaion(vector<int>&arr,int low,int high){
    int i=low+1;
    int j=high;
    int pivot=arr[low];
    while(true){
        while(i<=high && arr[i]<=pivot){
            i++;
        }
        while(j>=low && arr[j]>pivot){
            j--;
        }
        if(i>j)break;//i>=j
        swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;
}
void quicksort(vector<int>&arr,int low,int high){
   if(low<high){
    int pi=partitaion(arr,low,high);
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
}

/*
if(low<high){
    int pi=partitaion(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
   }
    
arr = [8, 4, 7, 3, 6, 2, 5]
low = 0, high = 6
Step-by-Step Execution with Diagram

Initial Call: quicksort(arr, 0, 6)

Partition happens, choosing 8 (arr[0]) as the pivot.
Rearrange elements: [5, 4, 7, 3, 6, 2, 8]
Pivot index returned: pi = 6
Recur on two parts:
quicksort(arr, 0, 5)
quicksort(arr, 7, 6) → (base case triggered)
yaml
Copy
Edit
Initial: [8, 4, 7, 3, 6, 2, 5]
Pivot: 8
After partition: [5, 4, 7, 3, 6, 2, 8]
Left Part: [5, 4, 7, 3, 6, 2]   |   Right Part: []
Recursive Calls: quicksort(0,5) and quicksort(7,6)->not occur

*/