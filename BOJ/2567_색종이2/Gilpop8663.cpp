#include <bits/stdc++.h>
using namespace std;

int n;

vector<pair<string, int>> arr;

string nums[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int board[105][105];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    while (n--)
    {
        int row, col;
        cin >> row >> col;

        for (int i = row; i < row + 10; i++)
        {
            for (int j = col; j < col + 10; j++)
            {
                board[i][j] = 1;
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {

            if (board[i][j] == 1)
            {

                for (int k = 0; k < 4; k++)
                {
                    if (board[i + dx[k]][j + dy[k]] == 0)
                    {
                        answer++;
                    }
                }
            }
        }
    }

    cout << answer;
}
