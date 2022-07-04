#include <bits/stdc++.h>
using namespace std;

int n;

int arr[50][2];

void DFS(int st) // 중위순회
{
    if (st == -1)
        return;

    DFS(arr[st][0]);
    cout << (char)(st + 'A');
    DFS(arr[st][1]);
}

void bfs2(int st) // 후위순회
{
    if (st == -1)
        return;

    bfs2(arr[st][0]);
    bfs2(arr[st][1]);
    cout << (char)(st + 'A');
}

void bfs(int st) // 전위순회
{

    if (st == -1)
        return;
    cout << (char)(st + 'A');

    bfs(arr[st][0]);
    bfs(arr[st][1]);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char a, b, c;

        cin >> a >> b >> c;

        int one = a - 'A';

        if (b != '.')
        {
            arr[one][0] = b - 'A';
        }
        else
        {
            arr[one][0] = -1;
        }

        if (c != '.')
        {
            arr[one][1] = c - 'A';
        }
        else
        {
            arr[one][1] = -1;
        }
        // cout << one << " " << two << " " << three << "\n";
    }

    // q.push(0);

    bfs(0); // 전위순회

    cout << "\n";

    DFS(0);
    cout << "\n";
    bfs2(0);
}
