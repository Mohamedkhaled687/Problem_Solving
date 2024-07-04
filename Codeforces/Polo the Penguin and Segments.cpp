#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>

const double pi = 3.141592653589793;


int main() {
    fast

    int n , k;
    cin >> n >> k;

//    vector<pair<int , int>> v(n);
    int covered_dist = 0;

    for(int i = 0 ; i < n ;i++){
        int x , y;
        cin >> x >> y;
        covered_dist += (y - x + 1);
    }


    if(covered_dist % k == 0)
        cout << 0;
    else{
        int temp = covered_dist / k + 1;
        cout << (temp) * k - covered_dist;
    }

}
