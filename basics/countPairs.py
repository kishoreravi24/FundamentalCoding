class Soltuion:
    def countPairs(self,arr,n,k):
        count = 0
        freq = {}
        for item in arr:
            target = k-item
            if target in freq:
                count+=freq[target]

            if item in freq:
                freq[item]+=1
            else:
                freq[item]=1

        return count

