#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ll long long
#define vii vector<int>
#define vib vector<bool>
#define vil vector<int>
#define vis vector<string>
#define pp pair<int, int>
#define inf 1e9
#define GRAPH vector<vector<char>>
#define tests int t;cin >> t; while(t--)
const double EPS = 1e-9;
const double pi = 3.14159265358979323846;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // Combine the two hash values
    }
};


int main() {
    fast

    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<char>> graph(n, vector<char>(m));
    unordered_map<char, vector<pp>> mp;
    vector<pp> shift_key;

    // Reading the keyboard layout
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            char c = graph[i][j];

            if (c == 'S') {
                shift_key.push_back({i, j});
            } else {
                mp[c].push_back({i, j});
            }
        }
    }

    unordered_map<char, double> min_dist;

    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (mp.find(ch) == mp.end()) continue;

        double min_distance = inf;

        for (auto &pos : mp[ch]) {
            for (auto &shift_pos : shift_key) {
                int r = pos.first, c = pos.second;
                int sr = shift_pos.first, sc = shift_pos.second;
                double dist = sqrt(pow(r - sr, 2) + pow(c - sc, 2));

                min_distance = min(min_distance, dist);
            }
        }
        min_dist[ch] = min_distance;
    }

    int str_length;
    cin >> str_length;
    string s;
    cin >> s;

    int cnt = 0;

    for (char c : s) {
        if (islower(c)) {
            if (mp.find(c) == mp.end()) {
                cout << -1;
                return 0;
            }
        } else {
            char lower_c = tolower(c);

            if (mp.find(lower_c) == mp.end() || shift_key.empty()) {
                cout << -1;
                return 0;
            }

            if (min_dist[lower_c] > x) {
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;

}
