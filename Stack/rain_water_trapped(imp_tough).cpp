https://www.interviewbit.com/problems/rain-water-trapped/
https://leetcode.com/problems/trapping-rain-water/solution/ (STAR)

Solution: DP ( O(n), O(n) )
int Solution::trap(const vector<int> &A) {
    int result = 0;
    int n = A.size();
    vector<int> left_max(n), right_max(n);

    if(n <= 2)
    {
        return 0;
    }

    left_max[0] = A[0];

    right_max[n-1] = A[n-1];

    for(int i=1; i<A.size(); i++)
    {
        left_max[i] = max(left_max[i-1], A[i]);
        right_max[n-(i+1)] = max(right_max[n-i], A[n-(i+1)]);
    }
    for(int i=0; i<n ; i++)
    {
        result +=  ( min(left_max[i], right_max[i]) - A[i] );
    }
    return result;
}

Solution: Two Pointers ( O(n), O(1) )

int Solution::trap(const vector<int> &A) {
    int result = 0;
    int n = A.size();
    int left_max = A[0], right_max = A[n-1];
    int left = 0, right = n-1;

    if(n <= 2)
    {
        return 0;
    }

    while(left < right)
    {
        if(A[left] < A[right])
        {
            if(A[left]>left_max)
            {
                left_max = A[left];
            }
            result += left_max - A[left];
            left++;
        }
        else //A[right] > A[left]
        {
            if(A[right]>right_max)
            {
                right_max = A[right];
            }
            result += right_max - A[right];    
            right --;
        }
    }

    return result;
}
