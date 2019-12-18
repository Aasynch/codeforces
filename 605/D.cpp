#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  for (int i = 0; i < n; ++i) std::cin >> v[i];
  int ans = -1;
  std::vector<int> l(n, 1);
  for (int i = 1; i < n; ++i) {
    if (v[i] > v[i - 1]) l[i] = l[i - 1] + 1;
    ans = std::max(ans, l[i]);
  }
  std::vector<int> r(n, 1);
  for (int i = n - 2; i >= 0; --i) {
    if (v[i] < v[i + 1]) r[i] = r[i + 1] + 1;
  }
  for (int i = 1; i < n - 1; ++i) {
    if (v[i - 1] < v[i + 1]) ans = std::max(ans, l[i - 1] + r[i + 1]);
  }
  std::cout << ans << std::endl;
  return 0;
}
