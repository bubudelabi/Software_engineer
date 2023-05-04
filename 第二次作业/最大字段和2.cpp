#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums, int left, int right) {
	if (left == right) return nums[left];
	int mid = left + (right - left) / 2;
	int leftMax = maxSubArray(nums, left, mid);
	int rightMax = maxSubArray(nums, mid+1, right);
	int crossMax = nums[mid];
	int sum = nums[mid];
	for (int i = mid-1; i >= left; i--) {
		sum += nums[i];
		crossMax = max(crossMax, sum);
	}
	sum = crossMax;
	for (int i = mid+1; i <= right; i++) {
		sum += nums[i];
		crossMax = max(crossMax, sum);
	}
	return max(leftMax, max(rightMax, crossMax));
}

int main() {
	vector<int> a{1,10,100,1000,10000,100000};
	cout << maxSubArray(a, 0, a.size()-1) << endl;
	return 0;
}
