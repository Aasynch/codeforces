#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t --) {
    int n, k;
    std::cin >> n >> k;
    int half = k / 2;
    int ave = n / k;
    int remain = n - ave * k;
    if (remain <= half) std::cout << ave * k + remain << std::endl;
    else std::cout << ave * k + half << std::endl;
  }
  return 0;
}
