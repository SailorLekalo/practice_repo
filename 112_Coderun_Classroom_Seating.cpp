#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define uint unsigned

int main() 
{
	uint N, D;
	// .first значение, .second позиция в исходном
	std::vector<std::pair<uint, uint> > students;
	std::cin >> N >> D;

	for (uint i = 0; i < N; ++i) {
		uint x;
		std::cin >> x; 
		students.push_back({ x, i });
	}
	std::sort(students.begin(), students.end());

	std::vector<uint> tickets(N, 0U);
	uint types = 1;

	// 1. Считаем кол-во типов билетов
	// 2. Потом в очереди храним доступные нам билеты
	// 3. Двумя указателями кайфуем

	uint r = 0;
	uint max_types = 1;
	// В max_types считаем минимальное кол-во билетов разного вида
	for (uint l = 0; l < N - 1; ++l) {
		max_types = std::max(max_types, 1U);
		r = std::max(r, l + 1);

		while (r < N && students[r].first - students[l].first <= D) {
			++r;
			++max_types;
		}

		types = std::max(max_types, types);
		--max_types;
	}

	// В available_types поддерживаем доступные виды билетов
	std::queue<uint> available_types;
	for (uint i = 1; i <= types; ++i) {
		available_types.push(i);
	}

	// Идем по студентам и назначаем им билеты
	r = 0;
	for (uint l = 0; l < N; ++l) {
		if (tickets[l] == 0) {
			tickets[l] = available_types.front();
			available_types.pop();
		}

		r = std::max(r, l + 1);
		while (r < N && students[r].first - students[l].first <= D) {
			tickets[r] = available_types.front();
			available_types.pop();
			++r;
		}

		available_types.push(tickets[l]);
	}

	std::vector<uint> students_to_tickets(N);

	for (uint i = 0; i < N; ++i) {
		students_to_tickets[students[i].second] = tickets[i];
	}

	std::cout << types << "\n";
	for (uint i = 0; i < N; ++i) {
		std::cout << students_to_tickets[i] << " ";
	}

	return 0;
}
