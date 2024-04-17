#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int getAnswer(vector<int> buildings) {
  int center = 2;
  int ans = 0;

  while (center + 2 < buildings.size()) {
    int left_max = max(buildings[center - 1], buildings[center - 2]);
    int right_max = max(buildings[center + 1], buildings[center + 2]);

    if (buildings[center] > max(left_max, right_max)) {
      ans += buildings[center] - max(left_max, right_max);
    }

    center++;
  }

  return ans;
}

int main() {
  for (int i = 1; i <= 10; i++) {
    int n;
    cin >> n;
    vector<int> buildings;

    for (int j = 0; j < n; j++) {
      int height;
      cin >> height;

      buildings.push_back(height);
    }

    cout << "#" << i << " " << getAnswer(buildings) << endl;
  }
}
