#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    
        
    int len = s.size();
    
    int answer = len;
    
    int n = len/2;
    
    for(int i=1;i<=n;i++){
        string result ="";
        
        string ss = s.substr(0,i);
        
        int cnt =1;
        
        
        for(int j=i;j<=len;j+=i){
            string sj = s.substr(j,i);
            

            
            if(ss == sj){
                            // cout << sj<<" "<<ss<<"\n";
                cnt++;
            }else{
                if(cnt ==1){
                  result +=ss;  
                }else{
                    // cout << cnt <<"\n";
                    result += (to_string(cnt)+ss);
                }
                
                            ss = s.substr(j,i);
            
            cnt =1;
            }
            

            

        }
        
                    // cout << result <<"\n";
            
            if(len % i !=0){
                result += s.substr((len/i)*i);
                cout << len/i <<" "<< (len/i)*i <<" "<<i<<"\n";
            }
            
            // cout << result <<"\n";
            
            int number = result.size();
            answer = min(answer,number);
    }
    
    return answer;
}