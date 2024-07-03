#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<ll>

const double pi = 3.141592653589793;



int main() {
    fast

    ll x , y;
    cin >> x >> y;

    ll a[5] = {0}; ll b[5] = {0};

    for(ll i = 1 ; i <= x ; i++){
        a[i%5]++;
    }
    for(ll i = 1 ; i <= y ; i++){
        b[i%5]++;
    }

    ll ans = 0;

    for(ll i = 0 ; i <= 4 ; i++){
        for(ll j = 0 ; j <= 4 ; j++){
            if(((i + j) % 5 )== 0){
                ans += a[i] * b[j];
            }
        }
    }

    cout << ans;
}



