class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
 
          sort(nums.begin(), nums.end() , [](int a , int b){
        return a > b;
    });

    int a , b , c;

    for(int i = 0 ; i < nums.size() - 2 ; i++){
        a = nums[i];
        b = nums[i + 1];
        c = nums[i + 2];

        if((a + b > c) && (a + c > b) && (b + c > a)){
            return a + b + c ;
        }
    }

    return 0;
}
};
