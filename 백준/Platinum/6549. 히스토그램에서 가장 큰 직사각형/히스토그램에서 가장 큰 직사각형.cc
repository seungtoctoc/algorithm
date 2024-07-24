#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Square {
  int location;
  int height;
};

stack<Square> st;
long long ans = 0;

void pushSquare(int location, int height) {
  if (height >= st.top().height) {
    st.push({location, height});
    return;
  }

  int right_location = location;
  Square top;

  while (st.top().height > height) {
    top = st.top();
    st.pop();

    long long area = (long long)top.height * (right_location - top.location);
    ans = max(area, ans);
  }

  st.push({top.location, height});
  st.push({location, height});
}

void init() {
  while (st.size() > 0) {
    st.pop();
  }
  ans = 0;
}

int main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0) {
      break;
    }

    init();
    st.push({0, 0});
    for (int i = 1; i <= n; i++) {
      int height;
      cin >> height;

      pushSquare(i, height);
    }
    pushSquare(n + 1, 0);

    cout << ans << endl;
  }
}