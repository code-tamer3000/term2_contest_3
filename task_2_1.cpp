#include <iostream>
#include <vector>

std::vector<size_t> get_pi() {
   std::vector<size_t> pi;
   size_t tmp = 0;
   while (std::cin >> tmp) {
       pi.push_back(tmp);
   }
   return pi;
}

std::string find_min_string_by_pi(const std::vector<size_t>& pi) {
    std::string ans = "a";
    for (size_t i = 1; i < pi.size(); i++) {
        if (pi[i] != 0) ans.push_back(ans[pi[i] - 1]);
        else { 
            size_t ind = pi[i - 1];
            std::vector<bool> alphabet(26);
            while (ind > 0) {
                alphabet[ans[ind] - 'a'] = true;
                ind = pi[ind - 1];
            }
            char next = 'b';
            while (alphabet[next - 'a']) next++;
            ans.push_back(next);
        }
    }
    return ans;
}

int main() {
    std::cout << find_min_string_by_pi(get_pi()) << '\n';
    return 0;
}
