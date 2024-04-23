#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Proc {
  int x;
  int y;
};

vector<Proc> procs;
int calc[501][501] = {};

int getMin(int start, int end) {
  if (calc[start][end] != -1) {
    return calc[start][end];
  }

  if (end - start == 1) {
    return calc[start][end] = procs[start].x * procs[start].y * procs[end].y;
  }

  // start ~ i, i+1 ~ end
  int min = -1;
  for (int i = start; i < end; i++) {
    int temp = getMin(start, i) + getMin(i + 1, end) +
               procs[start].x * procs[i].y * procs[end].y;

    if (min == -1 || temp < min) {
      min = temp;
    }
  }
  return calc[start][end] = min;
}

int main() {
  int n;

  memset(calc, -1, sizeof(calc));

  cin >> n;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    Proc proc = {x, y};
    procs.push_back(proc);

    calc[i][i] = 0;
  }

  cout << getMin(0, n - 1) << endl;
}