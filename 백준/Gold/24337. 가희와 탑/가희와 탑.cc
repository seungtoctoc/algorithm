#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> ans;
  int n, a, b;
  cin >> n >> a >> b;

  for (int i = 1; i < a; i++) {
    ans.push_back(i);
  }

  ans.push_back(max(a, b));

  for (int i = b - 1; i > 0; i--) {
    ans.push_back(i);
  }

  if (ans.size() > n) {
    cout << -1 << endl;
  } else {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << " ";

      if (i == 0) {
        for (int j = 0; j < n - (a + b - 1); j++) {
          cout << "1 ";
        }
      }
    }
  }
}