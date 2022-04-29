#include <bits/stdc++.h>
using namespace std;

int n;

int main(void) // 카운팅 정렬로 O(n) 을  충족함 카운팅 정렬은 주로 범위가 알파벳정도일때 자주 사용되며 1000000000처럼 큰 수는 오히려 메모리를 최대로 사용해서 효율이 안좋다고 함
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<int> v;

    // cout << v.back();
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        // cout << v.back();
    }

    sort(v.begin(), v.end());

    int k;

    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        // cout << "여기임:" << num;
        if (binary_search(v.begin(), v.end(), num) == true)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}
