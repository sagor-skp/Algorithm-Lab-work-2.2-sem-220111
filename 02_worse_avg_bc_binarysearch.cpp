
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int choice, target, count = 0;
    vector<int> arr;

    cout << "Choose a case to simulate:\n";
    cout << "1. Average case (target is in the array)\n";
    cout << "2. Worst case (target is not in the array)\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    cout << "Enter the size of the array: ";
    int n;
    cin >> n;

    cout << "Enter a sorted array : ";
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    cout << "Enter the target element: ";
    cin >> target;

    if (choice == 1 && find(arr.begin(), arr.end(), target) == arr.end())
    {
        cout << "Error: Target must exist in the array for the average case.\n";
        return 0;
    }

    int low = 0, high = arr.size() - 1;
    int mid;
    bool found = false;

    while (low <= high)
    {
        count++;
        mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            found = true;
            break;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found)
    {
        cout << "Target found at index " << mid << ".\n";
    }
    else
    {
        cout << "Target not found in the array.\n";
    }
    cout << "Total loop iterations: " << count << "\n";

    return 0;
}
