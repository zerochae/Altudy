#include <bits/stdc++.h>
using namespace std;

int t, n;

int direc[14];
int arr[14];

vector<int> arr1;
vector<int> arr2;
vector<int> arr3;
vector<int> arr4;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int index = 0;
    for (int i = 0; i < 6; i++)
    {
        int dir, dim;

        cin >> dir >> dim;

        direc[i] = dir;
        arr[i] = dim;
        direc[6 + i] = dir;
        arr[6 + i] = dim;

        if (dir == 1)
        {
            arr1.push_back(dim);
        }
        else if (dir == 2)
        {
            arr2.push_back(dim);
        }
        else if (dir == 3)
        {
            arr3.push_back(dim);
        }
        else
        {
            arr4.push_back(dim);
        }
    }

    for (int i = 1; i < 12; i++)
    {

        // cout << i << " " << direc[i - 1] << " " << direc[i] << "\n";
        if (direc[i - 1] == 4 && direc[i] == 2)
            continue;
        if (direc[i - 1] == 2 && direc[i] == 3)
            continue;
        if (direc[i - 1] == 3 && direc[i] == 1)
            continue;
        if (direc[i - 1] == 1 && direc[i] == 4)
            continue;

        index = i;
    }

    // cout << index << " " << arr[index] << "\n";

    int x, y, sX, sY;
    if (arr1.size() == 1)
    {
        x = arr1[0];
    }
    else if (arr2.size() == 1)
    {
        x = arr2[0];
    }

    if (arr3.size() == 1)
    {
        y = arr3[0];
    }
    else if (arr4.size() == 1)
    {
        y = arr4[0];
    }

    sX = arr[index - 1];
    sY = arr[index];

    // cout << x << " " << y << " " << sX << " " << sY << "\n";
    int ans = (x * y - sX * sY) * n;

    cout << ans;
}

//  4 2 3 1 3 1

/*

1

3 60

1 20

4 160

2 50

3 100

1 30


1

3 60
1 20
4 160
2 50
3 100
1 30



*/
