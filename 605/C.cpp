#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

int main() {
  int n, k;
  std::cin >> n >> k;
  std::string s;
  std::vector<int> v(26, 0);
  std::cin >> s;
  for (int i = 0; i < k; ++i) {
    char c;
    std::cin >> c;
    v[c - 'a'] = 1;
  }
  for (auto &c : s) {
    if (v[c - 'a'] == 0) c = ' ';
  }
  std::istringstream is(s);
  long long ans = 0;
  while (is >> s) {
    ans += (long long)s.length() * (s.length() + 1) / 2;
  }
  std::cout << ans << std::endl;
  return 0;
}
