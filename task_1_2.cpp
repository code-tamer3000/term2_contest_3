/*
Задача 1. Поиск подстроки (3 балла)

Найдите все вхождения шаблона в строку. Длина шаблона – p, длина строки ­– n. Время O(n + p), доп. память – O(p).
Вариант 1. С помощью префикс-функции;
Вариант 2. С помощью z-функции.

Формат ввода
Шаблон, символ перевода строки, строка.

Формат вывода
Позиции вхождения шаблона в строке.

*/

#include <iostream>
#include <vector>

std::vector<int> calculate_z_func(const std::string& s) {
    std::vector<int> z_func(s.size());
    int left = 0;
    int right = 0;
    for (int i = 1; i < s.size(); i++) {
        if (i <= right) {
            z_func[i] = std::min(right - i + 1, z_func[i - left]);
        }
        while (i + z_func[i] < s.size() && s[z_func[i]] == s[i + z_func[i]]) {
            z_func[i]++;
        }
        if (i + z_func[i] - 1 > right) {
            left = i;
            right = i + z_func[i] - 1;
        }
    }
    return z_func;
}
          
std::vector<int> find_all_occurances(const std::string& original, const std::string& pattern) {
    std::vector<int> ans;
    std::vector<int> z = calculate_z_func(pattern);
    int left = 0;
    int right = 0;
    for (int i = 0; i < original.size(); i++) {
        if (i + pattern.size() > original.size()) break;
        int z_value = 0;
        if (i <= right) {
            z_value = std::min(right - i + 1, z[i - left]);
        }
        while (z_value < pattern.size() && i + z_value < original.size() && pattern[z_value] == original[i + z_value]) {
            z_value++;
        }
        if (i + z_value - 1 > right) {
            left = i;
            right = i + z_value - 1;
        }
        if (z_value == pattern.size()) ans.push_back(i);
    }
    return ans;
}

int main() {
    std::string pattern;
    std::string s;
    std::cin >> pattern >> s;
    for (auto it : find_all_occurances(s, pattern)) {
        std::cout << it << '\n';
    }
    return 0;
}
