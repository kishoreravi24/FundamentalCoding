#include <iostream>
#include <string>

void generateSubsequences(const std::string& str, int index, std::string& currentSubsequence) {
    // Base case: If we have processed all characters of the string, print the current subsequence.
    if (index == str.length()) {
        std::cout << currentSubsequence << std::endl;
        return;
    }

    // Recursive case 1: Include the current character in the subsequence.
    currentSubsequence.push_back(str[index]);
    generateSubsequences(str, index + 1, currentSubsequence);

    // Recursive case 2: Exclude the current character from the subsequence.
    currentSubsequence.pop_back();
    generateSubsequences(str, index + 1, currentSubsequence);

    // Recursive case 3: Skip the current character and move to the next character.
    generateSubsequences(str, index + 1, currentSubsequence);
}

int main() {
    std::string str = "abc";
    std::string currentSubsequence; // To store the current subsequence
    generateSubsequences(str, 0, currentSubsequence);
    return 0;
}
