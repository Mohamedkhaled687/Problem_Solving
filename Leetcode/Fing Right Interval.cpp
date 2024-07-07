class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> pp(n);
        map<pair<int, int>, int> mp;
        
        for (int i = 0; i < n; ++i) {
            pp[i] = {intervals[i][0], intervals[i][1]};
            mp[{intervals[i][0], intervals[i][1]}] = i;
        }
        
        vector<pair<int, int>> p(pp.begin(), pp.end());
        sort(pp.begin(), pp.end());
        
        vector<int> result(n, -1);
        
        for (int i = 0; i < n; ++i) {
            auto it = upper_bound(pp.begin(), pp.end(), make_pair(p[i].second, INT_MIN));
            if (it != pp.end()) {
                result[i] = mp[{it->first, it->second}];
            }
        }
        
        return result;
    }
