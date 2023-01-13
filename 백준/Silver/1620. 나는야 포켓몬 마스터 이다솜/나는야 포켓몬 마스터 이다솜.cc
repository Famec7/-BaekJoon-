#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(0);
	std::cin.tie(NULL);

  int N, M;

  std::cin >> N >> M;
  std::map<int, std::string> name;
  std::map<std::string, int> number;
  std::string pocketMon;
  for (int i = 1; i <= N; i++) {
    std::cin >> pocketMon;
    name[i] = pocketMon;
    number.insert(std::make_pair(pocketMon, i));
  }

  for (int i = 0; i < M; i++) {
    std::cin >> pocketMon;
    if (pocketMon[0] >= 'A' && pocketMon[0] <= 'Z')
      std::cout << number[pocketMon] << '\n';
    else
      std::cout << name[std::stoi(pocketMon)] << '\n';
  }

  return 0;
}