#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>

const double pi = 3.141592653589793;


int main() {
    fast

    int n = 4;
    vector<vector<char>> arr(n , vector<char>(n));

    for(auto &i : arr){
        for(auto &j : i)
            cin >> j;
    }


    for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - 1 ;j++){
            int freq[200] = {0};
            freq[arr[i][j]]++;
            freq[arr[i+1][j]]++;
            freq[arr[i][j+1]]++;
            freq[arr[i+1][j+1]]++;

            int diff = n - max(freq['#'] , freq['.']);
            if(diff <= 1){
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";


}
