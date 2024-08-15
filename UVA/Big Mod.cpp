// link : UVA 374


#include <bits/stdc++.h>

using namespace std;


ll mod_exponential(ll b , ll p , ll m){

    ll result = 1;

    while(p > 0){
        if(p % 2 == 1)
            result = (result * b) % m;

        b = (b * b) % m;
        p /= 2;
    }

    return result;
}

int main(){

    ll b , p , m;
    cin >> b >> p >> m;

    cout << mod_exponential(b , p , m);

}
