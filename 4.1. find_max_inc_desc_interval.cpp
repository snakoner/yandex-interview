#include <iostream>
#include <vector>
#include <unordered_map>


template <typename F, typename S>
std::ostream& operator<<(std::ostream& os, const std::pair<F,S>& p) {
    os << "(" << p.first << ", " << p.second << ")";

    return os;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    bool first = true;
    os << "[";

    for (size_t i = 0; i < v.size(); i++) {
        if (first) {
            first = false;
            os << v[i];
            continue;
        }
        os << ", " << v[i];
    }

    os << "]";

    return os;
}

//  0 1 2 3 4 5 6
// {1,1,2,3,4,4,3} -> {1,4}

void updateMaxInterval(std::pair<int,int>& max, const std::pair<int,int> ind) {
    if (max.second - max.first < ind.second - ind.first) {
        max.first = ind.first;
        max.second = ind.second;
    }
}

std::pair<int,int> maxDistance(const std::vector<int>& v) {
    std::pair<int,int> ind = {0,0};
    std::pair<int,int> max_ind = {0,0};
    bool up = false, down = false;

    if (v.size() <= 1)
        return max_ind;
    
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i - 1] == v[i]) {
            up = down = false;
            ind = {i,i};
        } else if (v[i - 1] < v[i]) {
            up = true;

            if (down) {
                down = false;
                ind = {i-1, i-1};            
            }

            ind.second++;
        } else {
            down = true;

            if (up) {
                up = false;
                ind = {i-1, i-1};            
            }

            ind.second++;
        }
    
        updateMaxInterval(max_ind, ind);            
    }

    return max_ind;
}

int main() {
    std::vector<int> v = {1,2,3,2,1,1,2};
    auto result = maxDistance(v);

    std::cout << result << std::endl;
}
