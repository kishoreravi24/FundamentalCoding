class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3),1)==0;
    }
};
/*
Logarithmic Properties: The code is essentially checking if the result of log10(n) / log10(3) is an integer (i.e., the remainder when divided by 1 is 0). This is based on the properties of logarithms:

If n is a power of 3, then log10(n) should be an integer multiple of log10(3). This is true because the logarithm of a number to a specific base represents the exponent to which the base must be raised to obtain the number.
Base-10 Logarithm: The code uses log10 because it's working with base-10 logarithms, which are more common in practical applications, especially when dealing with numbers in everyday contexts.

Modulus Operation (fmod): The fmod function is used to check if the result of the division is an integer (i.e., the remainder is 0). If the result is 0, it means that the logarithms are integer multiples of each other, and n is a power of 3.
*/