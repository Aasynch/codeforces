#include <iostream>
#include <algorithm>

typedef long long LL;

int main() {
  int q;
  std::cin >> q;
  while (q --) {
    LL a, b, c;
    std::cin >> a >> b >> c;
    LL ans = 9999999999;
    for (int i = -1; i <= 1; ++i) {
      for (int j = -1; j <= 1; ++j) {
        for (int k = -1; k <= 1; ++k) {
          int a1 = a + i;
          int b1 = b + j;
          int c1 = c + k;
          ans = std::min(ans, (LL)std::abs(a1 - b1) + std::abs(a1 - c1) + std::abs(b1 - c1));
        }
      }
    }
    std::cout << ans << std::endl;
  }
  return 0;
}
