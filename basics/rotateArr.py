class Solution:
    def rotateArr(self,arr,k):
        k=k%len(arr)
        arr.reverse()

        arr[:k]=reverse(arr[:k])
        arr[k:]=reverse(arr[k:])

