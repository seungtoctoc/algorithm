#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct App {
  int volume;
  int cost;
};

int main() {
  int n, m;
  int ans = 10'000;

  vector<App> apps;
  int dp[101][10'001] = {};
  memset(dp, 0, sizeof(dp));

  cin >> n >> m;

  apps.push_back({0, 0});

  for (int i = 1; i <= n; i++) {
    int current_volume;
    cin >> current_volume;

    App current_app = {current_volume, 0};
    apps.push_back(current_app);
  }

  for (int i = 1; i <= n; i++) {
    int current_cost;
    cin >> current_cost;

    apps[i].cost = current_cost;
  }

  for (int i = 1; i <= n; i++) {
    App current_app = apps[i];
    int cost = -1;

    while (++cost <= 10'000) {
      if (cost < current_app.cost) {
        dp[i][cost] = dp[i - 1][cost];
        continue;
      }

      dp[i][cost] = max(dp[i - 1][cost], dp[i - 1][cost - current_app.cost] +
                                             current_app.volume);
    }
  }

  for (int i = 0; i <= 10'000; i++) {
    if (dp[n][i] >= m) {
      cout << i << endl;
      break;
    }
  }
}