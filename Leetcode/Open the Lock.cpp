class Solution {
   
bool process(vector<string>& deadends, queue<string>& q, string neighbour, unordered_set<string>& visited, string target) {
        if(neighbour == target)
            return true;
        if(!visited.count(neighbour) && find(deadends.begin(), deadends.end(), neighbour) == deadends.end()) {
            visited.insert(neighbour);
            q.push(neighbour);
        }
        return false;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if(visited.count("0000")) return -1;

        queue<string> q;
        visited.insert("0000");
        q.push("0000");

        if("0000" == target)
            return 0;

        for(int level = 0; !q.empty(); ++level) {
            int sz = q.size();
            while(sz--) {
                string cur = q.front();
                q.pop();

                for(int i = 0; i < 4; ++i) {
                    string temp = cur;
                    temp[i] = (cur[i] - '0' + 1) % 10 + '0';
                    if(process(deadends, q, temp, visited, target))
                        return level + 1;
                    
                    temp = cur;
                    temp[i] = (cur[i] - '0' - 1 + 10) % 10 + '0';
                    if(process(deadends, q, temp, visited, target))
                        return level + 1;
                }
            }
        }
        return -1;
    }
};
