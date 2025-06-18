#include <iostream>
#include <string>
#include <vector>
#include <set>

int main() 
{	
	int gg;
	std::set<int> ggg;
	while (std::cin >> gg) {
		ggg.insert(gg);
	}

	std::cout << ggg.size();

	return 0;
}
