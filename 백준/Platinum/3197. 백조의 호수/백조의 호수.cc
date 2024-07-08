#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int r, c;
char lake[1500][1500];
int melt[1500][1500] = {};
int vis[1500][1500] = {};
int total_duck = 0;
int duck_x = 0;
int duck_y = 0;
int max_melt = 0;

struct Pos {
  int x;
  int y;
  int melt_day;

  bool operator<(const Pos& other) const { return melt_day > other.melt_day; }
};
priority_queue<Pos> pq;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void getLakeInput() {
  cin >> r >> c;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> lake[i][j];
    }
  }
}

bool canMove(int x, int y) {
  if (x >= 0 && x < r && y >= 0 && y < c) {
    return true;
  }
  return false;
}

void searchFirstDayIce(int x, int y) {
  melt[x][y] = 1;
  pq.push({x, y, melt[x][y]});

  while (!pq.empty() && pq.top().melt_day <= 1) {
    Pos top_pos = pq.top();
    pq.pop();

    if (lake[top_pos.x][top_pos.y] == 'L') {
      total_duck++;
      duck_x = top_pos.x;
      duck_y = top_pos.y;
    }

    for (int i = 0; i < 4; i++) {
      int nx = top_pos.x + dx[i];
      int ny = top_pos.y + dy[i];

      if (!canMove(nx, ny) || melt[nx][ny] > 0) {
        continue;
      }

      if (lake[nx][ny] == '.' || lake[nx][ny] == 'L') {
        melt[nx][ny] = top_pos.melt_day;
        pq.push({nx, ny, top_pos.melt_day});
        continue;
      }

      melt[nx][ny] = top_pos.melt_day + 1;
      pq.push({nx, ny, top_pos.melt_day + 1});
    }
  }
}

void setExtraMelt() {
  while (!pq.empty()) {
    Pos top_pos = pq.top();
    pq.pop();

    for (int i = 0; i < 4; i++) {
      int nx = top_pos.x + dx[i];
      int ny = top_pos.y + dy[i];

      if (!canMove(nx, ny) || melt[nx][ny] > 0) {
        continue;
      }

      melt[nx][ny] = top_pos.melt_day + 1;
      pq.push({nx, ny, top_pos.melt_day + 1});
    }
  }
}

void setMelt() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (lake[i][j] != 'X' && melt[i][j] == 0) {
        searchFirstDayIce(i, j);
      }
    }
  }
  setExtraMelt();
}

void searchDuck() {
  pq.push({duck_x, duck_y, melt[duck_x][duck_y]});
  vis[duck_x][duck_y] = 1;
  int current_duck = 0;

  while (!pq.empty()) {
    Pos top_pos = pq.top();
    pq.pop();
    max_melt = max(max_melt, melt[top_pos.x][top_pos.y]);

    if (lake[top_pos.x][top_pos.y] == 'L') {
      current_duck++;

      if (current_duck == total_duck) {
        return;
      }
    }

    for (int i = 0; i < 4; i++) {
      int nx = top_pos.x + dx[i];
      int ny = top_pos.y + dy[i];

      if (!canMove(nx, ny) || vis[nx][ny] > 0) {
        continue;
      }

      vis[nx][ny] = 1;
      pq.push({nx, ny, melt[nx][ny]});
    }
  }
}

int main() {
  getLakeInput();
  setMelt();
  searchDuck();
  cout << max_melt - 1 << endl;
}