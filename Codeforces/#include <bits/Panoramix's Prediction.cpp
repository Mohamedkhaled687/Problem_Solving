#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
#define ll long long
#define vi vector<int>

bool isPrime(int n){
    if(n == 2)
        return true;
    if(n == 1 || n % 2 == 0)
        return false;

    for(int i = 2 ; i <= sqrt(n) ; i++){
        if(n % i == 0)
            return false;
    }

    return true;
}

int main(){

  fast

    int n , m;
    cin >> n >> m;

    if(!(isPrime(n) && isPrime(m))){
        cout << "NO";
        return 0;
    }

    for(int i = n + 1 ; i <= m ;i++){
        if(isPrime(i)){
            if(i == m){
                cout << "YES";
            }
            else{
                cout << "NO";
            }
            break;
        }
    }
}
