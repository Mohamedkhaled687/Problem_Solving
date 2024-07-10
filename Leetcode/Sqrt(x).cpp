class Solution {
public:
	double mySqrtD(double value, double EPS = 1e-9) {
		double start = 0, end = value;

		while (end - start > EPS) {
			double mid = start + (end - start) / 2;
			if (mid * mid - value < 0.0)
				start = mid;
			else
				end = mid;
		}
		return start + 1e-9;	// result could be 1.9999999999. Add epislon
	}

	int mySqrt(int x) {
		return mySqrtD(x);
	}
};
