#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// [자릿수][자릿수의 숫자][비트 마스킹]
int dp[100][10][1024] = {};

void saveCurrentDp(int current_digit, int current_number) {
  int prev_down = current_number - 1;
  int prev_up = current_number + 1;

  int binary_current_num = 0b0000000001 << current_number;

  if (prev_up < 10) {
    for (int i = 0; i < 1024; i++) {
      if (dp[current_digit - 1][prev_up][i] > 0) {
        long long temp =
            (long long)
                dp[current_digit][current_number][i | binary_current_num] +
            (long long)dp[current_digit - 1][prev_up][i];
        temp %= 1'000'000'000;

        dp[current_digit][current_number][i | binary_current_num] = temp;
      }
    }
  }

  if (prev_down >= 0) {
    for (int i = 0; i < 1024; i++) {
      if (dp[current_digit - 1][prev_down][i] > 0) {
        long long temp =
            (long long)
                dp[current_digit][current_number][i | binary_current_num] +
            (long long)dp[current_digit - 1][prev_down][i];
        temp %= 1'000'000'000;

        dp[current_digit][current_number][i | binary_current_num] = temp;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  // set dp of first number
  for (int i = 1; i < 10; i++) {
    int zero = 0b0000000001;
    dp[0][i][zero << i] = 1;
  }

  for (int current_digit = 1; current_digit < n; current_digit++) {
    for (int current_number = 0; current_number < 10; current_number++) {
      saveCurrentDp(current_digit, current_number);
    }
  }

  long long ans = 0;

  for (int i = 0; i < 10; i++) {
    ans += (long long)dp[n - 1][i][1023];
    ans %= 1'000'000'000;
  }

  cout << ans << endl;
}
