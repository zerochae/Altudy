#include <bits/stdc++.h>
using namespace std;

int a, b;
// 2000000000
int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < 2 * n - 1; i++)
    {

        if (i == 0 || i == 2 * n - 2)
        {

            for (int j = 0; j < n; j++)
            {

                cout << '*';
            }
            for (int j = 0; j < 2 * n - 3; j++)
            {
                cout << ' ';
            }
            for (int j = 0; j < n; j++)
            {

                cout << '*';
            }
            cout << "\n";

            continue;
        }

        if (i == n - 1)
        {
            for (int j = 0; j < n - 1; j++)
            {
                cout << " ";
            }
            cout << "*";

            for (int j = 0; j < n - 2; j++)

            {

                cout << " ";
            }

            cout << "*";

            for (int j = 0; j < n - 2; j++)

            {

                cout << " ";
            }

            cout << "*\n";

            continue;
        }

        for (int j = 0; j < (n - 1) - abs(n - 1 - i); j++)
        {
            cout << " ";
        }

        cout << "*";

        for (int j = 0; j < n - 2; j++)
        {
            cout << " ";
        }
        cout << "*";

        for (int j = 0; j < 2 * abs((n - 1) - i) - 1; j++)
        {
            cout << " ";
        }
        cout << "*";

        for (int j = 0; j < n - 2; j++)
        {
            cout << " ";
        }
        cout << "*\n";
    }
}
