class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
       

  vector<pair<int, int>> v(profit.size());

    for (int i = 0; i < profit.size(); i++) {
        v[i] = {difficulty[i], profit[i]};
    }


    sort(v.begin() , v.end());
    sort(worker.begin() , worker.end());

    int mx = 0;

    int job = 0; int max_profit = 0;
    for (int i = 0; i < worker.size(); i++) {
        for( ; job < profit.size() && worker[i] >= v[job].first ; ++job){
            max_profit = max(max_profit , v[job].second);
        }

        mx += max_profit;

    }

    return mx;
