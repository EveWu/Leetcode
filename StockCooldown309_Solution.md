# Problem
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

* You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).  
* After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)  

**Example:**
```
prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
```
# Solution
There are three operations, as `buy`, `sell`, and `rest`.  
We define that:  
``` 
buy[i]: The maximum profit of any sequence end at "buy" operation before ith day (including ith day).  
sell[i]: The maximum profit of any sequence end at "sell" operation before ith day (including ith day).  
rest[i]: The maximum profit of any sequence end at "rest" operation before ith day (including ith day).  
```  
From above definition, we can have following equalence:  
```
buy[i] = max(buy[i-1], rest[i-1]-prices)
sell[i] = max(sell[i-1], buy[i-1]+prices)
rest[i] = max(buy[i-1], sell[i-1], rest[i-1])
```
Since `sell[i-1]>=rest[i-1]>=buy[i-1]`, it is clearly that `rest[i] = sell[i-1]`.  
Then we have:  
```
buy[i] = max(buy[i-1], sell[i-2]-prices)  
sell[i] = max(sell[i-1], buy[i-1]+prices)  
```
Thus, `sell[n]` is the maximum profit.
Solution idea came from [dietpepsi's discussion](https://discuss.leetcode.com/topic/30421/share-my-thinking-process).

# Analysis  
As we only need traverse the array once, the time complexity is O(n).
