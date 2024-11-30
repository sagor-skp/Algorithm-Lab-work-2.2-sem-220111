
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int arr[] = {2, 4, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice, key;

    cout << "Menu:\n";
    cout << "1. Linear Search\n";
    cout << "2. Binary Search\n";
    cout << "3. Display Time Complexity\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        // Linear Search
        cout << "Enter the key to search: ";
        cin >> key;
        bool found = false;

        for (int i = 0; i < size; i++)
        {
            if (key == arr[i])
            {
                cout << "Element found at index: " << i << endl;
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Element not found" << endl;
    }
    break;

    case 2:
    {
        // Binary Search
        cout << "Enter the key to search: ";
        cin >> key;
        int l = 0, h = size - 1, mid;
        bool found = false;

        while (l <= h)
        {
            mid = (l + h) / 2;

            if (key == arr[mid])
            {
                cout << "Element found at index: " << mid << endl;
                found = true;
                break;
            }

            if (key > arr[mid])
                l = mid + 1; // Search in the right half
            else
                h = mid - 1; // Search in the left half
        }

        if (!found)
            cout << "Element not found" << endl;
    }
    break;

    case 3:
    {
        // Display Time Complexity
        cout << "Time Complexity Analysis:\n\n";

        // Linear Search
        cout << "1. Linear Search:\n";
        cout << "   Best Case: O(1)\n";
        cout << "   Worst Case: O(n) \n\n";

        // Binary Search
        cout << "2. Binary Search:\n";
        cout << "   Best Case: O(1) \n";
        cout << "   Worst Case: O(log n) \n";
        cout << "   For this array of size " << size << ", Worst Case = log2(" << size
             << ") = " << log2(size) << " iterations.\n";
    }
    break;

    default:
        cout << "Invalid choice! Please enter 1, 2, or 3." << endl;
    }

    return 0;
}

