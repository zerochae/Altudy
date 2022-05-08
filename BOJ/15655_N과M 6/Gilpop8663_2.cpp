#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> a;
int num[8];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    // M의 개수만큼 0을 넣어줌
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }
    sort(num, num + N);

    for (int i = 0; i < N; ++i)
        a.push_back(i < M ? 0 : 1);
    do
    {
        for (int i = 0; i < N; ++i)
            if (a[i] == 0)
                cout << num[i] << ' ';
        cout << '\n';
    } while (next_permutation(a.begin(), a.end()));
}