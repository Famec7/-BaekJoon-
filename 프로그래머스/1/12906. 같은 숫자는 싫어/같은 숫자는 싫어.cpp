#include <bits/stdc++.h>

std::vector<int> solution(std::vector<int> arr)
{
    std::vector<int> answer;

    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0 || arr[i] != arr[i - 1])
        {
            answer.push_back(arr[i]);
        }
    }

    return answer;
}