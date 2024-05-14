#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n, k;
int dp[100'001] = {};
int ans = 0;

void load(int w, int v) {
  for (int i = k; i >= 0; i--) {
    if (dp[i] > -1 && i + w <= k && dp[i] + v > dp[i + w]) {
      dp[i + w] = dp[i] + v;
      ans = max(ans, dp[i + w]);
    }
  }
}

int main() {
  cin >> n >> k;
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    int w, v;
    cin >> w >> v;

    load(w, v);
  }

  cout << ans << endl;
}