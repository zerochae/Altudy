#include <bits/stdc++.h>
using namespace std;

int n;

int num[21];

vector<tuple<int, int, int, string>> students;

// int score[100005][4];

bool cmp(tuple<int, int, int, string> a, tuple<int, int, int, string> b)
{
    if (get<0>(a) != get<0>(b))
    {
        return get<0>(a) > get<0>(b);
    }
    if (get<1>(a) != get<1>(b))
    {
        return get<1>(a) < get<1>(b);
    }
    if (get<2>(a) != get<2>(b))
    {
        return get<2>(a) > get<2>(b);
    }
    return get<3>(a) < get<3>(b);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string name;
        int kor, eng, math;
        cin >> name >> kor >> eng >> math;
        students.push_back({kor, eng, math, name});
    }

    sort(students.begin(), students.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        cout << get<3>(students[i]) << "\n";
    }
}
