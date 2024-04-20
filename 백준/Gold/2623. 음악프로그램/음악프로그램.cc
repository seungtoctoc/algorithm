#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<int> from[1'001];
vector<int> ans;
int front[1'001] = {};

void getAnswer() {
  queue<int> queue;

  for (int i = 1; i <= n; i++) {
    if (front[i] == 0) {
      queue.push(i);
    }
  }

  while (!queue.empty()) {
    int current = queue.front();
    queue.pop();
    ans.push_back(current);

    for (int i = 0; i < from[current].size(); i++) {
      int next = from[current][i];
      front[next]--;

      if (front[next] == 0) {
        queue.push(next);
      }
    }
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int num;
    cin >> num;

    int prev = -1;
    for (int j = 0; j < num; j++) {
      int current;
      cin >> current;

      if (prev > -1) {
        from[prev].push_back(current);
        front[current]++;
      }

      prev = current;
    }
  }

  getAnswer();

  if (ans.size() == n) {
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << endl;
    }
  } else {
    cout << 0 << endl;
  }
}