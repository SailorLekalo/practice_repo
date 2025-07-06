#include <vector>
#include <queue>
#include <utility>

class Solution {
    // Traverse island using BFS with all four possible directions
    void island(std::vector<std::vector<char>>& grid, const std::pair<int, int>& root) {
        std::queue<std::pair<int, int>> q;
        q.push(root);
        // mark as checked
        grid[root.first][root.second] = '0';

        while (!q.empty()) {
            std::pair<int, int> curr = q.front();
            q.pop();

            // go left/right/up/down
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; ++i) {
                int next_row = curr.first + dr[i];
                int next_col = curr.second + dc[i];

                if (next_row >= 0 && next_row < grid.size() &&
                    next_col >= 0 && next_col < grid[0].size() &&
                    grid[next_row][next_col] == '1') {
                    // continue island, mark as checked
                    q.push({next_row, next_col});
                    grid[next_row][next_col] = '0';
                }
            }
        }
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int count = 0;
        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == '1') {
                    // island part found, traverse it
                    ++count;
                    island(grid, std::make_pair(row, col));
                }
            }
        }

        return count;
    }
};

// Runtime: O(nm)
// Memory: O(nm)
