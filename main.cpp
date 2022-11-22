#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include "sys/types.h"

long double size_char = 0x0;
std::vector<std::pair<size_t, std::string>> vec;

auto compare(std::pair<size_t, std::string> const &a, std::pair<size_t, std::string> const &b) -> bool {
    return a.second < b.second;
}

auto push(char str[], size_t size) -> void {
    std::unordered_map<size_t, std::string> holder;
    std::string collector;

    for (size_t i = 0x0; i < size - 0x1; i++) {
        size_char += sizeof(str[i]) / 1048576.0;
        collector += str[i];
    }
    holder[size - 0x1] = collector;
    std::copy(holder.begin(), holder.end(), back_inserter(vec));
}

auto dump_strings() -> void {
    for (auto const &element : vec) {
        std::cout << "len:" << element.first << " | " << element.second << std::endl;
    }
}

auto pop() -> void {
    std::string replacement;
    for (size_t i = 0x0; i < vec[vec.size() - 0x1].second.size(); i++) replacement += "*";
    vec[vec.size() - 0x1].second = replacement;
}

auto sort() -> void {
    std::sort(vec.begin(), vec.end(), compare);

    for (auto const &element : vec) {
        std::cout << "len:" << element.first << " | " << element.second << std::endl;
    }
}

auto dump() -> void {
    for (auto const &element : vec) {
        std::cout << &element.second << std::endl;
    }
}

auto get_memory() -> size_t {
    std::string token;
    std::ifstream file("/proc/meminfo");

    while (file >> token) {
        if (token == "MemAvailable:") {
            size_t mem;
            if (file >> mem) return mem;
            else return 0x0;
        }
    }
    return 0x0;
}

auto status() -> void {
    std::cout << "You have total " << get_memory() * 0x3E8 << "MB memory available" << std::endl;
    long double percentage = (size_char * 0x64) / (get_memory() * 0x64);
    std::cout << std::fixed << std::setprecision(0x14) << percentage
              << "% of used capacity is computed for characters" << std::endl;
}

auto main() -> int {
    char test1[] = "trabzon";
    char test2[] = "denizli";
    char test3[] = "adana";
    char test4[] = "zonguldak";
    char test5[] = "bolu";

    push(test1, sizeof(test1)/sizeof(test1[0x0]));
    push(test2, sizeof(test2)/sizeof(test2[0x0]));
    push(test3, sizeof(test3)/sizeof(test3[0x0]));
    push(test4, sizeof(test4)/sizeof(test4[0x0]));
    push(test5, sizeof(test5)/sizeof(test5[0x0]));

    dump_strings();
    std::cout << std::endl;
    pop();
    std::cout << std::endl;
    dump_strings();
    std::cout << std::endl;
    sort();
    std::cout << std::endl;
    dump();
    std::cout << std::endl;
    status();
    std::cout << std::endl;

    return 0x0;
}
