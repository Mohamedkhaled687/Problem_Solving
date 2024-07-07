class Solution {
public:
    int findFirstOccurrence(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int first_occurrence = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] >= target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }

            if (nums[mid] == target) {
                first_occurrence = mid;
            }
        }

        return first_occurrence;
    }

    int findLastOccurrence(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        int last_occurrence = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] <= target) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }

            if (nums[mid] == target) {
                last_occurrence = mid;
            }
        }

        return last_occurrence;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);

        int first = findFirstOccurrence(nums, target);
        if (first == -1) {
            return result;
        }

        int last = findLastOccurrence(nums, target);

        result[0] = first;
        result[1] = last;

        return result;
    }
};
