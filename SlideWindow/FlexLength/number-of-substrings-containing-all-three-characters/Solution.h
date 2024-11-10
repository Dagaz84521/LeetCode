#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt[3];
        int left = 0, right = 0;
        int n = s.size();
        int ans = 0;
        while(right < n){
            cnt[s[right]-'a']++;
            
            while(cnt[0]>0 && cnt[1]>0 && cnt[2]>0){
                cnt[s[left]-'a']--;
                left++;
            }
            ans += left;
            right++;
        }
        return ans;
    }
};