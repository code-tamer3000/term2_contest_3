#include <iostream>
#include <vector>

std::vector<size_t> get_pi() {
   std::vector<size_t> ans;
   size_t tmp = 0;
   while (std::cin >> tmp) {
       ans.push_back(tmp);
   }
   return ans;
}

std::string find_the_string(const std::vector<size_t>& pi) {
    std::string ans = "a";
    for (size_t i = 1; i < pi.size(); i++) {
        if (pi[i] != 0) ans.push_back(ans[pi[i] - 1]);
        else { 
            size_t ind = pi[i - 1];
            std::vector<bool> alfabet(26);
            while (ind > 0) {
                alfabet[ans[ind] - 'a'] = true;
                ind = pi[ind - 1];
            }
            char next = 'b';
            while (alfabet[next - 'a']) next++;
            ans.push_back(next);
        }
    }
    return ans;
}

int  main() {
    std::cout << find_the_string(get_pi()) << '\n';
    return 0;
}
