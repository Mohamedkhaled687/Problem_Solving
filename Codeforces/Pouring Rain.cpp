#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
#define ll long long
#define vi vector<int>

const double pi = 3.141592653589793;


int main(){

    fast

    double d , h , v , e;
    cin >> d >> h >> v >> e;


    double t = (pi * pow(d / 2 , 2) * h) / (v - pi * pow(d / 2 , 2) * e);

        if(t > 1e-4){
            cout << "YES" << endl;
            cout << fixed << setprecision(12) << t;
        }
        else
            cout << "NO";



}
