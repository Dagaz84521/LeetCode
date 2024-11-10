#include<vector>
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int n = words.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(isExpressive(s, words[i])){
                ans++;
            }
        }
        return ans;
    }

    bool isExpressive(string s, string word){
        int n = s.size(), m = word.size();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(s[i] == word[j]){
                int cnt1 = 1, cnt2 = 1;
                while(i + 1 < n && s[i] == s[i + 1]){
                    i++;
                    cnt1++;
                }
                while(j + 1 < m && word[j] == word[j + 1]){
                    j++;
                    cnt2++;
                }
                if(cnt1 < cnt2 || (cnt1 < 3 && cnt1 != cnt2)){
                    return false;
                }
                i++;
                j++;
            }
            else{
                return false;
            }
        }
        return i == n && j == m;
    }
};