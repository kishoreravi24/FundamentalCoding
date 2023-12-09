class Solution:
    def commonPrefix(self,arr,n):
        if not arr:
            return "-1"
        arr.sort()
        min_len = min(len(arr[0]),len(arr[n-1]))
        prefix = ""
        for i in range(min_len):
            if arr[0][i] == arr[n-1][i]:
                prefix+=arr[0][i]
            else:
                break
        if len(prefix)==0:
            return "-1"
        else:
            return prefix

