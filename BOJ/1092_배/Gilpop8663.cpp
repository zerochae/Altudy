#include <bits/stdc++.h>
using namespace std;

int n, m;

int crr[55];

bool ch[55] = {0};

vector<int> boxes;
vector<int> tmp;

bool comp(int a, int b)
{
    return a > b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> crr[i];
    }
    sort(crr, crr + n, greater<int>());

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        boxes.push_back(num);
    }
    sort(boxes.begin(), boxes.end(), greater<int>());

    if (boxes[0] > crr[0])
    {
        cout << -1;
        return 0;
    }

    int ans = 0;
    while (!boxes.empty())
    {
        ans++;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < boxes.size(); j++)
            {
                if (crr[i] >= boxes[j])
                {
                    boxes.erase(boxes.begin() + j);
                    break;
                }
            }
        }
    }

    cout << ans;
}