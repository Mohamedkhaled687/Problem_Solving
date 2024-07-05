class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() && k > 0; ++i) {
            if (nums[i] < 0) {
                nums[i] *= -1;
                k--;
            }
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int mn = *min_element(nums.begin(), nums.end());

        if (k % 2) {
            sum -= 2 * mn;
        }

        return sum;
    }
};
