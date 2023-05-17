#include <iostream>
#include <utility>
#include <map>

int main()
{
    std::string row{ "Hello World!!" };
    std::map<char, int> arr;
    std::multimap<int, char, std::greater<int>> sort_arr;
    int num = 0;

    for (auto const& symbol : row) {
        
        if (arr.find(symbol) != arr.end()) {
            num = ++arr.at(symbol);
            arr[symbol] = num;
        }
        else {
            arr[symbol] = 1;
        }
    }
    
    for (auto const& symbol : arr) {
        sort_arr.insert(std::make_pair(symbol.second, symbol.first));
    }

    std::cout << "[IN]: " << row << std::endl;
    std::cout << "[OUT]: " << std::endl;
    for (auto const& num : sort_arr) {
        std::cout << num.second << ": " << num.first << std::endl;
    }
}