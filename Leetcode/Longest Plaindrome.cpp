#include <bits/stdc++.h>

using namespace std;

string s;
int dp[1000][1000];
string longest_palindrome;

bool is_Palindrome(int r , int c){
    for(int i = r, j = c; i <= j; i++, j--){
        if(s[i] != s[j])
            return false;
    }
    return true;
}

int generate_all(int i , int j){
    if(i > j)
        return 0;

    auto &ret = dp[i][j];

    if(ret != -1)
        return ret;

    if(is_Palindrome(i , j)){
        string result(s.begin() + i, s.begin() + j + 1);
        if ((j - i + 1) > longest_palindrome.size()) {
            longest_palindrome = result;
        }
        return ret = (j - i + 1) + generate_all(i + 1 , j - 1);
    }

    int choice1 = generate_all(i + 1 , j);
    int choice2 = generate_all(i , j - 1);

    return ret = max(choice2 , choice1);
}

int main(){
    fast;

    cin >> s;
    memset(dp, -1, sizeof(dp));

    generate_all(0, s.size() - 1);

    cout << "Longest Palindromic Substring: " << longest_palindrome << endl;

    return 0;
}
