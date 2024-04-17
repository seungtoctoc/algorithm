#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> values;

  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;

    values.push_back(value);
  }

  sort(values.begin(), values.end());
  long long ans = 3'000'000'001;
  int ans_index[3] = {};

  for (int center = 1; center < values.size() - 1; center++) {
    int left = 0;
    int right = values.size() - 1;

    while (left < center && center < right) {
      long long sum = (long long)values[left] + (long long)values[center] +
                      (long long)values[right];

      if (abs(sum) < ans) {
        ans = abs(sum);
        ans_index[0] = left;
        ans_index[1] = center;
        ans_index[2] = right;
      }

      if (sum == 0) {
        break;
      }

      if (sum > 0) {
        right--;
        continue;
      }

      left++;
    }
  }

  for (int i = 0; i < 3; i++) {
    cout << values[ans_index[i]] << " ";
  }
}