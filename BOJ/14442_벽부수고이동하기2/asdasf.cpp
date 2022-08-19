#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr1[5] = {-9, 1, 6, 8, 12};
    int arr2[4] = {-7, 7, 13, 15};

    int arr3[10];
    int idx1 = 0;
    int idx2 = 0;
    for (int i = 0; i < 9; i++)
    {
        if (arr1[idx1] < arr2[idx2])
        {
            arr3[i] = arr1[idx1++];
        }
        else
        {
            arr3[i] = arr2[idx2++];
        }
        cout << idx1 << " " << idx2 << "\n";
    }
    for (int i = 0; i < 9; i++)
        cout << arr3[i] << " ";
}