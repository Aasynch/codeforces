#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> x(n);
  for (int i = 0; i < n; ++i) std::cin >> x[i];
  std::queue<std::pair<int, int>> q;
  std::map<int, int> mp;
  int cnt = 0;
  long long res = 0;
  std::vector<int> ans;
  for (int &d : x) {
    q.push({d, 1});
    q.push({d, -1});
    mp[d] = 1;
  }
  while (!q.empty()) {
    auto v = q.front();
    q.pop();
    if (mp[v.first + v.second] == 1) {
      continue;
    }
    mp[v.first + v.second] = 1;
    cnt ++;
    res += std::abs(v.second);
    ans.emplace_back(v.first + v.second);
    if (cnt == m) break;
    if (v.second > 0) q.push({v.first, v.second + 1});
    else q.push({v.first, v.second - 1});
  }
  std::cout << res << std::endl;
  for (int &d : ans) {
    std::cout << d << ' ';
  }
  std::cout << std::endl;
  return 0;
}
