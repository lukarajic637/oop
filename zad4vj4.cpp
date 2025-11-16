#include <iostream>
#include <string>


std::string word_to_pig_latin(const std::string& word) {
    if (word.empty()) return word;

    std::string vowels = "aeiouAEIOU";

    if (vowels.find(word[0]) != std::string::npos) {
        return word + "hay";
    }
    return word.substr(1) + word[0] + "ay";
}

int main() {
    std::string w1 = "apple";
    std::string w2 = "hello";
    std::string w3 = "string";

    std::cout << w1 << " -> " << word_to_pig_latin(w1) << "\n";
    std::cout << w2 << " -> " << word_to_pig_latin(w2) << "\n";
    std::cout << w3 << " -> " << word_to_pig_latin(w3) << "\n";

    return 0;
}
