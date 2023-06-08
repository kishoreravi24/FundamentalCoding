void frequencyCount(std::vector<int>& arr, int N, int P)
{
    std::vector<int> vect;
    vect.resize(P, 0);  // Resize vect to size P and initialize new elements with 0

    for (int i = 0; i < N; i++) {
        if (arr[i] <= P) {
            vect[arr[i] - 1]++;
        }
    }

    for(auto x: vect){
        std::cout<<x<<" ";
    }
}

//main concept in vector
/*
To clarify, when encountering a repeated element, 
the correct logic to update the count in the frequency vector should be frequency[arr[i] - 1]++. 
This will increment the count at the corresponding index in the vector, 
effectively updating the value instead of adding.
*/