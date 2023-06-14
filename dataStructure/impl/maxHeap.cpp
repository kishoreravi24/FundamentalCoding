#include<bits/stdc++.h>
int main(){
    std::priority_queue<int,std::vector<int>> heap;
    
    // Inserting elements into the min heap
    heap.push(5);
    heap.push(2);
    heap.push(8);
    heap.push(1);
    heap.push(10);
    
    int maxVal = heap.top();
    std::cout<<maxVal<<" ";
    
    heap.pop();
    
    int val = heap.top();
    std::cout<<val<<" ";
    
    return 0;
}