#include <iostream>
using namespace std;


void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
    // Base case: If only one disk, move it directly from source to destination
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
    }
    // Move n-1 disks from source to auxiliary peg
    towerOfHanoi(n - 1, from, aux, to);

    // Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << from << " to " << to << endl;

    // Move the n-1 disks from auxiliary peg to destination
    towerOfHanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}

