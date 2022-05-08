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
            cout << num[arr[i]] << " "; // arr에 기록해둔 수를 모두 출력
        }
        cout << "\n";
        return;
    }

    int tmp = 0; // 중복 수열인지 확인 하기 위한 임시 변수

    int st = 0;
    if (k != 0)
        st = arr[k - 1];

    for (int i = st; i < n; ++i)
    {
        // cout << isused[i] << tmp << num[i] << "\n";
        if (!isused[i] && tmp != num[i]) // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
        {
            isused[i] = 1;
            arr[k] = i; // k번째를 num[i]로 지정
            tmp = num[arr[k]];
            func(k + 1); // 다음 수를 정하러 한 단계 더 들어감
            isused[i] = 0;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
    }

    sort(num, num + n);

    func(0);
}
