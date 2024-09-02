// link : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/

class Solution {
    long long dices;
    long long range;
    long long dp[35][1005];
    long long mod = 1e9 + 7;
public:
    long long numRollsToTarget(long long n, long long k, long long target) {
        dices = n , range = k;

        memset(dp , -1 , sizeof(dp));
        return all_choices(0 , target);

    }
private:
    long long all_choices(long long idx , long long target){
        
        if(idx == dices && target == 0)
            return 1;
        
        if(idx == dices || target <= 0)
            return 0;
        
        
        auto &ret = dp[idx][target];
        
        if(ret != -1)
            return ret;
        
        ret = 0;
        
        for(long long i = 1 ; i <= range ; i++){
            ret += all_choices(idx + 1 , target - i);
            ret %= mod;
        }
        
        return ret;
    }
};
