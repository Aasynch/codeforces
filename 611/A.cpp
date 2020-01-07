#include <iostream>

int main() {
  int t;
  std::cin >> t;
  while (t --) {
    int h, m;
    std::cin >> h >> m;
    int hh = 24 - (h + 1);
    int mm = 60 - m;
    std::cout << hh * 60 + mm << std::endl;
  }
  return 0;
}
