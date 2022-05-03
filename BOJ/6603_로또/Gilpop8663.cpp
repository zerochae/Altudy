#include <bits/stdc++.h>
using namespace std;

int n;
int num[15];
int arr[15];
bool isused[15];

void func(int k) // 현재까지 k개를 선택했음
{
    if (k == 6) // m개를 모두 택했으면
    {
        bool flag = true;
        int tmp = -1;
        for (int i = 0; i < 6; i++)
        {
            if (tmp > num[arr[i]])
                flag = false;
            tmp = num[arr[i]];
        }

        if (flag)
        {
            for (int i = 0; i < 6; i++)
            {
                cout << num[arr[i]] << " ";
            }
            cout << "\n";
        }
        return;
    }

    for (int i = 0; i < n; ++i)
    {
        // cout << isused[i] << tmp << num[i] << "\n";
        if (!isused[i]) // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
        {
            arr[k] = i; // k번째를 num[i]로 지정
            isused[i] = 1;
            func(k + 1); // 다음 수를 정하러 한 단계 더 들어감
            isused[i] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> n;
        if (n == 0)
            break; // cout << n;
        for (int i = 0; i < n; ++i)
        {

            cin >> num[i];
            // cout << num[i];
        }
        sort(num, num + n);
        func(0);
        cout << "\n";
        fill(arr, arr + n, 0);
        fill(num, num + n, 0);
    }

    // func(0);
}
