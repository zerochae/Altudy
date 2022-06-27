#include <bits/stdc++.h>
using namespace std;

int n;

void hanoi(int n, int from, int by, int to)
{
    if (n == 1)
    {
        cout << from << " " << to << "\n";
    }
    else
    {
        hanoi(n - 1, from, to, by);
        cout << from << " " << to << "\n";
        hanoi(n - 1, by, from, to);
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    string k = to_string(pow(2, n));

    int x = k.find('.');
    k = k.substr(0, x);
    k[k.length() - 1] -= 1;

    cout << k << "\n";

    if (n < 21)
    {

        hanoi(n, 1, 2, 3);
    }
}

/*


*/