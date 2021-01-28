#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// My estimated time of the big-Oh of this algorithm is O(log base 3 of n)

unsigned int ternary_search(const std::vector<int> &data, int l, int r, int value)
{
    if (r >= 1)
    {
        int first_third = l + (r - l) / 3;
        int second_third = r - (r - l) / 3;

        if (data[first_third] == value)
        {
            return first_third;
        }
        if (data[second_third] == value)
        {
            return second_third;
        }

        if (value < data[first_third])
        {
            return ternary_search(data, l, first_third - 1, value);
        }
        else if (value > data[second_third])
        {
            return ternary_search(data, second_third + 1, r, value);
        }
        else
        {
            return ternary_search(data, first_third + 1, second_third - 1, value);
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
    int num_tests = 100;
    srand(time(NULL));
    for (int i = 0; i < num_tests; i++)
    {
        std::vector<int> sorted;
        int size = rand() % 10000 + 1;
        for (int i = 0; i < size; i++)
        {
            int num = i - (size / 2);
            sorted.push_back(num);
        }

        int value = rand() % size - (size / 2);
        std::cout << "The size of the vector is " << sorted.size() << std::endl;
        std::cout << "The values start at " << sorted[0] << " and end at " << sorted[sorted.size() - 1] << std::endl;
        int l = 0;
        int r = (sorted.size() - 1);
        int ans = ternary_search(sorted, l, r, value);
        std::cout << "Index of " << value << " is: " << ans << "\n"
                  << std::endl;
    }
    return 0;
}