# https://www.geeksforgeeks.org/problems/closest-strings0611/1?page=1&sortBy=submissions
class Soltuion:
    def shortestDistance(self,s,word1,word2):
        res = float('inf')
        word1_index = -1
        word2_index = -1
        for i,word in enumerate(s):
            if word==word1:
                word1_index = i
            elif word==word2:
                word2_index = i
            if word1_index!=-1 and word2_index!=-1:
                res = min(res,abs(word1_index,word2_index))
        return res if res!=float('inf') else 0

