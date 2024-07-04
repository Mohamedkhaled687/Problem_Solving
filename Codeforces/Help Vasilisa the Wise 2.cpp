#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

bool is_valid(int x) {
    return (x >= 1 && x <= 9);
}

int main() {
    fast

    int r1, r2, c1, c2, d1, d2;
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;

    int a = (r1 + c1 - d2) / 2;
    int b = r1 - a;
    int c = c1 - a;
    int d = r2 - c;

    bool are_distinct = (a != b && a != c && a != d && b != c && b != d && c != d);
    bool sum_check = (d1 == a + d) && (d2 == c + b) && (a + b == r1) && (a + c == c1) && (c + d == r2) && (b + d == c2);
    bool all_valid = is_valid(a) && is_valid(b) && is_valid(c) && is_valid(d);

    if (are_distinct && sum_check && all_valid) {
        cout << a << ' ' << b << '\n' << c << ' ' << d;
    } else {
        cout << -1;
    }

    return 0;
}
