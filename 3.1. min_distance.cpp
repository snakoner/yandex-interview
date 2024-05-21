#include <iostream>

int minDistance(const std::string& path) {
    size_t min_dist = path.size();
    size_t start_index = 0;
    bool has_hit = false;
    char last_char;

    while (path[start_index] == 'O')
        start_index++;

    last_char = path[start_index];

    for (size_t i = start_index + 1; i < path.size(); i++) {
        if (path[i] != 'O' && path[i] != last_char) {
            last_char = path[i];
            min_dist = std::min(min_dist, i - start_index);
            start_index = i;
            has_hit = true;
        } else if (path[i] == last_char) {
            start_index = i;
        }
    }

    return (has_hit) ? min_dist : 0;
}

int main() {
    std::cout << minDistance("OOOXXXOXOOYOY") << std::endl;
}
