#include <iostream>
using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        if(divisor == 1)
            return dividend;
        if(divisor == -1){
            if(dividend == INT_MIN)
                return INT_MAX;
            return -dividend;
        }
        long a = dividend;
        long b = divisor;
        int sign = 1;
        if((a > 0 && b < 0) || (a < 0 && b > 0))
            sign = -1;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        return sign * recursive(a,b);
    }

    int recursive(long a, long b){
        if(a < b)
            return 0;
        long count = 1;
        long sum = b;
        while(sum + sum <= a){
            sum += sum;
            count += count;
        }
        return count + recursive(a-sum,b);
    }
};