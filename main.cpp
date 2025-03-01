#include<iostream>
#include<vector>

using namespace std;
long long MOD = 1e9 + 7;

  bool contains_apple(vector<string> pizza, int row, int col, int m, int n) {
    for (int i = row; i < m; i++) {
      for (int j = col; j < n; j++) {
        if (pizza[i][j] == 'A')
          return true;
      }
    }
    return false;
  }

  int dfs(vector<string> pizza, int row, int col, int k) {
    if (k == 0) {
      return 1;
    }
    int m = pizza.size();
    int n = pizza[0].length();

    int ans = 0;

    for (int i = row; i < m; i++) {
      for (int j = col; j < n; j++) {
        if (contains_apple(pizza, row, col, i, j) &&
            contains_apple(pizza, i, j, pizza.size(), pizza[0].length())) {
          ans += dfs(pizza, i, j, k - 1);
          ans %= MOD;
        }
      }
    }
    return ans;
  }

  int ways(vector<string> &pizza, int k) {
    if (k == 0)
      return 1;
    return dfs(pizza, 0, 0, k - 1);
  }
