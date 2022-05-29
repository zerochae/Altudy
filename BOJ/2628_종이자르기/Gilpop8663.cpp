#include <bits/stdc++.h>
using namespace std;

int n, m;

int t;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    cin >> t;

    vector<int> ver;
    vector<int> hor;
    vector<int> verAns;
    vector<int> horAns;

    for (int i = 0; i < t; i++)
    {
        int num, dir;
        cin >> dir >> num;

        // cout << dir << num << "\n";
        if (dir == 1)
        {
            hor.push_back(num);
        }
        if (dir == 0)
        {
            ver.push_back(num);
        }
    }

    hor.push_back(n);
    ver.push_back(m);

    sort(hor.begin(), hor.end());
    sort(ver.begin(), ver.end());

    int hNum = 0;
    int vNum = 0;

    for (int i = 0; i < hor.size(); i++)
    {
        if (i == 0)
        {

            horAns.push_back(hor[i]);
        }
        else
        {
            horAns.push_back(hor[i] - hor[i - 1]);
        }
    }
    for (int i = 0; i < ver.size(); i++)
    {
        if (i == 0)
        {

            verAns.push_back(ver[i]);
        }
        else
        {
            verAns.push_back(ver[i] - ver[i - 1]);
        }
    }

    sort(horAns.begin(), horAns.end());
    sort(verAns.begin(), verAns.end());

    // for (int i = 0; i < hor.size(); i++)
    // {
    //     cout << hor[i] << " ";
    // }
    // cout << verAns.back() * horAns.back();
    cout << verAns[verAns.size() - 1] * horAns[horAns.size() - 1];
}
