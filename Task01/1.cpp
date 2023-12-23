#include <iostream>
#include <vector>

int findMissingNumber(int n, const std::vector<int>& numbers) {
    int x1 = 1;
    for (int i = 2; i <= n; ++i) {
        x1 ^= i;
    }

    int x2 = numbers[0];
    for (size_t i = 1; i < numbers.size(); ++i) {
        x2 ^= numbers[i];
    }

    return x1 ^ x2;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> numbers(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> numbers[i];
    }

    int missingNumber = findMissingNumber(n, numbers);
    std::cout << missingNumber << std::endl;

    return 0;
}
