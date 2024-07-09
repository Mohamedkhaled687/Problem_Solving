#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        
        auto can = [&](int radius) {
            int j = 0;
            for (int i = 0; i < heaters.size(); i++) {
                int left = heaters[i] - radius, right = heaters[i] + radius;
                while (j < houses.size() && houses[j] >= left && houses[j] <= right) {
                    ++j;
                }
            }
            return j == (int)houses.size();
        };
        
        int start = 0, end = 1e9;
        int ans = 0;
        
        while (start <= end) {
            int radius = start + (end - start) / 2;
            if (can(radius)) {
                ans = radius;
                end = radius - 1;
            } else {
                start = radius + 1;
            }
        }
        
        return ans;
    }
};

