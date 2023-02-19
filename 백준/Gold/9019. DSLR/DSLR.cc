#include <iostream>
#include <queue>
#include <string>

int A, B;
bool visited[10001];
void calculator();

int main() {
  int T;

  std::cin >> T;
  while (T--) {
    std::cin >> A >> B;
    std::fill(visited, visited + 10001, false);
    calculator();
  }

  return 0;
}

void calculator() {
  std::queue<std::pair<int, std::string>> q;
  q.push({A, ""});
  visited[A] = true;

  while (!q.empty()) {
    int num = q.front().first;
    std::string op = q.front().second;
    q.pop();

    if (num == B) {
      std::cout << op << '\n';
      return;
    }

    int D = (num * 2) % 10000;
    if (!visited[D]) {
      q.push({D, op + "D"});
      visited[D] = true;
    }
    int S = num - 1 < 0 ? 9999 : num - 1;
    if (!visited[S]) {
      q.push({S, op + "S"});
      visited[S] = true;
    }
    int L = (num % 1000) * 10 + num / 1000;
    if (!visited[L]) {
      q.push({L, op + "L"});
      visited[L] = true;
    }
    int R = (num % 10) * 1000 + num / 10;
    if (!visited[R]) {
      q.push({R, op + "R"});
      visited[R] = true;
    }
  }
}