#include <iostream>

using namespace std;

string day_of_week[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int month_day[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int month, day;
    int total_day = 0;
    cin >> month >> day;

    for (int i = 1; i < month; i++)
        total_day += month_day[i - 1]; // 2007년의 월 더하기

    total_day += day + 2;            //초기 날짜 설정 (월요일)
    total_day = (5 + total_day) % 7; //날짜 계산

    cout << day_of_week[total_day]; //요일 출력
}