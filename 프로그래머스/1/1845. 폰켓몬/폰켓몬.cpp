#include <vector>
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    std::unordered_set<int> set(nums.begin(), nums.end());

    int answer = std::min(set.size(), nums.size() / 2);
    
    return answer;
}