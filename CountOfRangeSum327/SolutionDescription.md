**Problem:**  
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ≤ j), inclusive.

Note:  
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:  
Given nums = [-2, 5, -1], lower = -2, upper = 2,   
Return 3.  
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.


**Solution:**  
This can be solved by applying Divide and Conquer method.

Divide:  
When vector has more than one element, recursively split it into two subvectors until subvectors only have one element.

Conquer:  
The vector only has one or no element, then simply examine whether this element is in the given bound.

Combine:  
This is the most important and complex part in this whole algorithm.  
Total possible range number (sum) is the sum of three parts: 

1. Possible range number of left subvector (sum1)  
2. Possible range number of right subvector (sum2)  
3. Number of possible ranges start in left subvector, and end in right subvector (sum3) 

Since possible ranges in the third situation must start in left subvector, and end in right subvector, it means that range always include
the last element of left subvector and the first element of right subvector. That is, each possible range consists of two ranges, the one
range starts in left subvector and ends at the last element of left subvector. The other range starts at the first element of right
subvector and ends in the right subvector.

The third step of Combine pseudocode:   

    Calculate every ranges left_sum[i], which means the range sum starts at index i and ends at the end of left subvector.  
    Calculate every ranges right_sum[i], which means the range sum start at the index 0 and ends at index i of right subvector.  
    Sort left_sum and right_sum in ascending order.  
    
    Set iter_right_lower, iter_right_upper, and sum3 to 0    
    Traverse left_sum in descending order, that is, start from left_sum[left_size-1] to left_sum[0], for each left_sun[iter_left]    
      Start from index iter_right_lower of right_sum, and increase by 1, until reach the end    
        Find the first index iter_right_lower, which satisfy left_sum[iter_left] + right_sum[iter_right_lower] >= lower  
      Start from index iter_right_upper of right_sum, and increase by 1, until reach the end  
        Find the first index iter_right_upper, which satisfy left_sum[iter_left] + right_sum[iter_right_upper] > upper  
      Number of possible ranges start at index iter_left (temp)= iter_right_upper - iter_right_lower   
      Let sum3 add up temp  

**Analysis:**

Devide:   
Vector is divided into two sub vector with size n/2

Conquer:   
O(1)

Conbine:  
Sort costs O(nlogn)

Traverse costs O(n), since iter_right_lower and iter_right_upper only increase and go through right subvector only once   
Thus, total complexity T(n) = 2T(n/2) + O(nlogn) => T(n) = O(nlogn)  
T(n) is better than O(n^2)



