https://www.interviewbit.com/problems/nearest-smaller-element/

APPROACH: Now look at A[i-1]. All elements with index smaller than i - 1 and greater than A[i-1] 
are useless to us because they would never qualify for G[i], G[i+1], ...
Using the above fact, we know that we only need previous numbers in descending order.
   
The pseudocode would look something like :
1) Create a new empty stack st
2) Iterate over array `A`,
   where `i` goes from `0` to `size(A) - 1`.
    a) We are looking for value just smaller than `A[i]`. So keep popping from `st` till elements in `st.top() >= A[i]` or st becomes empty.
    b) If `st` is non empty, then the top element is our previous element. Else the previous element does not exist. 
    c) push `A[i]` onto st


Solution:
vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> out;
    stack<int> temp;
    if(A.size() == 0)
    {
        return out;
    }
    out.push_back(-1); //No nearest element for the 1st element
    temp.push(A[0]); //push all processed element to stack whether it's smaller or larger
    for(int i=1; i<A.size(); i++)
    {
        if(A[i] > temp.top()) //if curr elem is greater than top of stack element
        {
            out.push_back(temp.top()); //nearest element is on the top of stack, push it to output vector
            temp.push(A[i]); //again push the curr element to stack
        }
        else //if curr elem is less than the top of stack
        {
            while(!temp.empty() && temp.top() >= A[i]) //recursively pop from stack unless its empty or an element smaller than the current element is found
            {
                temp.pop();
            }
            if(temp.empty()) //if no smaller element was found, push -1 to output vector
            {
                out.push_back(-1);
                temp.push(A[i]);
            }
            else //else push the smaller element on the output vector
            {
                out.push_back(temp.top());
                temp.push(A[i]);
            }
            
        }
    }
    
    return out;
}
