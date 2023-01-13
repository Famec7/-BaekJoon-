#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(NULL);

  int N, M;
  std::cin >> N >> M;
  std::map<std::string, int> noListen;
  std::string name;
  for (int i = 0; i < N; i++) {
    std::cin >> name;
    noListen[name]++;
  }
  for (int i = 0; i < M; i++) {
    std::cin >> name;
    noListen[name]++;
  }
  int count = 0;
  std::vector<std::string> result;
  for (auto &person : noListen) {
    if (person.second > 1) {
      count++;
      result.push_back(person.first);
    }
  }
  std::cout << count << '\n';
  for (int i = 0; i < count; i++)
    std::cout << result[i] << '\n';

  return 0;
}