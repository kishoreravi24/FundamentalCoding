#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> vector(6);
    for (int i = 1; i <= 6; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            vector.at(i - 1) = "FizzBuzz";
        }
        else if (i % 3 == 0)
        {
            vector.at(i - 1) = "Fizz";
        }
        else if (i % 5 == 0)
        {
            vector.at(i - 1) = "Buzz";
        }
        else
        {
            vector.at(i - 1) = std::to_string(i);
        }
    }

    for(std::string i:vector){
        std::cout<<i<<" ";
    }

    return 0;
}