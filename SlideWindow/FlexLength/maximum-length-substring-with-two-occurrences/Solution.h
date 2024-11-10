#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> substr;
        int left = 0, right = 0;
        int result = 0;
        while(right < n){
            substr[s[right]]++;
            while(substr[s[right]] > 2){
                substr[s[left]]--;
                left++;
            }
            right++;
            result = max(result, right-left);
        }
        return result;
    }
};