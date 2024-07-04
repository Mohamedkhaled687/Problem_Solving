class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

      sort(arr.begin(), arr.end());

    vector<vector<int>> v;

    int min_diff = INT_MAX;

    for(int i = 0, j = i + 1; j < arr.size(); i++, j++) {
        min_diff = min(min_diff, abs(arr[j] - arr[i]));
    }

    for(int i = 0, j = i + 1; j < arr.size(); i++, j++) {
        if(abs(arr[j] - arr[i]) == min_diff) {
            v.push_back({arr[i], arr[j]});
        }
    }
    
    return v;
    }
};
