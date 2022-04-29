#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) // 카운팅 정렬로 O(n) 을  충족함 카운팅 정렬은 주로 범위가 알파벳정도일때 자주 사용되며 1000000000처럼 큰 수는 오히려 메모리를 최대로 사용해서 효율이 안좋다고 함
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int arr[10001] = {0};

    // cout << arr[0] << arr[1];
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[num]++;
    }

    for (int i = 1; i < 10001; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cout << i << "\n";
        }
    }
}
