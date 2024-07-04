class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
            vector<pair<int, int>> v(dist.size());
    for(int i = 0; i < dist.size(); i++) {
        v[i] = {dist[i], speed[i]};
    }

    sort(v.begin(), v.end(), [](pair<int, int> p1, pair<int, int> p2) {
        return (double)p1.first / p1.second < (double)p2.first / p2.second;
    });

    int cnt = 1;

    for(int i = 1 ; i < dist.size() ; i++){
        int distt = v[i].first - i * v[i].second;
        if(distt > 0)
            cnt++;
        else{
           return cnt;
        }
    }

        return cnt;
    }
};
