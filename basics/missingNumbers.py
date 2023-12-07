class Solution:
    def missingNumbers(self,array,n):
        #Method 1:
        for i in range(1,n+1):
            if i not in array:
                print(i)
                break
        
        #Method 2:
        total_sum = (n*(n+1))//2
        array_sum = sum(array)
        print(total_sum-array_sum)
        return

obj = Solution()
array = [num for num in range(1,11) if num!=8]
print(array)
obj.missingNumbers(array,10)

