#include <iostream>
#include <string>
#include <map>
#include <algorithm>

int main() {
  int q;
  std::cin >> q;
  getchar();
  while (q --) {
    std::string s;
    std::map<char, int> mp;
    std::getline(std::cin, s);
    for (auto &c : s) {
      mp[c] ++;
    }
    s = "";
    int r1 = std::min(mp['U'], mp['D']);
    int r2 = std::min(mp['L'], mp['R']);
    if (r1 == 0 && r2 != 0) r2 = 1;
    if (r2 == 0 && r1 != 0) r1 = 1;
    s += std::string(r1, 'U');
    s += std::string(r2, 'L');
    s += std::string(r1, 'D');
    s += std::string(r2, 'R');
    std::cout << 2 * r1 + 2 * r2 << std::endl;
    std::cout << s << std::endl;
  }
  return 0;
}
