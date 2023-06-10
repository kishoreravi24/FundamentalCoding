//without duplication logic
vector<vector<int> > fourSum(vector<int> &arr, int k) {
    // Your code goes here
    std::vector<std::pair<int,int>> vect;
    std::sort(arr.begin(),arr.end());
    for(int i=0;i<n-(n-1);i++){
        fof(int j=n-1;j>n-2;j--){
            int first=arr[i];
            int last=arr[j];
            int left*=arr[i+1];
            int right*=arr[j-1];
            while(left<right){
                if(first+left+right+last==k){
                    vect.push_back({first,left,right,last});
                }
                if(first+left+right+last<k){
                    left++;
                }else{
                    right--;
                }
            }
        }
    }
    return vect;
}

//with duplication logic

std::vector<std::vector<int>> fourSum(std::vector<int>& arr, int k) {
std::vector<std::vector<int>> result;
int n = arr.size();
std::sort(arr.begin(), arr.end());

for (int i = 0; i < n - 3; i++) {
    if (i > 0 && arr[i] == arr[i - 1])
        continue;

    for (int j = i + 1; j < n - 2; j++) {
        if (j > i + 1 && arr[j] == arr[j - 1])
            continue;

        int left = j + 1;
        int right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[j] + arr[left] + arr[right];

            if (sum == k) {
                result.push_back({arr[i], arr[j], arr[left], arr[right]});
                left++;
                right--;
            } else if (sum < k) {
                left++;
            } else {
                right--;
            }
        }
    }
}

return result;
}