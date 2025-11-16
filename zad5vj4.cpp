#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void reverse_strings(std::vector<std::string>& words) {
    for (auto& w : words) {
        std::reverse(w.begin(), w.end());
    }
}

int main() {
    std::vector<std::string> v = { "hello", "world", "c++" };

    std::cout << "Prije: ";
    for (auto& s : v) std::cout << s << " ";

    reverse_strings(v);

    std::cout << "\nPoslije: ";
    for (auto& s : v) std::cout << s << " ";

    return 0;
}
