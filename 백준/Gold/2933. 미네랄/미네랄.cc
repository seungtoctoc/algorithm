#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

int r, c;
char cave[102][102];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int vis[102][102] = {};
int drop_height_limit[5] = {};
bool is_float[5];

void getCaveInput() {
  cin >> r >> c;
  memset(cave, '.', sizeof(cave));
  for (int i = 0; i <= c + 1; i++) {
    cave[r + 1][i] = 'x';
  }

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cin >> cave[i][j];
    }
  }
}

void dfs(int x, int y, int group) {
  vis[x][y] = group;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (cave[nx][ny] == 'x' && vis[nx][ny] == 0) {
      dfs(nx, ny, group);
    }
  }
}

void searchNearClusterShouldBeDropped(int x, int y) {
  memset(vis, 0, sizeof(vis));
  dfs(r + 1, 0, -1);

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (cave[nx][ny] != 'x' || vis[nx][ny] != 0) {
      is_float[i + 1] = false;
      continue;
    }

    dfs(nx, ny, i + 1);
    is_float[i + 1] = true;
  }
}

bool hasFloatCluster() {
  for (int i = 1; i <= 4; i++) {
    if (is_float[i]) {
      return true;
    }
  }
  return false;
}

void searchFloatClusterAndDrop() {
  while (hasFloatCluster()) {
    for (int i = r; i >= 1; i--) {
      for (int j = 1; j <= c; j++) {
        if (cave[i][j] == 'x' && vis[i][j] > 0) {
          cave[i + 1][j] = 'x';
          cave[i][j] = '.';
          vis[i + 1][j] = vis[i][j];
          vis[i][j] = 0;

          if (cave[i + 2][j] == 'x' && vis[i + 2][j] != vis[i + 1][j]) {
            is_float[vis[i + 1][j]] = false;
          }
        }
      }
    }
  }
}

void throwStick(int height, bool throwFromLeft) {
  if (throwFromLeft) {
    for (int i = 1; i <= c; i++) {
      if (cave[height][i] == 'x') {
        cave[height][i] = '.';
        searchNearClusterShouldBeDropped(height, i);
        searchFloatClusterAndDrop();
        return;
      }
    }
  }
  for (int i = c; i >= 1; i--) {
    if (cave[height][i] == 'x') {
      cave[height][i] = '.';
      searchNearClusterShouldBeDropped(height, i);
      searchFloatClusterAndDrop();
      return;
    }
  }
}

void printCave() {
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      cout << cave[i][j];
    }
    cout << endl;
  }
}

void getThrowStickInput() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int height;
    cin >> height;

    if (i % 2 == 0) {
      throwStick(r + 1 - height, true);
      continue;
    }
    throwStick(r + 1 - height, false);
  }
}

int main() {
  getCaveInput();
  getThrowStickInput();
  printCave();
}