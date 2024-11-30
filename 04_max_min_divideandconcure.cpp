#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input size!" << endl;
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int choice;
    cout << "\nChoose an option:\n";
    cout << "1. Find Minimum and Maximum using Divide and Conquer\n";
    cout << "2. Find Minimum and Maximum using Normal (Iterative) method\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            // Divide and Conquer Method
            int low = 0, high = n - 1;
            int count = 0;
            int max_value, min_value;

            if (low == high) {
                max_value = arr[low];
                min_value = arr[low];
                count++;
            } else if (high == low + 1) {
                count += 2;
                if (arr[low] > arr[high]) {
                    max_value = arr[low];
                    min_value = arr[high];
                } else {
                    max_value = arr[high];
                    min_value = arr[low];
                }
            } else {
                int mid = (low + high) / 2;
                int left_max = arr[low], left_min = arr[low];
                int right_max = arr[mid + 1], right_min = arr[mid + 1];

                // Process left part
                for (int i = low; i <= mid; i++) {
                    count++;
                    if (arr[i] > left_max) left_max = arr[i];
                    if (arr[i] < left_min) left_min = arr[i];
                }

                // Process right part
                for (int i = mid + 1; i <= high; i++) {
                    count++;
                    if (arr[i] > right_max) right_max = arr[i];
                    if (arr[i] < right_min) right_min = arr[i];
                }

                // Combine results
                max_value = max(left_max, right_max);
                min_value = min(left_min, right_min);
                count += 2;
            }

            cout << "Max value: " << max_value << " and Min value: " << min_value
                 << " and Order of n (Steps): " << count << endl;
            break;
        }
        case 2: {
            // Normal (Iterative) Method
            int max_value = INT_MIN, min_value = INT_MAX;
            int count = 0;

            // Traverse the array to find max and min
            for (int i = 0; i < n; i++) {
                count++;
                if (arr[i] > max_value) max_value = arr[i];
                if (arr[i] < min_value) min_value = arr[i];
            }

            cout << "Max value: " << max_value << " and Min value: " << min_value
                 << " and Order of n (Steps): " << count << endl;
            break;
        }
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}
