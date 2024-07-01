#include <bits/stdc++.h>

using namespace std;

using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<ll>

int main(){

    fast

    ll n , k;
    cin >> n >> k;

    ll half = ceil(n / 2.00);

    if(k <= half)
        cout << 2*k - 1;
    else
        cout << (k - half) * 2;


}
