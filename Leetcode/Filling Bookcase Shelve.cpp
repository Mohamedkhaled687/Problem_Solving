// link : https://leetcode.com/problems/filling-bookcase-shelves/

// COde

class Solution {
public:
    vector<vector<int>> arr;
    int shelf_width;
    int dp[1005];
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        arr = books;
        shelf_width = shelfWidth;
        memset(dp , -1 , sizeof(dp));

        return split(0);
    }

private:
    int split(int idx){
        if(idx >= arr.size())
            return 0;

        auto &ret = dp[idx];

        if(ret != -1)
            return ret;


        ret = INT_MAX;
        int total_width = 0 , mx_height = 0;

        for(int k = idx ; k < arr.size() ; k++){
            int cur_width = arr[k][0] , cur_height = arr[k][1];

            total_width += cur_width;
            mx_height = max(mx_height , cur_height);
            if(total_width > shelf_width)
                break;

            ret = min(ret , mx_height + split(k + 1));
        }

        return ret;
    }
};
