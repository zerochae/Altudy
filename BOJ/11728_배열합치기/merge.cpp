#include <bits/stdc++.h>

using namespace std;

int n = 9;

int arr[1000000] = {-1, 85, 8, -4, -8, 9, 6, 5, 2};
int tmp[1000000];

void merge(int st, int en)
{
    int mid = (st + en) / 2;
    int lidx = st;
    int ridx = mid;
    for (int i = st; i < en; i++)
    {
        if (ridx == en)
            tmp[i] = arr[lidx++];
        else if (lidx == mid)
            tmp[i] = arr[ridx++];
        else if (arr[lidx] <= arr[ridx])
            tmp[i] = arr[lidx++];
        else
            tmp[i] = arr[ridx++];
    }
    for (int i = st; i < en; i++)
        arr[i] = tmp[i];
}

void merge_sort(int st, int en)
{
    if (en == st + 1)
        return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main(void)
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    merge_sort(0, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}