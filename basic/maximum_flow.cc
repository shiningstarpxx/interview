#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

bool bfs(std::vector<std::vector<int>> &matrix, int start, int sink, std::vector<int>& parent) {
  int size = matrix.size();
  parent = std::vector<int>(size, 0);

  std::deque<int> q;
  std::vector<bool> visited(size);
  q.push_back(start);

  while (!q.empty()) {
    int c = q.front();
    q.pop_front();

    for (int i = 0; i < size; ++i) {
      if (matrix[c][i] > 0 && !visited[i]) {
        visited[i] = true;
        parent[i] = c;
        q.push_back(i);
      }
    }
  }

  return visited[sink] == true;
}

int ford_fulkson(std::vector<std::vector<int>> &matrix, int start, int sink) {
  std::vector<std::vector<int>> residal_grpah = matrix;

  int max_flow = 0;
  std::vector<int> parent;

  while (bfs(residal_grpah, start, sink, parent)) {
    int current_flow = INT32_MAX;

    for (int p = sink; p != start; p = parent[p]) {
      int r = residal_grpah[parent[p]][p];
      current_flow = std::min(current_flow, r);
    }

    for (int p = sink; p != start; p = parent[p]) {
      residal_grpah[parent[p]][p] -= current_flow;
      residal_grpah[p][parent[p]] += current_flow;

    }
    max_flow += current_flow;
    std::cout << "test line" << std::endl;
  }

  return max_flow;
}

int main() {
  std::vector<std::vector<int>> matrix = {
    {0, 16, 13, 0, 0, 0}, 
    {0, 0, 10, 12, 0, 0}, 
    {0, 4, 0, 0, 14, 0}, 
    {0, 0, 9, 0, 0, 20}, 
    {0, 0, 0, 7, 0, 4}, 
    {0, 0, 0, 0, 0, 0}};

  std::cout << ford_fulkson(matrix, 0, 5) << std::endl;
  return 0;
}