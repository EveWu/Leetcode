class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size(), len2 = nums2.size(), total = len1 + len2;
		double median = 0.0;
		if (len1 == 0 && len2 == 0) return 0;
	if (len1 > len2) return findMedianSortedArrays(nums2, nums1);  // ensure len1 < len2
	if (len1 == 0) return (nums2[(len2-1)/2] + nums2[len2/2]) / 2.0;
	// len1 != 0 && len2 != 0 && len1 < len2
	int left = 0, right = len1, i, j, l1, l2, r1, r2;
	while(left <= right) {
		
		i = (left + right) / 2;
		j = (len1 + len2 + 1) / 2 - i;
		//cout<<left<<" "<<right<<" "<<i<<" "<<j<<endl;
		l1 = (i == 0) ? INT_MIN : nums1[i-1];
		r1 = (i == len1) ? INT_MAX : nums1[i];
		l2 = (j == 0) ? INT_MIN : nums2[j-1];
		r2 = (j == len2) ? INT_MAX : nums2[j];
		if (l1 <= r2 && l2 <= r1) {
			if (total % 2 == 0) {
				median = (max(l1,l2) + min(r1,r2)) / 2.0;
			} else {
				median = max(l1,l2);
			}
			break;
		} else if (l1 > r2) {
			right = i - 1;
		} else if (l2 > r1) {
			left = i + 1;
		}
	}
	return median;
}
};