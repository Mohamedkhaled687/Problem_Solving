// link : B. Mr. Kitayuta's Colorful Graph

#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ll long long
#define vii vector<int>
#define vib vector<bool>
#define vil vector<int>
#define vis vector<string>
#define pp pair<int, int>
#define GRAPH vector<vector<int>>
int mx = INT_MIN;
int mn = INT_MAX;
const double EPS = 1e-9;
const double pi = 3.14159265358979323846;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2; // Combine the two hash values
    }
};


void dfs(vector<vector<pp>> &graph , int node , int color , unordered_set<pp , pair_hash> &visited , map<int , set<int>> &mp , int parent){
    if(visited.find({node , color}) != visited.end())
        return ;

    visited.insert({node , color});
    mp[node].insert(color);

    for(auto &neighbour : graph[node]){
        if(neighbour.first == parent)
            continue;
        if(neighbour.second != color)
            continue;
        dfs(graph , neighbour.first , neighbour.second , visited , mp , node);
    }
}

int main() {
    fast;

    int nodes , edges;
    cin >> nodes >> edges;

    vector<vector<pp>> graph(nodes + 1);

    for(int i = 0 ; i < edges ; i++){
        int from , to , color;
        cin >> from >> to >> color;
        graph[from].push_back({to , color});
        graph[to].push_back({from , color});
    }

    int q;
    cin >> q;

    while(q--){
        int from , to;
        cin >> from >> to;

        unordered_set<pp , pair_hash> visited;
        map<int , set<int>> mp;

        for(auto &neighbour : graph[from]){
            dfs(graph , neighbour.first , neighbour.second , visited , mp , from);
        }

        auto it = mp[to];

        cout << it.size() << endl;
    }


}
