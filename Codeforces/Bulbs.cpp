#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, blue_bulbs = 0;
    cin >> n;

    vector<int> arr(n + 1);
    int max_bulb = 0;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        max_bulb = max(max_bulb, arr[i]);
        if (max_bulb == i)  // If all bulbs up to i are turned on
            blue_bulbs++;
    }

    cout << blue_bulbs;
    return 0;
}
