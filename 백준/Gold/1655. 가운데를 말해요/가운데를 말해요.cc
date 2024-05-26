#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> top;
  priority_queue<int> bottom;

  for (int i = 0; i < n; i++) {
    int num;
    scanf("%d", &num);

    if (i == 0) {
      bottom.push(num);
    } else {
      if (bottom.top() < num) {
        top.push(num);

        if (top.size() > bottom.size()) {
          bottom.push(top.top());
          top.pop();
        }
      } else {
        bottom.push(num);

        if (bottom.size() - top.size() > 1) {
          top.push(bottom.top());
          bottom.pop();
        }
      }
    }

    printf("%d\n", bottom.top());
  }
}