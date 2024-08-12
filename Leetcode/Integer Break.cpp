
// link : https://leetcode.com/problems/integer-break/description/

class Solution {
    int memory[60];
public:
	int productSum(int n) {
		if (n == 1)
			return 1;

		auto &ret = memory[n];
		if (ret != -1)
			return ret;

		ret = n;	// default don't divide
		for (int i = 1; i < n; i++)
			ret = max(ret, i * productSum(n - i));

		return ret;
	}

	int integerBreak(int n) {
		// Special case for these 2 numbers: must k >= 2
		if (n == 2 || n == 3)
			return n-1;
		memset(memory, -1, sizeof(memory));
		return productSum(n);
	}
};
