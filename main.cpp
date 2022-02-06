#include <iostream>
#include <vector>
#include <numeric>
//#include <string>
//#include <map>
//#include <algorithm>
//#include <stdexcept>
#include <functional>

std::vector <int> inputVector();
int find_even_index(const std::vector <int>& numbers);

int main()
{
    std::vector <int> numbers = { 1,2,3,4,3,2,1 };//inputVector();
    int EvenIndex = find_even_index(numbers);
    std::cout << EvenIndex << std::endl;
    return 0;
}

std::vector <int> inputVector() {
    std::vector <int> vec;
    std::cout << "Input array of integers (press enter after finished work): " << std::endl;
    int i = 0;
    do {
        std::cin >>i;
        vec.push_back(i);
    } while (!std::cin.get());
    return vec;
};

int find_even_index(const std::vector<int>& numbers) {
    std::vector<int> sum_left, sum_right; sum_left.resize(numbers.size()); sum_right.resize(numbers.size()); 
    sum_left[0] = numbers[0];  sum_right[numbers.size()-1] = numbers[numbers.size() - 1];
    for (int i = 1; i < numbers.size(); i++) {
        sum_left[i] = sum_left[i - 1] + numbers[i];
    }
    for (int i = numbers.size()-2; i >= 0; i--) {
        sum_right[i] = sum_right[i + 1] + numbers[i];
    }
    for (int i = 0; i < numbers.size(); i++) {
        if (sum_left[i] == sum_right[i])
            return i;
    }
    return -1;
}