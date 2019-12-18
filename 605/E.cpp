#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 0x3f3f3f3f

int n;
std::vector<int> even;
std::vector<int> odd;
std::vector<std::vector<int>> g;
std::vector<int> ans;

void go(std::vector<int> &st, std::vector<int> &ed) {
  std::vector<int> d(n, INF);
  std::queue<int> q;
  for (auto e : st) {
    d[e] = 0;
    q.push(e);
  }
  while (!q.empty()) {
    int e = q.front();
    q.pop();
    for (auto to : g[e]) {
      if (d[to] == INF) {
        d[to] = d[e] + 1;
        q.push(to);
      }
    }
  }
  for (auto e : ed) {
    if (d[e] != INF) ans[e] = d[e];
  }
}

int main() {
  std::cin >> n;
  std::vector<int> v(n);
  g = std::vector<std::vector<int>>(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
    if (v[i] & 1) odd.emplace_back(i);
    else even.emplace_back(i);
  }
  for (int i = 0; i < n; ++i) {
    int l = i - v[i];
    int r = i + v[i];
    if (l >= 0)  g[l].emplace_back(i);
    if (r < n) g[r].emplace_back(i);
  }
  ans = std::vector<int>(n, -1);
  go(odd, even);
  go(even, odd);
  for (auto d : ans) std::cout << d << ' ';
  std::cout << std::endl;
  return 0;
}
