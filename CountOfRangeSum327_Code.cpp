class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		int num = nums.size();
		// conquer
		if (num == 0) {
			return 0;
		} else if (num == 1) {
			if (nums[0] >= lower && nums[0] <= upper) {
				return 1;
			}
			else {
				return 0;
			}
		}
		// divide
		int middle = num/2, sum1 = 0, sum2 = 0, sum3 = 0, sum = 0;
		vector<int> left(nums.begin(), nums.begin() + middle);
		vector<int> right(nums.begin() + middle, nums.end());
		sum1 = countRangeSum(left, lower, upper);
		sum2 = countRangeSum(right, lower, upper);
		// combine
		int position, current_sum = 0, left_size = middle, right_size = num - middle;
		vector<int> left_sum;
		vector<int> right_sum;
		for (position = left_size - 1; position >= 0; position--) {
			current_sum += left[position];
			left_sum.push_back(current_sum);
		}
		current_sum = 0;
		for (position = 0; position < right_size; position++) {
			current_sum += right[position];
			right_sum.push_back(current_sum);
		}
		sort(left_sum.begin(), left_sum.end());
		sort(right_sum.begin(), right_sum.end());
		
		int iter_left, iter_right = 0, iter_right_upper = 0, iter_right_lower = 0;
		for (iter_left = middle - 1; iter_left >= 0; iter_left--) {
			while (iter_right_lower < right_size) {
				int temp_sum = left_sum[iter_left] + right_sum[iter_right_lower];
				if (temp_sum >= lower) {
					break;
				} else {
					iter_right_lower++;
				}
			}
			while (iter_right_upper < right_size) {
				int temp_sum = left_sum[iter_left] + right_sum[iter_right_upper];
				if (temp_sum > upper) {
					break;
				} else {
					iter_right_upper++;
				}
			}
			if (iter_right_lower == right_size) {
				break;
			}
			int temp = iter_right_upper - iter_right_lower;
			sum3 += temp;
		}
		
		sum = sum1 + sum2 + sum3;
		return sum;
	}
};