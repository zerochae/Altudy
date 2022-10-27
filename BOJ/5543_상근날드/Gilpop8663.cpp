#include <bits/stdc++.h>
using namespace std;

string str;

int n = 5;

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int burger = 9999, drink = 9999;
  for (int i = 0; i < 3; i++)
  {
    int num;
    cin >> num;
    burger = min(burger, num);
  }
  for (int i = 0; i < 2; i++)
  {
    int num;
    cin >> num;
    drink = min(drink, num);
  }

  int ans = burger + drink - 50;

  cout << ans;
}
