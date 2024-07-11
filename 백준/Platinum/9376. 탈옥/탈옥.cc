#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int h, w;
char jail[102][102];
int vis[102][102][3];

struct Pos {
  int x;
  int y;
  int door;

  bool operator<(const Pos& other) const { return door > other.door; }
};
vector<Pos> people;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void init() {
  memset(jail, '.', sizeof(jail));
  memset(vis, -1, sizeof(vis));
  people.clear();
}

void getJailInput() {
  cin >> h >> w;
  people.push_back({0, 0, 0});

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> jail[i][j];
      if (jail[i][j] == '$') {
        people.push_back({i, j, 0});
      }
    }
  }
}

bool canMove(int x, int y) {
  if (x >= 0 && x <= h + 1 && y >= 0 && y <= w + 1) {
    return true;
  }
  return false;
}

void dijkstra(Pos pos, int idx) {
  priority_queue<Pos> pq;
  pq.push(pos);
  vis[pos.x][pos.y][idx] = pos.door;

  while (!pq.empty()) {
    Pos top = pq.top();
    pq.pop();
    int x = top.x;
    int y = top.y;
    int door = top.door;

    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      char nc = jail[nx][ny];

      if (!canMove(nx, ny) || vis[nx][ny][idx] > -1 || nc == '*') {
        continue;
      }

      if (nc == '#') {
        vis[nx][ny][idx] = door + 1;
        pq.push({nx, ny, door + 1});
        continue;
      }

      vis[nx][ny][idx] = door;
      pq.push({nx, ny, door});
    }
  }
}

int getAnswer() {
  int ans = vis[0][0][0] + vis[0][0][1] + vis[0][0][2];

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (jail[i][j] == '*') {
        continue;
      }

      int sum = vis[i][j][0] + vis[i][j][1] + vis[i][j][2];
      if (sum < 0) {
        continue;
      }
      if (jail[i][j] == '#') {
        sum -= 2;
      }
      ans = min(ans, sum);
    }
  }

  return ans;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    init();
    getJailInput();

    for (int i = 0; i < people.size(); i++) {
      dijkstra(people[i], i);
    }
    cout << getAnswer() << endl;
  }
}