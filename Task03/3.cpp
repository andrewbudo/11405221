#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> lengths(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> lengths[i];
    }

    // Находим медиану
    std::sort(lengths.begin(), lengths.end());
    int median = lengths[n/2];

    // Считаем общую стоимость
    long long totalCost = 0;
    for (int i = 0; i < n; ++i) {
        totalCost += std::abs(lengths[i] - median);
    }

    std::cout << totalCost << std::endl;

    return 0;
}
