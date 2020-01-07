#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n);
  std::vector<int> cnt(n, 0);
  for (int i = 0; i < n; ++i) {
    std::cin >> v[i];
    cnt[v[i] - 1]++;
  }
  int mn = 0;
  for (int i = 0; i < n; ++i) {
    if (cnt[i]) {
      mn += 1;
      i += 2;
    }
  }
  int mx = 0;
  std::vector<int> ocp(n, 0);
  for (int i = 0; i < n; ++i) {
    if (cnt[i] == 1) {
      if (i == 0) {
        mx += 1;
      } else if (ocp[i - 1] == 0) {
        ocp[i - 1] = 1;
      } else if (ocp[i] == 0) {
        ocp[i] = 1;
      } else {
        if (i < n  - 1) ocp[i + 1] = 1;
        else mx += 1;
      }
    } else if (cnt[i] == 2) {
      if (i == 0) {
        mx += 1;
        ocp[0] = 1;
      } else if (ocp[i - 1] == 0) {
        ocp[i - 1] = 1;
        if (ocp[i] == 0) ocp[i] = 1;
        else if (i < n - 1) ocp[i + 1] = 1;
        else mx += 1;
      } else {
        ocp[i] = 1;
        if (i < n - 1) ocp[i + 1] = 1;
        else mx += 1;
      }
    } else if (cnt[i] > 2) {
      if (i == 0) {
        mx += 1;
        ocp[i] = 1;
        ocp[i + 1] = 1;
      } else {
        ocp[i - 1] = 1;
        ocp[i] = 1;
        if (i < n - 1) ocp[i + 1] = 1;
        else mx += 1;
      }
    }
  }
  for (int &d : ocp) {
    if (d > 0) mx ++;
  }
  std::cout << mn << ' ' << mx << std::endl;
  return 0;
}
