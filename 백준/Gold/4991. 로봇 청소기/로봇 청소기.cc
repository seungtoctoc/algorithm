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
};

char map[22][22];
int distances[22][22][10] = {};
vector<Pos> dirty;
Pos start;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void setDistancesOfDirty(int dirty_num) {
  queue<Pos> q;
  q.push(dirty[dirty_num]);
  distances[dirty[dirty_num].x][dirty[dirty_num].y][dirty_num] = 0;

  while (!q.empty()) {
    Pos current = q.front();
    q.pop();
    int x = current.x;
    int y = current.y;

    for (int i = 0; i < 4; i++) {
      if (distances[x + dx[i]][y + dy[i]][dirty_num] == -1 &&
          map[x + dx[i]][y + dy[i]] != 'x') {
        q.push({x + dx[i], y + dy[i]});
        distances[x + dx[i]][y + dy[i]][dirty_num] =
            distances[x][y][dirty_num] + 1;
      }
    }
  }
}

void getMapInput(int w, int h) {
  memset(map, 'x', sizeof(map));
  dirty.clear();

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> map[i][j];

      if (map[i][j] == 'o') {
        start = {i, j};
        continue;
      }

      if (map[i][j] == '*') {
        dirty.push_back({i, j});
      }
    }
  }
}

void printDistances(int dirty_num) {
  cout << "print num: " << dirty_num << endl;
  for (int i = 1; i <= 7; i++) {
    for (int j = 1; j <= 7; j++) {
      cout << distances[i][j][dirty_num] << " ";
    }
    cout << endl;
  }
  cout << endl << endl;
}

int vis[10] = {};
int ans = 400;
void getAnswer(int x, int y, int sum, int vis_cnt) {
  if (vis_cnt == dirty.size()) {
    ans = min(ans, sum);
    return;
  }

  for (int i = 0; i < dirty.size(); i++) {
    if (vis[i] == 0) {
      vis[i] = 1;

      if (distances[x][y][i] == -1) {
        ans = -1;
        return;
      }

      getAnswer(dirty[i].x, dirty[i].y, sum + distances[x][y][i], vis_cnt + 1);
      vis[i] = 0;
    }
  }
}

int main() {
  while (true) {
    int w = 100, h = 100;
    cin >> w >> h;

    if (w == 0 && h == 0) {
      break;
    }

    getMapInput(w, h);

    memset(distances, -1, sizeof(distances));
    for (int i = 0; i < dirty.size(); i++) {
      setDistancesOfDirty(i);
      // printDistances(i);
    }

    memset(vis, 0, sizeof(vis));
    ans = 400;
    getAnswer(start.x, start.y, 0, 0);
    cout << ans << endl;
  }
}