class Solution {
public:
    int maxArea(vector<int>& height) {
        return recursive(height, 0, height.size()-1);
    }
    int recursive(vector<int>& height, int i, int j) {
        int len = j - i;
        if (len < 1) return 0;
        if (len == 1) return min(height[i], height[j]);
        int left = height[i], right = height[j];
        if (left < right) return max(left * len, recursive(height, i+1, j));
        else return max(right * len, recursive(height, i, j-1));
    }
};