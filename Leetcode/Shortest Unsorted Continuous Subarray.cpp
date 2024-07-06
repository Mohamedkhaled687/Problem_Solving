#include <bits/stdc++.h>

using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long
#define vi vector<int>

const double pi = 3.141592653589793;

int main() {
    fast

    int n;
    cin >> n;

    vi nums(n);
    for(auto &i : nums)
        cin >>i;


    int right = -1 , left = -1 , mnSofar = INT_MAX , mxsofar = INT_MIN;

    for(int i = 0 ; i < nums.size(); i++){
        mxsofar = max(nums[i] , mxsofar);
        if(mxsofar > nums[i])
            right = i;
    }
    for(int i = (int) nums.size() ; i >= 0 ; i--){
        mnSofar = min(mnSofar , nums[i]);
        if(mnSofar < nums[i])
            left = i;
    }

    cout << right - left + 1;


}
