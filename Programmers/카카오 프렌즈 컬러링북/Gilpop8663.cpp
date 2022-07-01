#include <bits/stdc++.h>

using namespace std;



// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

    bool ch[105][105]={0};

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

queue<pair<int,int>> q;

    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int cnt=0;
            if(ch[i][j] ==1) continue;
            if(picture[i][j] != 0){
                q.push({i,j});
                ch[i][j] =1;
                number_of_area++;
            }

            while(!q.empty()){
                pair<int,int> cur = q.front();
                q.pop();

                int x= cur.first;
                int y= cur.second;

                int num = picture[x][y];

                cnt++;

                for(int k=0;k<4;k++){
                    int nx = x+dx[k];
                    int ny= y+dy[k];
                    if(ch[nx][ny] == 1) continue;
                    if(nx<0 || ny<0 || nx>=m || ny>=n|| picture[nx][ny] ==0) continue;

                    if(picture[nx][ny] == num){
                        q.push({nx,ny});
                        ch[nx][ny]=1;
                    }
                }
            }

            max_size_of_one_area = max(max_size_of_one_area , cnt);
        }
        cout <<"\n";
    }


    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}