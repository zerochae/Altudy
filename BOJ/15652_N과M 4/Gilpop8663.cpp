#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[10];

void func(int k) // 현재까지 k개를 선택했음
{
    if (k == m) // m개를 모두 택했으면
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " "; // arr에 기록해둔 수를 모두 출력
        }
        cout << "\n";
        return;
    }
    // 또 다른 방법
    // int st=1;
    // if(k!=0) st=arr[k-1];
    // for (int i = st; i <= n; i++)
    for (int i = 1; i <= n; i++)
    {
        if (arr[k - 1] <= i)
        {
            arr[k] = i;  // k번째를 i로 지정
            func(k + 1); // 다음 수를 정하러 한 단계 더 들어감
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);
}
