#include <bits/stdc++.h>
using namespace std;

int n, m;
int num[8];
int arr[10];
bool isused[10];

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

    for (int i = 0; i < n; i++)
    {
        if (!isused[i])
        {
            isused[i] = 1;
            arr[k] = num[i]; // k번째를 num[i]로 지정
            func(k + 1);     // 다음 수를 정하러 한 단계 더 들어감
            isused[i] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num, num + n);

    func(0);
}
