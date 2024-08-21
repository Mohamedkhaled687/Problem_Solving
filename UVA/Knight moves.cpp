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
int dr[8] = {2 , -2 , -2 , 2 , 1 , -1 , 1 , -1};
int dc[8] ={1 , 1 , -1 , -1 , -2 , -2 , 2 , 2};
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // Combine the two hash values
    }
};


bool is_valid(int r , int c){
    return (r >= 1 && r <= 8 && c >= 1 && c <= 8);
}

int bfs(int start_r , int start_c , int req_r , int req_c){
    queue<pp> q;
    unordered_set<pp , pair_hash> visited;

    q.push({start_r , start_c});
    visited.insert({start_r , start_c});

    for(int level = 0 , sz = q.size() ; !q.empty() ; level++ , sz = q.size()){
        while(sz--){
            auto [cur_r , cur_c] = q.front();
            q.pop();

            if(cur_r == req_r && cur_c == req_c)
                return level;

            for(int i = 0 ; i < 8 ; i++){
                int nr = cur_r + dr[i] , nc = cur_c + dc[i];
                if(is_valid(nr, nc) && !visited.count({nr  , nc})){
                    q.push({nr , nc});
                    visited.insert({nr , nc});
                }
            }
        }
    }

    return -1;
}

int main(){
    map<char , int> mp;
    int cnt = 1;

    for(char i = 'a' ; i <= 'h' ; i++){
        mp[i] = cnt;
        cnt ++;
    }

    int t;
    cin >> t;

    while(t--){
        string s1 , s2;
        cin >> s1 >> s2;

        int start_r = s1[1] - '0'; // Extract row as integer
        int start_c = mp[s1[0]];   // Extract column using map
        int req_r = s2[1] - '0';   // Extract row as integer
        int req_c = mp[s2[0]];     // Extract column using map

        cout << bfs(start_r , start_c , req_r , req_c) << endl;
    }
}
