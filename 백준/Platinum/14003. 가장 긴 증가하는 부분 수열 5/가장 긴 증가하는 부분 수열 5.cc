#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> inputs;
vector<int> seq;
int pos[1'000'000];

void PushAndsetPos(int index) {
  int current = inputs[index];

  if (seq.size() == 0 || seq.back() < current) {
    pos[index] = seq.size();
    seq.push_back(current);

    return;
  }

  if (current <= seq.front()) {
    pos[index] = 0;
    seq[0] = current;

    return;
  }

  int left = 0;
  int right = seq.size() - 1;

  while (left + 1 < right) {
    int mid = (left + right) / 2;

    if (seq[mid] < current) {
      left = mid;
      continue;
    }

    right = mid;
  }

  pos[index] = right;
  seq[right] = current;
}

void PrintAnswer(int seq_size) {
  int target_order = seq_size - 1;
  stack<int> ans;

  for (int i = inputs.size() - 1; i >= 0; i--) {
    if (pos[i] == target_order) {
      ans.push(inputs[i]);
      target_order--;
    }
  }

  while (!ans.empty()) {
    cout << ans.top() << " ";
    ans.pop();
  }

  cout << endl;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;

    inputs.push_back(num);
  }

  for (int i = 0; i < n; i++) {
    PushAndsetPos(i);
  }

  cout << seq.size() << endl;
  PrintAnswer(seq.size());
}