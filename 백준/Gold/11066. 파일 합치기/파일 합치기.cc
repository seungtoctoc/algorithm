#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

vector<int> pages;
int dp[501][501] = {};
int accumulate[501] = {};

void getInput() {
  pages.clear();
  pages.push_back(0);

  int k;
  cin >> k;

  for (int i = 1; i <= k; i++) {
    int page;
    cin >> page;
    pages.push_back(page);

    accumulate[i] = accumulate[i - 1] + pages[i];
  }
}

int getDpValue(int left, int right) {
  if (dp[left][right] > 0) {
    return dp[left][right];
  }

  if (left == right) {
    return dp[left][right] = 0;
  }

  if (right - 1 == left) {
    return dp[left][right] = pages[left] + pages[right];
  }

  int min_sum = 2'000'000'000;
  for (int i = left; i < right; i++) {
    int sum = getDpValue(left, i) + getDpValue(i + 1, right);

    min_sum = min(min_sum, sum);
  }

  return dp[left][right] = min_sum + accumulate[right] - accumulate[left - 1];
}

int getAnswer() {
  memset(dp, 0, sizeof(dp));
  return getDpValue(1, pages.size() - 1);
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    getInput();
    cout << getAnswer() << endl;
  }
}