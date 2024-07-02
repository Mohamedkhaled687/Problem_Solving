#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>


int main() {
    fast

    int n, top;
    cin >> n >> top;

    int last_top = top;
    while (n--) {
        vector<int> freq(7, 0);
        freq[last_top] = 1;
        freq[7 - last_top] = 1;

        int x, y;
        cin >> x >> y;

        freq[x] = 1;
        freq[7 - x] = 1;
        freq[y] = 1;
        freq[7 - y] = 1;

//        for(int &i : freq)
//            cout << i << ' ';
//        cout << endl;

        auto it = find(freq.begin() + 1, freq.end(), 0);
        if (it != freq.end()) {
            cout << "NO";
            return 0;
        }

        last_top = 7 - top;
    }

    cout << "YES";
    return 0;
}
