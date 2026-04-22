#include <bits/stdc++.h>

int solution(std::vector<int> numbers, int target)
{
    int answer = 0;

    std::priority_queue<std::pair<int, int>> pq;
    pq.push({0, numbers[0]});
    pq.push({0, -numbers[0]});

    while (not pq.empty())
    {
        const int index = pq.top().first;
        const int result = pq.top().second;
        pq.pop();

        if (index == numbers.size() - 1)
        {
            if (result == target)
            {
                answer++;
            }
            continue;
        }

        pq.emplace(index + 1, result + numbers[index + 1]);
        pq.emplace(index + 1, result - numbers[index + 1]);
    }

    return answer;
}