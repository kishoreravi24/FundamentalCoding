from typing import List

class Solution:
    # Function to find the leaders in the array.
    def leaders(self, A, N):
        res = [A[-1]] #Save current leader 
        for i in range(N-2,-1,-1):
            if A[i] >= res[-1]:
                res.append(A[i])
        print(res)
        print(res[::-1])
        return res[::-1]

