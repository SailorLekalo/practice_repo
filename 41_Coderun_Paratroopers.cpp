#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>

#define uint unsigned

uint get_num_vert(uint m, uint i, uint j, std::vector<uint> &index_to_vertex) {
	return index_to_vertex[i * m + j];
}

void color_eq_heights(std::pair<uint, uint> start_v, const uint color, 
					  std::vector< std::vector<uint> >& vertices, 
					  const std::vector< std::vector<uint> >& heights
					  ) {
	const std::pair<int, int> moves[4] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
	std::queue<std::pair<uint, uint>> eq_heights;
	uint h = heights[start_v.first][start_v.second];
	eq_heights.push(start_v);
	vertices[start_v.first][start_v.second] = color;

	while (eq_heights.empty() == false) {
		auto v = eq_heights.front();
		eq_heights.pop();
		for (auto move : moves) {
			std::pair<uint, uint> v_to = {v.first + move.first, v.second + move.second};
			if (heights[v_to.first][v_to.second] == h &&
				vertices[v_to.first][v_to.second] != color) {
				
				vertices[v_to.first][v_to.second] = color;
				eq_heights.push(v_to);
			}
		}
	}
}

int main() 
{
	// Я думала, тут красивое решение с перестройкой графа, а это неправда ))))))):
	// Трюк, для удобства делаем матрицу с краем 10001
	uint N, M;
	std::cin >> N >> M;
	std::vector<std::vector<uint> > heights(N + 2, std::vector<uint>(M + 2, 10001U));
	std::vector<std::vector<uint> > square_to_vertex(N + 2, std::vector<uint>(M + 2, 10001U));
	std::vector<std::set<uint> > graph;

	for (uint i = 1; i <= N; ++i) {
		for (uint j = 1; j <= M; ++j) {
			std::cin >> heights[i][j];
		}
	}

	uint color = 0;
	for (uint i = 1; i <= N; ++i) {
		for (uint j = 1; j <= M; ++j) {
			if (square_to_vertex[i][j] == 10001U) {
				color_eq_heights({i, j}, color, square_to_vertex, heights);
				++color;
			}
		}
	}

	graph.resize(color, {});
	// меньшая высота -> большая высота
	for (uint i = 1; i <= N; ++i) {
		for (uint j = 1; j <= M; ++j) {
			uint num_ver = square_to_vertex[i][j];
			uint h = heights[i][j];
			if (h < heights[i - 1][j] && i > 1) {
				graph[square_to_vertex[i - 1][j]].insert(num_ver);
			}
			if (h > heights[i - 1][j]) {
				graph[num_ver].insert(square_to_vertex[i - 1][j]);
			}

			if (h < heights[i][j - 1]  && j > 1) {
				graph[square_to_vertex[i][j - 1]].insert(num_ver);
			}
		   	if (h > heights[i][j - 1]) {
				graph[num_ver].insert(square_to_vertex[i][j - 1]);
			}
		}
	}

	uint ans = 0;
	for (uint i = 0; i < graph.size(); ++i) {
		if (graph[i].empty()) {
			++ans;
		}
	}

	std::cout << ans;

	return 0;
}
