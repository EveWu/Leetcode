# Problem  
Given a string containing just the characters ```'('``` and ```')'```, find the length of the longest valid (well-formed) parentheses substring.

For ```"(()"```, the longest valid parentheses substring is ```"()"```, which has length = 2.

Another example is ```")()())"```, where the longest valid parentheses substring is ```"()()"```, which has length = 4.  
# Solution
When it comes to valid parentheses, stack is always a choice.  
Let ```0``` denotes ```'('```, and any number ```>0``` denotes the maximum count of valid parentheses ends at that position.  
Let ```max``` represents the pair of longest valid parentheses so far.  
Let s[i] denote ith character, then:  
* If s[i] is ```'('```, then push a ```0``` into the stack
* If s[i] is ```')'```, then check whether there is ```'('``` in stack
  * If there is no ```0``` in the stack, which means any ```')'``` afterwards cannnot make a match with the ```'('``` before, then empty the stack
  * Else if there is a ```'('```, then check whether there are parentheses between them  
    * If the top of the stack is ```0```, then pop it and let ```count``` be 1
    * Else if the top of the stack is not ```0```, then ```0``` must be in the second top, pop twice and let ```count``` be ```top number + 1``` 
    * Then check the top of the stack  
      If the top of the stack is not ```0```, which means there exist valid parentheses, then let ```count``` increased by ```top number```, which means to connect these two parts
    * If ```count > max```, then update ```max``` with ```count```  

Then the longest length will be ```2*max```.  
# Analysis
As we only need traverse the string once, the time complexity is O(n).
