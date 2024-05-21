#include <iostream>
#include <sstream>
#include <unordered_map>

// Task1. Convert string like this: AAAABBBCCXYZ -> A4B3C2XYZ
std::string compressString(const std::string& s) {
    if (s.size() <= 1) 
        return s;

    std::stringstream ss;
    int counter = 1;
    char prev = s[0];

    for (size_t i = 1; i < s.size(); i++) {
        if (s[i] == prev) {
            counter++;
        } else {
            ss << prev;
            prev = s[i];

            if (counter > 1) {
                ss << counter;
                counter = 1;
            }
        }
    }

    ss << s[s.size() - 1];
    if (counter > 1)
        ss << counter;

    return ss.str();
}

int main() {
    std::unordered_map<std::string, std::string> cases = {
        {"AAAABBBCCXYZZ", "A4B3C2XYZ2"},
    };

    for (auto it = std::begin(cases); it != std::end(cases); it = std::next(it)) {
        std::string result = compressString(it->first);
        if (result != it->second) {
            std::cout << result << " != " << it->second << std::endl;
        }
    }
}
