#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0;
        for(int i = 0; i < k;i++){
            if(blocks[i]=='W')
                count++;
        }
        int result = count;
        for(int i = k; i<blocks.size();i++){
            count = count + ((blocks[i] == 'W')?1:0);
            count = count + ((blocks[i-k] == 'W')?-1:0);
            result = min(count,result);
        }
        return result;
    }
};