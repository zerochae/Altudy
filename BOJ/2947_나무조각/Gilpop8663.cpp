#include <bits/stdc++.h>
using namespace std;

int arr[6];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {

        cin >> arr[i];
    }

    while (true)
    {

        if (arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4 && arr[4] == 5)
        {
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;

                for (int k = 0; k < 5; k++)
                {
                    cout << arr[k] << " ";
                }
                cout << "\n";
            }
        }
    }
}
