class Solution:
    def kadanesalgo(self,arr,n):
        curr_sum = arr[0]
        max_sum = arr[0]
        for i in range(1,n):
            curr_sum=max(arr[i],curr_sum+arr[i])
            max_sum=max(curr_sum,max_sum)
        return max_sum

