#include <bits/stdc++.h>

typedef struct Node
{
    int left;
    int right;
} Node;

const int MAX_N = 100001;
int N = 0;
Node nodes[MAX_N];

void input()
{
    std::cin >> N;
    int data = 0;
    for (int i = 0; i < N; i++)
    {
        std::cin >> data;
        std::cin >> nodes[data].left >> nodes[data].right;
    }
}

/*
 * 유사 중위 순회
 * node: 현재 노드
 * is_round_trip: 오른쪽 자식 노드를 방문한 후 다시 루트 노드로 돌아왔는지 여부
 * move_count: 이동 횟수
 */
void similar_inorder(int node, bool is_round_trip, int &move_count)
{
    if (node == -1)
        return;

    move_count++;
    similar_inorder(nodes[node].left, true, move_count);

    if (not is_round_trip)
    {
        similar_inorder(nodes[node].right, false, move_count);
    }
    else
    {
        move_count++;
        similar_inorder(nodes[node].right, true, move_count);
    }
}

void solve()
{
    int move_count = 0;
    similar_inorder(1, false, move_count);
    std::cout << move_count - 1 << '\n';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    input();
    solve();

    return 0;
}