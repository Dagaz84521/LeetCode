#include<cmath>
#include<vector>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        vector<int> f(n+1,INT_MAX/2);
        f[0] = 0;
        for(int i = 1; i <= m; i++){
            for(int j = pow(i,2); j <= n; j++){
                f[j] = min(f[j],f[j-pow(i,2)]+1);
            }
        }
        return f[n] < INT_MAX / 2 ? f[n] : 0;
    }
};