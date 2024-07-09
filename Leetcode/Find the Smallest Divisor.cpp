#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto can = [&](double mid) {
            int result = 0;
            for (auto &i : nums)
                result += ceil(i / mid);
            return result <= threshold;
        };

        double start = 1, end = *max_element(nums.begin(), nums.end());
        double ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (can(mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }
};
