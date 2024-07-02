#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
#define ll long long
#define vi vector<int>

bool isPossible(double angle){

    double n = 360 / (180 - angle);

    return n == int (n);
}


int main(){

    fast

    int t;
    cin >> t;

    while(t--){
        double a ; cin >> a;
        cout << (isPossible(a) ? "YES" : "NO") << endl;
    }

}
