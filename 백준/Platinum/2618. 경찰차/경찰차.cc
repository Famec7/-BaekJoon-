#include <iostream>
#include <utility>

std::pair<int, int> cases[1001];

int N, W, cache[1001][1001];
int distance(int case1, int case2);
int solve(int case1, int case2);
void root(int case1, int case2);

int main() {
  std::cin >> N >> W;
  for (int i = 1; i <= W; i++)
    std::cin >> cases[i].first >> cases[i].second;
  std::fill(&cache[0][0], &cache[1000][1001], -1);
  std::cout << solve(0, 0) << '\n';
  root(0, 0);

  return 0;
}

int distance(int case1, int case2) {
  return abs(cases[case1].first - cases[case2].first) +
         abs(cases[case1].second - cases[case2].second);
}

int solve(int case1, int case2) {
  if (case1 == W || case2 == W)
    return 0;

  int &ret = cache[case1][case2];
  if (ret != -1)
    return ret;

  int next = std::max(case1, case2) + 1;

  int dist1, dist2;
  if (case1 == 0)
    dist1 = solve(next, case2) + abs(cases[next].first - 1) +
            abs(cases[next].second - 1);
  else
    dist1 = solve(next, case2) + distance(case1, next);
  if (case2 == 0)
    dist2 = solve(case1, next) + abs(cases[next].first - N) +
            abs(cases[next].second - N);
  else
    dist2 = solve(case1, next) + distance(case2, next);

  ret = std::min(dist1, dist2);
  return ret;
}

void root(int case1, int case2) {
  if (case1 == W || case2 == W)
    return;

  int next = std::max(case1, case2) + 1;
  int dist1, dist2;

  if (case1 == 0)
    dist1 = cache[next][case2] + abs(cases[next].first - 1) +
            abs(cases[next].second - 1);
  else
    dist1 = cache[next][case2] + distance(case1, next);
  if (case2 == 0)
    dist2 = cache[case1][next] + abs(cases[next].first - N) +
            abs(cases[next].second - N);
  else
    dist2 = cache[case1][next] + distance(case2, next);

  if (dist1 < dist2) {
    std::cout << "1\n";
    root(next, case2);
  } else {
    std::cout << "2\n";
    root(case1, next);
  }
}