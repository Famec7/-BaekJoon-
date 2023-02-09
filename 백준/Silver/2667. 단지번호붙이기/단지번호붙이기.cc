#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int N, count = 0;
int complex[25][25];
bool visited[25][25];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void dfs(int y, int x);

int main() {
  std::vector<int> result;
  std::string s;

  std::cin >> N;
  for (int i = 0; i < N; i++) {
    std::cin >> s;
    for (int j = 0; j < N; j++)
      complex[i][j] = s[j] - '0';
  }
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (complex[y][x] == 1 && !visited[y][x]) {
        visited[y][x] = true;
        count = 1;
        dfs(y, x);
        result.push_back(count);
      }
    }
  }
  std::sort(result.begin(), result.end());
  std::cout << result.size() << '\n';
  for (const auto &ret : result)
    std::cout << ret << '\n';

  return 0;
}

void dfs(int y, int x) {
  visited[y][x] = true;

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
      continue;
    if (complex[ny][nx] == 1 && !visited[ny][nx]) {
      count++;
      dfs(ny, nx);
    }
  }
}