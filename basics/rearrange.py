class Solution:
    def rearrange(self,arr, n):
        # code here
        positive_list = [x for x in arr if x>=0]
        negative_list = [x for x in arr if x<0]
        
        res = []
        min_len = min(len(positive_list),len(negative_list))
        for i in range(min_len):
            res.append(positive_list[i])
            res.append(negative_list[i])
        
        if len(positive_list) > len(negative_list):
            res.extend(positive_list[min_len::])
        else:
            res.extend(negative_list[min_len::])
        
        return res

solution_instance = Solution()

input_array = [9, 4, -2, -1, 5, 0, -5, -3, 2]
array_size = len(input_array)

result = solution_instance.rearrange(input_array, array_size)
print(result)

