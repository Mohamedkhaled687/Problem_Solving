#include <bits/stdc++.h>

using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<char>



int main(){

    fast

    string s;
    cin >> s;

    string result;
    vector<string> strings;
    for(int i = 0 ; i < s.size() ;){
        if(s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B'){
            i+= 3;
            if(!result.empty()){
                strings.push_back(result);
                result.clear();
            }
        }
        else{
            result += s[i];
            i++;
        }
    }

    if(!result.empty())
        strings.push_back(result);

    for(auto &i : strings)
        cout << i << ' ';


}
