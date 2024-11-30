#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;


    int arr[n];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m;
    cout << "Enter the element to search: ";
    cin >> m;


    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == m) {
            result = mid;
            break;
        }
        if (arr[mid] < m) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }


    if (result == -1) {
        cout << "Element not found in the array." << endl;
    } else {
        cout << "Element found at index " << result << endl;
    }

    return 0;
}

