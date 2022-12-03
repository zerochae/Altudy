#include <bits/stdc++.h>
using namespace std;

int n;

int arr[55][10];

int tmp[55][10];

vector<int> state;

bool runner[4] = {0};

stack<pair<int, int>> s;

void combinationPlayer(vector<int> state) // 조합에 따라 선수를 바꿈
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            tmp[i][j] = arr[i][state[j]];
        }
    }
    return;
}

int returnRunnerDigits(int runnerNumber)
{
    if (runnerNumber < 9)
        return runnerNumber + 1;
    if (runnerNumber == 9)
        return 1;
    return 0;
}

int run(int score)
{
    int total = 0;
    runner[0] = 1;
    for (int i = 3; i >= 0; i--)
    {
        if (runner[i] == 0)
            continue;
        runner[i] = 0;
        if (i + score > 3)
        {
            total++;
        }
        else
        {
            runner[i + score] = 1;
        }
    }

    return total;
}

pair<int, int> scoreCalculations(int inning, int runnerNumber)
{
    int cnt = 0;
    int score = 0;
    fill(runner, runner + 4, 0); // 이닝 시작
    while (cnt < 3)

    {

        if (tmp[inning][runnerNumber] > 0)
        {
            score += run(tmp[inning][runnerNumber]);
        }

        if (tmp[inning][runnerNumber] == 0)
        {
            cnt++;
        }

        runnerNumber = returnRunnerDigits(runnerNumber);
    }

    return {score, runnerNumber};
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int ans = 0;

    for (int k = 1; k <= n; k++)
    {

        for (int i = 1; i <= 9; i++)
        {
            cin >> arr[k][i];
        }
    }

    state.push_back(0);
    for (int i = 1; i <= 9; i++)
    {
        state.push_back(i);
    }

    do
    {
        vector<int> newState;
        newState.push_back(0);

        for (int i = 2; i <= 4; i++)
        {
            newState.push_back(state[i]);
        }

        newState.push_back(1);

        for (int i = 5; i <= 9; i++)
        {
            newState.push_back(state[i]);
        }

        int score = 0;
        combinationPlayer(newState);

        int runnerNumber = 1;
        for (int i = 1; i <= n; i++)
        {
            auto cur = scoreCalculations(i, runnerNumber);
            score += cur.first;
            runnerNumber = cur.second;
        }

        ans = max(ans, score);

    } while (next_permutation(state.begin() + 2, state.end()));

    cout << ans;
}
