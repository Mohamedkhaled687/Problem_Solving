#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define vii vector<int>
#define vib vector<bool>
#define vil vector<int>
#define vis vector<string>
#define pp pair<int, int>
#define GRAPH vector<vector<int>>
int mx = INT_MIN;
int mn = INT_MAX;

const int INF = 1e9;
const double EPS = 1e-9;
const double pi = 3.14159265358979323846;
int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
map<int, int> val_to_idx;
map<int, int> idx_to_val;

map<int, vector<pair<int, int>>> mp; // Row -> List of intervals

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2; // Combine hashes
    }
};

// Check if cell (r, c) is within any allowed interval on row r
bool is_in_range(int r, int c) {
    if (mp.find(r) == mp.end()) return false;
    const auto& intervals = mp[r];
    for (const auto& [start_c, end_c] : intervals) {
        if (c >= start_c && c <= end_c) return true;
    }
    return false;
}

int BFS(int start_r, int start_c, int end_r, int end_c) {
    queue<pp> q;
    unordered_set<pp, hash_pair> visited;

    q.push({start_r, start_c});
    visited.insert({start_r, start_c});

    int level = 0;

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [cur_r, cur_c] = q.front();
            q.pop();

            if (cur_r == end_r && cur_c == end_c)
                return level;

            for (int i = 0; i < 8; i++) {
                int nr = cur_r + dr[i], nc = cur_c + dc[i];

                if (is_in_range(nr, nc) && !visited.count({nr, nc})) {
                    visited.insert({nr, nc});
                    q.push({nr, nc});
                }
            }
        }
        level++;
    }
    return -1; // Return -1 if there's no path
}

int main() {
    fast;
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    int n;
    cin >> n;

    while (n--) {
        int row, c1, c2;
        cin >> row >> c1 >> c2;
        mp[row].push_back({c1, c2});
    }

    cout << BFS(x0, y0, x1, y1) << '\n';
}
