#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        else{
            string str = countAndSay(n-1);
            string result = "";
            int count = 1;
            for(int i=0;i<str.size();i++){
                if(i+1<str.size() && str[i]==str[i+1]){
                    count++;
                }else{
                    result += to_string(count) + str[i];
                    count = 1;
                }
            }
            return result;
        }
    }
};