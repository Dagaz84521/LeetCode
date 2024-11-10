#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while(left < right){
            int mid = (left + right) / 2;
            if(arr[mid] < x){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        int idx = left;
        right = idx;
        left = idx - 1;
        while(right - left - 1 < k){
            if(left < 0){
                right++;
            }else if(right >= n){
                left--;
            }else{
                if(x - arr[left] <= arr[right] - x){
                    left--;
                }else{
                    right++;
                }
            }
        }
        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};