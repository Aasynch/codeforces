#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define INF 0x3f3f3f3f

const int N = 201;

int dp[N][N][N * 2];
std::pair<std::pair<int, int>, std::pair<int, char>> p[N][N][N * 2];

int main() {
  std::string s, t;
  std::cin >> s >> t;
  memset(dp, INF, sizeof(dp));
  dp[0][0][0] = 0;
  for (int i = 0; i <= s.length(); ++i) {
    for (int j = 0; j <= t.length(); ++j) {
      for (int k = 0; k < N * 2; ++k) {
        if (dp[i][j][k] == INF) continue;
        int nxi = i + (i < s.length() && s[i] == '(');
        int nxj = j + (j < t.length() && t[j] == '(');
        if (k + 1 < 2 * N && dp[nxi][nxj][k + 1] > dp[i][j][k] + 1) {
          dp[nxi][nxj][k + 1] = dp[i][j][k] + 1;
          p[nxi][nxj][k + 1] = {{i, j}, {k, '('}};
        }
        nxi = i + (i < s.length() && s[i] == ')');
        nxj = j + (j < t.length() && t[j] == ')');
        if (k > 0 && dp[nxi][nxj][k - 1] > dp[i][j][k] + 1) {
          dp[nxi][nxj][k - 1] = dp[i][j][k] + 1;
          p[nxi][nxj][k - 1] = {{i, j}, {k, ')'}};
        }
      }
    }
  }
  int ans = INF;
  int remain = 0;
  for (int i = 0; i < N * 2; ++i) {
    if (ans > dp[s.length()][t.length()][i] + i) {
      ans = dp[s.length()][t.length()][i] + i;
      remain = i;
    }
  }
  std::string res = std::string(remain, ')');
  int pi = s.length(), pj = t.length(), pk = remain;
  while (pi > 0 || pj > 0 || pk != 0) {
    int i = pi, j = pj, k = pk;
    res += p[pi][pj][pk].second.second;
    pi = p[i][j][k].first.first;
    pj = p[i][j][k].first.second;
    pk = p[i][j][k].second.first;
  }
  std::reverse(res.begin(), res.end());
  std::cout << res << std::endl;
  return 0;
}
