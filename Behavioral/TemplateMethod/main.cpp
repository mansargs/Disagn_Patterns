#include "CaffeineBeverage.hpp"

int main() {
	std::cout << "=== Making coffee ===\n";
	Coffee coffee;
	coffee.prepareRecipe();

	std::cout << "\n=== Making tea ===\n";
	Tea tea;
	tea.prepareRecipe();

	return 0;
}
