#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[10];
bool isused[10];

void func(int k) // 현재까지 k개를 선택했음
{
    if (k == m) // m개를 모두 선택했으면
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " "; // arr[i] 에 기록해둔 수를 출력
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= n; i++) // 1부터 n까지의 수에 대해
    {
        if (!isused[i])
        {                      //아직 i가 사용되지 않았다면
            arr[k] = i;        // k번째를 i로 정함
            isused[i] = true;  // i를 사용했다고 표시
            func(k + 1);       // 다음 수를 정하러 한 단계 더 들어감
            isused[i] = false; // k번째에 i를 지정한 모든 경우의 수를 확인했으니 i를 이제 사용하지 않았다고 명시함
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
