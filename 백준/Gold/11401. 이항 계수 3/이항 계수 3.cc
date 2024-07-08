#include <algorithm>
#include <iostream>

using namespace std;

long long P = 1'000'000'007;

long long factorial(int n) {
  long long val = 1;

  for (int i = 2; i <= n; i++) {
    val = val * i % P;
  }
  return val;
}

long long power(int n, int e) {
  if (e == 0) {
    return 1;
  }
  if (e == 1) {
    return n;
  }

  long long val = power(n, e / 2);
  if (e % 2 == 0) {
    return val * val % P;
  }
  return val * val % P * n % P;
}

int main() {
  long long n, k;
  cin >> n >> k;

  long long val1 = power(factorial(n - k) * factorial(k) % P, P - 2);
  long long val2 = factorial(n) % P;

  cout << val1 * val2 % P << endl;
}