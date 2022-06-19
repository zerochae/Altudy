#include <bits/stdc++.h>
using namespace std;

int n, m;

int arr[1030];
int d[1030];



int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

int ans =0;
  reverse(arr,arr+n);


  for(int i=0;i<n;i++){
      for(int j=0;j<i;j++){
          if(arr[i]>arr[j]){
              d[i] = max(d[i],d[j]+1);
          }

}
  }

  ans = *max_element(d,d+n)+1;

    cout<< ans;

}
