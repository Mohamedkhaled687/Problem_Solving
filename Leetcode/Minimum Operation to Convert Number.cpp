// link : https://leetcode.com/problems/minimum-operations-to-convert-number/

// Code

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        // Initial validation
        if(start == goal) return 0;
        if(start < 0 || start > 1000) return -1;

        vector<bool> visited(1001, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        for(int level = 0; !q.empty(); ++level) {
            int sz = q.size();
            while(sz--) {
                int cur = q.front();
                q.pop();

                for(int i = 0; i < nums.size(); ++i) {
                    int a = cur + nums[i], b = cur - nums[i], c = cur ^ nums[i];
                    if(process(visited, q, a, goal) ||
                       process(visited, q, b, goal) ||
                       process(visited, q, c, goal)) {
                        return level + 1;
                    }
                }
            }
        }

        return -1;
    }
private:
    bool process(vector<bool> &visited, queue<int> &q, int neighbour, int goal) {
        if(neighbour == goal)
            return true;

        if(neighbour >= 0 && neighbour <= 1000 && !visited[neighbour]) {
            visited[neighbour] = true;
            q.push(neighbour);
        }

        return false;
    }
};
