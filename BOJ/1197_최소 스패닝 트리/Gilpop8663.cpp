#include <bits/stdc++.h>
using namespace std;

int n, k;

vector<tuple<int, int, int>> arr;

int parent[10005];

int getParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = getParent(parent[x]);
}

// 각 부모의 노드를 합칩니다.
void unionParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a < b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
}

// 같은 부모 노드를 가졌는 지 확인합니다.
int findParent(int a, int b)
{
    a = getParent(a);
    b = getParent(b);
    if (a == b)
        return 1;
    return 0;
}

// // 크루스칼 알고리즘
// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n >> k;

//     for (int i = 0; i < k; i++)
//     {
//         int A, B, C;
//         cin >> A >> B >> C;

//         arr.push_back({C, A, B});
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         parent[i] = i;
//     }

//     sort(arr.begin(), arr.end());

//     int cnt = 0;
//     int ans = 0;

//     for (int i = 0; i < k; i++)
//     {
//         int cost = get<0>(arr[i]);
//         int A = get<1>(arr[i]);
//         int B = get<2>(arr[i]);

//         // cout << cost << " " << A << " " << B << "\n";

//         if (findParent(A, B) == 0)
//         {
//             unionParent(A, B);
//             cnt += 1;
//             ans += cost;
//         }

//         if (cnt == n - 1)
//             break;
//     }

//     cout << ans;
// }

vector<pair<int, int>> adj[10005]; // 비용 , 정점번호

bool chk[10005];

priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; // 비용 , 정점 1 ,정점 2

// 프림 알고리즘
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        int A, B, C;
        cin >> A >> B >> C;

        adj[A].push_back({C, B});
        adj[B].push_back({C, A});
    }

    int ans = 0;
    int cnt = 0;
    chk[1] = 1;

    for (auto nxt : adj[1])
    {
        pq.push({nxt.first, 1, nxt.second});
    }
    while (cnt < n - 1)
    {
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        if (chk[b] == 1)
            continue;
        ans += cost;
        chk[b] = 1;
        cnt += 1;

        for (auto nxt : adj[b])
        {
            if (!chk[nxt.second])
            {
                pq.push({nxt.first, b, nxt.second});
            }
        }
    }

    cout << ans;
}
