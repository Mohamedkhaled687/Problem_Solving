#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

int main() {
    fast

    string s, un_touched;
    cin >> s >> un_touched;

    string s1, s2;
    int i = 0;

    while (s[i] != '|') {
        s1 += s[i];
        i++;
    }

    i++;
    while (i < s.size()) {
        s2 += s[i];
        i++;
    }

    int total = s1.size() + s2.size() + un_touched.size();
    if (total % 2 != 0) {
        cout << "Impossible";
        return 0;
    }

    int target = total / 2;

    if (s1.size() > target || s2.size() > target) {
        cout << "Impossible";
        return 0;
    }

    while (s1.size() < target && !un_touched.empty()) {
        s1 += un_touched.back();
        un_touched.pop_back();
    }

    while (s2.size() < target && !un_touched.empty()) {
        s2 += un_touched.back();
        un_touched.pop_back();
    }

    if (s1.size() == target && s2.size() == target) {
        cout << s1 << '|' << s2;
    } else {
        cout << "Impossible";
    }

    return 0;
}
