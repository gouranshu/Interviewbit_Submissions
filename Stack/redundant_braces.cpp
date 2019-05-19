https://www.interviewbit.com/problems/redundant-braces/

Problem: 

Write a program to validate if the input string has redundant braces?
Return 0/1

0 -> NO
1 -> YES

Input will be always a valid expression

and operators allowed are only + , * , - , /

Example:

((a + b)) has redundant braces so answer will be 1
(a + (a + b)) doesn't have have any redundant braces so answer will be 0

Approach:

We keep pushing elements onto the stack till we encounter ')'. When we do encounter ')', we start popping elements till we find a matching '('. 
If the number of elements popped do not correspond to '()', we are fine and we can move forward. 
Otherwise, voila! Matching braces have been found. 

Solution:
int Solution::braces(string A) {
    stack<char> stk;
    
    int n = A.size();
    
    for(int i=0; i<n; i++)
    {
        if(A[i] != ')')
        {
            stk.push(A[i]);
        }
        else
        {
            int count = 0;
            while(stk.top()!= '(')
            {
                stk.pop();
                count++;
            }
            stk.pop(); // pp '('
            if(count <2) //if only one element or no element popped => redundant brace
            {
                return 1;
            }
        }
    }
    
    if(!stk.empty() && ( stk.top() == '(' || stk.top() == ')') )
    {
        return 1;
    }
    
    return 0;
}
