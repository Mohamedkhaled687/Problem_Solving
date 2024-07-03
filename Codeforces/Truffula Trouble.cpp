#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<ll>

const double pi = 3.141592653589793;

bool canSelectWithDurability(const vector<int>& v, int N, int K, int durability) {
    int thneed = 0;
    for (int i = 0; i < N; i++) {
        if (durability >= v[i] && thneed < K) {
            thneed++;
            i++;  // Skip the next element
            durability--;
        } else if (durability == 0) {
            break;
        }
    }
    return thneed >= K;
}

int main() {
    fast;

    int N, K;
    cin >> N >> K;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    if (N / 2 < K - 1) {
        cout << -1 << endl;
    } else {
        long long high = 1e10;
        long long low = 0;
        long long best = 0;

        while (high >= low) {
            int mid = low + (high - low) / 2;
            if (canSelectWithDurability(v, N, K, mid)) {
                high = mid - 1;
                best = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << best << endl;
    }

    return 0;
}
