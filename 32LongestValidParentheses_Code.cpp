class Solution {
public:
    int longestValidParentheses(string s) {
        int len = (int)s.size(), i, j, left = 0, count = 0, max_count = 0, slen, top;
        stack<int> state;
        for (j = 0; j < len; j++) {
            if (s[j] == '(') {
                left++;
                state.push(0);
            } else {
                if (left == 0) {
                    if (!state.empty()) {
                        count = state.top();
                        state.pop();
                        max_count = max(max_count, count);  
                    }
                } else {
                    if (state.top() == 0) {
                        count = 1;
                        state.pop();
                        if (!state.empty()) {
                            top = state.top();
                            if (top != 0) {
                                count += top;
                                state.pop();
                            }
                        }
                        state.push(count);
                        max_count = max(max_count, count);
                    } else {
                        top = state.top();
                        state.pop();
                        state.pop();
                        count = top+1;
                        if (!state.empty()) {
                            top = state.top();
                            if (top != 0) {
                                count += top;
                                state.pop();
                            }
                        }
                        state.push(count);
                        max_count = max(max_count, count);
                    }
                    left--;
                }
            }
        }
        return max_count * 2;
    }
};