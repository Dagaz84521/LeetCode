#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string doule_s = s+s;
        string target = "01";
        int result = n;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j = j+2){
                if(j == n-1 && n%2 ==1)//奇数情况
                    cnt += target[0] != doule_s[i+j]?1:0;
                else{
                    cnt += target[0] != doule_s[i+j]?1:0;
                    cnt += target[1] != doule_s[i+j+1]?1:0;
                }
            }
            result = min(cnt,result);
        }
        return result;
    }
};