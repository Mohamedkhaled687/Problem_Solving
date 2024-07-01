#include <iostream>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<ll>

int main() {
  fast
  
    ll l, r;
    cin >> l >> r;

    if (r - l < 2) {
        cout << -1 << endl;
    } else {
        // If l is even, we can directly use (l, l+1, l+2)
        if (l % 2 == 0) {
            cout << l << " " << l+1 << " " << l+2 << endl;
        } else {
            // If l is odd and r-l >= 3, we can use (l+1, l+2, l+3)
            if (r - l >= 3) {
                cout << l+1 << " " << l+2 << " " << l+3 << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
