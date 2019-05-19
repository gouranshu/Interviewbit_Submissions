https://www.interviewbit.com/problems/evaluate-expression/ 
EVALUATE POSTFIX EXPRESSION
https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/

Following is algorithm for evaluation postfix expressions.
1) Create a stack to store operands (or values).
2) Scan the given expression and do following for every scanned element.
…..a) If the element is a number, push it into the stack
…..b) If the element is a operator, pop operands for the operator from stack. Evaluate the operator and push the result back to the stack
3) When the expression is ended, the number in the stack is the final answer

This is pretty much a simulation problem.
Think stack.

When you encounter an operator is when you need the top 2 numbers on the stack, perform the operation on them and put them on the stack.


int Solution::evalRPN(vector<string> &A) {
    stack<string> st;
    
    for(int i=0; i<A.size(); i++)
    {
        if(A[i] == "*" || A[i] == "/" || A[i] == "+" || A[i] == "-")
        {
            int val1 = stoi(st.top()); //convert to int
            st.pop();
            int val2 = stoi(st.top());
            st.pop();
            switch (A[i][0])  //A[i] is a string (char arry), switch statement works only for int or char. A[i][0] is a char containing the operator.
            {  
                case '+': st.push(to_string(val2 + val1)); break;  
                case '-': st.push(to_string(val2 - val1)); break;  
                case '*': st.push(to_string(val2 * val1)); break;  
                case '/': st.push(to_string(val2/val1)); break;  
            }
        }
        else
        {
            st.push(A[i]); //push non-operators onto the stack
        }
    }
    return stoi(st.top()); //topmost element (only element on stack) contains result (in string format)
}
