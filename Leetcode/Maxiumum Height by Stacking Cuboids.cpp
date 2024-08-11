// link : https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // Sort dimensions of each cuboid
        for (auto& cuboid : cuboids) {
            sort(cuboid.begin(), cuboid.end());
        }
        // Sort cuboids based on their base dimensions
        sort(cuboids.begin(), cuboids.end());

        int n = cuboids.size();
        // Initialize dp array
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return max_height(0, -1, cuboids, dp);
    }

private:
    int max_height(int idx, int prev, vector<vector<int>>& cuboids, vector<vector<int>>& dp) {
        if (idx == cuboids.size()) {
            return 0;
        }

        if (dp[idx][prev + 1] != -1) {
            return dp[idx][prev + 1];
        }

        // Option 1: Skip the current cuboid
        int choice1 = max_height(idx + 1, prev, cuboids, dp);

        // Option 2: Use the current cuboid if it can be placed on the previous cuboid
        int choice2 = 0;
        if (prev == -1 || (cuboids[prev][0] <= cuboids[idx][0] &&
                           cuboids[prev][1] <= cuboids[idx][1] &&
                           cuboids[prev][2] <= cuboids[idx][2])) {
            choice2 = cuboids[idx][2] + max_height(idx + 1, idx, cuboids, dp);
        }

        // Store the result in dp array and return the maximum height
        return dp[idx][prev + 1] = max(choice1, choice2);
    }
};
