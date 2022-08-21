#include <bits/stdc++.h>
using namespace std;
int num_t[5][31][901];
int num_n[5][31][901];
//五个方向，分别对应着上右下左
int pre_t[31][31], pre_n[31][31];
char mp[40][40];
int n, m, c;
int ans;
int main() {
  scanf("%d%d%d", &m, &n, &c);
  for (int i = 1; i <= 4; i++)
    for (int j = 0; j <= 30; j++)
      for (int k = 0; k <= 900; k++) num_t[i][j][k] = num_n[i][j][k] = -1000000000;
  for (int i = 1; i <= m; i++) scanf("%s", mp[i] + 1);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      pre_t[i][j] = pre_t[i - 1][j] + pre_t[i][j - 1] - pre_t[i - 1][j - 1];
      pre_n[i][j] = pre_n[i - 1][j] + pre_n[i][j - 1] - pre_n[i - 1][j - 1];
      if (mp[i][j] == 'T')
        pre_t[i][j]++;
      else if (mp[i][j] == 'N')
        pre_n[i][j]++;
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = i; k <= m; k++) {
        for (int l = j; l <= n; l++) {
          int tmp_t = pre_t[k][l] - pre_t[i - 1][l] - pre_t[k][j - 1] + pre_t[i - 1][j - 1];
          int tmp_n = pre_n[k][l] - pre_n[i - 1][l] - pre_n[k][j - 1] + pre_n[i - 1][j - 1];
          // cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<tmp_t<<" "<<tmp_n<<"\n";
          if (tmp_t >= tmp_n) {
            int tmp = tmp_t - tmp_n;
            int sum = tmp_t + tmp_n;
            num_t[1][k][tmp] = max(num_t[1][k][tmp], sum);
            num_t[2][i][tmp] = max(num_t[2][i][tmp], sum);
            num_t[3][l][tmp] = max(num_t[3][l][tmp], sum);
            num_t[4][j][tmp] = max(num_t[4][j][tmp], sum);
          } else {
            int tmp = tmp_n - tmp_t;
            int sum = tmp_t + tmp_n;
            num_n[1][k][tmp] = max(num_n[1][k][tmp], sum);
            num_n[2][i][tmp] = max(num_n[2][i][tmp], sum);
            num_n[3][l][tmp] = max(num_n[3][l][tmp], sum);
            num_n[4][j][tmp] = max(num_n[4][j][tmp], sum);
          }
        }
      }
    }
  }
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= 30; j++)
      for (int k = 1; k <= 900; k++) {
        num_t[i][j][k] = max(num_t[i][j][k], num_t[i][j][k - 1]);
        num_n[i][j][k] = max(num_n[i][j][k], num_n[i][j][k - 1]);
      }

  for (int i = 1; i <= 30; i++) {
    for (int k = 1; k <= 900; k++) {
      num_t[1][i][k] = max(num_t[1][i][k], num_t[1][i - 1][k]);
      num_n[1][i][k] = max(num_n[1][i][k], num_n[1][i - 1][k]);
    }
  }

  for (int i = 1; i <= 30; i++) {
    for (int k = 1; k <= 900; k++) {
      num_t[3][i][k] = max(num_t[3][i][k], num_t[3][i - 1][k]);
      num_n[3][i][k] = max(num_n[3][i][k], num_n[3][i - 1][k]);
    }
  }

  for (int i = 30; i >= 1; i--) {
    for (int k = 1; k <= 900; k++) {
      num_t[2][i][k] = max(num_t[2][i][k], num_t[2][i + 1][k]);
      num_n[2][i][k] = max(num_n[2][i][k], num_n[2][i + 1][k]);
    }
  }

  for (int i = 30; i >= 1; i--) {
    for (int k = 1; k <= 900; k++) {
      num_t[4][i][k] = max(num_t[4][i][k], num_t[4][i + 1][k]);
      num_n[4][i][k] = max(num_n[4][i][k], num_n[4][i + 1][k]);
    }
  }

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = i; k <= m; k++) {
        for (int l = j; l <= n; l++) {
          int tmp_t = pre_t[k][l] - pre_t[i - 1][l] - pre_t[k][j - 1] + pre_t[i - 1][j - 1];
          int tmp_n = pre_n[k][l] - pre_n[i - 1][l] - pre_n[k][j - 1] + pre_n[i - 1][j - 1];
          if (tmp_t >= tmp_n) {
            int tmp = tmp_t - tmp_n;
            int sum = tmp_t + tmp_n;
            if (c >= tmp) {
              ans = max(ans, sum + num_t[1][i - 1][c - tmp]);
              ans = max(ans, sum + num_t[3][j - 1][c - tmp]);
              ans = max(ans, sum + num_t[2][k + 1][c - tmp]);
              ans = max(ans, sum + num_t[4][l + 1][c - tmp]);
            }
            if (tmp <= c) {
              ans = max(ans, sum + num_n[1][i - 1][min(900, c + tmp)]);
              ans = max(ans, sum + num_n[3][j - 1][min(900, c + tmp)]);
              ans = max(ans, sum + num_n[2][k + 1][min(900, c + tmp)]);
              ans = max(ans, sum + num_n[4][l + 1][min(900, c + tmp)]);
            }
          } else {
            int tmp = tmp_n - tmp_t;
            int sum = tmp_t + tmp_n;
            if (c >= tmp) {
              ans = max(ans, sum + num_n[1][i - 1][c - tmp]);
              ans = max(ans, sum + num_n[3][j - 1][c - tmp]);
              ans = max(ans, sum + num_n[2][k + 1][c - tmp]);
              ans = max(ans, sum + num_n[4][l + 1][c - tmp]);
            }
            if (tmp <= c) {
              ans = max(ans, sum + num_t[1][i - 1][min(900, c + tmp)]);
              ans = max(ans, sum + num_t[3][j - 1][min(900, c + tmp)]);
              ans = max(ans, sum + num_t[2][k + 1][min(900, c + tmp)]);
              ans = max(ans, sum + num_t[4][l + 1][min(900, c + tmp)]);
            }
          }
        }
      }
    }
  }
  auto x = random_device();
  printf("%d\n", ans);
}
