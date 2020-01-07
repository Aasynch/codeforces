#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> f(n);
  std::vector<bool> check(n, false);
  for (int i = 0; i < n; ++i) {
    std::cin >> f[i];
    if (f[i] != 0) check[f[i] - 1] = true;
  }
  std::vector<int> a;
  std::vector<int> b;
  for (int i = 0; i < n; ++i) {
    if (f[i] == 0) a.emplace_back(i);
    if (check[i] == false) b.emplace_back(i);
  }
  for (int i = 1; i < a.size(); ++i) {
    if (a[i] == b[i]) {
      int t = b[i];
      b[i] = b[i - 1];
      b[i - 1] = t;
    }
  }
  if (a[0] == b[0]) {
    int t = b[0];
    b[0] = b[b.size() - 1];
    b[b.size() - 1] = t;
  }
  for (int i = 0; i < a.size(); ++i) {
    f[a[i]] = b[i] + 1;
  }
  for (int &d : f) {
    std::cout << d << ' ';
  }
  std::cout << std::endl;
  return 0;
}
