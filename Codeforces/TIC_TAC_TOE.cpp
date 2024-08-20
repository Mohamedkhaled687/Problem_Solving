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

bool win(const string &cur){
    // Check rows
    for (int i = 0; i < 9; i += 3) {
        if (cur[i] != '.' && cur[i] == cur[i+1] && cur[i+1] == cur[i+2])
            return true;
    }
    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (cur[i] != '.' && cur[i] == cur[i+3] && cur[i+3] == cur[i+6])
            return true;
    }
    // Check diagonals
    if (cur[0] != '.' && cur[0] == cur[4] && cur[4] == cur[8])
        return true;
    if (cur[2] != '.' && cur[2] == cur[4] && cur[4] == cur[6])
        return true;

    return false;
}


bool bfs(string board) {
    queue<pair<string, bool>> q;
    unordered_set<string> visited;

    string start = ".........";
    q.push({start, 1});
    visited.insert(start);

    while (!q.empty()) {
        auto [cur, turn] = q.front();
        q.pop();

        if (cur == board)
            return true;

        if (win(cur))
            continue;

        for (int i = 0; i < 9; ++i) {
            if (cur[i] != '.')
                continue;

            cur[i] = (turn ? 'X' : 'O');

            if (!visited.count(cur)) {
                q.push({cur, !turn});
                visited.insert(cur);
            }
            cur[i] = '.';
        }
    }
    return false;
}

int main() {
    fast;
    int t;
    cin >> t;

    while (t--) {

        string board;
        for(int i = 0 ; i < 3 ; i ++){
            string row;
            cin >> row;
            board += row;
        }


        if (bfs(board)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
