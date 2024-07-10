#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>

const double pi = 3.141592653589793;
const double EPS = 1e-9; // Adjusted for precision

int number_of_pies, peoples;

bool can(double piece, vi &radii) {
    int cnt = 0;

    for (int i = 0; i < radii.size(); i++) {
        double result = pi * radii[i] * radii[i];
        cnt += static_cast<int>(result / piece);
    }

    return cnt >= peoples;
}

int main() {
    fast

    cin >> number_of_pies >> peoples;

    vi radius_pies(number_of_pies);

    int mx = 0;

    for (auto &i : radius_pies) {
        cin >> i;
        mx = max(mx, i);
    }

    double start = 0, end = pi * mx * mx, ans = 0;

    while (fabs(end - start) > EPS) {
        double piece = (start + end) / 2;

        if (can(piece, radius_pies)) {
            ans = piece;
            start = piece;
        } else {
            end = piece;
        }
    }

    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}
