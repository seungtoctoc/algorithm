#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

struct Pos {
  int x;
  int y;
  int direction;
  int change;

  bool operator<(const Pos& other) const { return change > other.change; }
};
priority_queue<Pos> pq;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int r, c;
char input[102][102];
int vis[102][102][5] = {};
int start_x, start_y;

void pushStartPos(int x, int y) {
  input[x][y] = '*';

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (input[nx][ny] != '*') {
      pq.push({
          nx,
          ny,
          i,
      });
      vis[nx][ny][4] = 0;
    }
  }
}

int bfs() {
  while (!pq.empty()) {
    Pos top = pq.top();
    pq.pop();

    int x = top.x;
    int y = top.y;
    int direction = top.direction;
    int change = top.change;

    if (input[x][y] == 'C') {
      return change;
    }

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (input[nx][ny] == '*') {
        continue;
      }

      int nc = change;
      if (i != direction) {
        nc++;
      }

      if (vis[nx][ny][4] < nc) {
        continue;
      }

      if (vis[nx][ny][3 - i] > 0) {
        continue;
      }

      pq.push({nx, ny, i, nc});
      vis[nx][ny][4] = nc;

      vis[nx][ny][i] = 1;
    }
  }

  return -1;
}

void getInput() {
  cin >> c >> r;
  memset(input, '*', sizeof(input));

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> input[i][j];

      if (input[i][j] == 'C') {
        start_x = i;
        start_y = j;
      }

      vis[i][j][4] = 10000;
    }
  }
}

void printInput() {
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cout << input[i][j] << " ";
    }
    cout << endl;
  }
}

void printVis() {
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (vis[i][j][4] == 10000) {
        cout << "* ";
        continue;
      }
      cout << vis[i][j][4] << " ";
    }
    cout << endl;
  }
}

int main() {
  getInput();
  // printInput();

  pushStartPos(start_x, start_y);
  cout << bfs() << endl;

  // cout << endl << "vis" << endl;
  // printVis();
}