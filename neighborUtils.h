#pragma once

#include <vector>
#include <optional>

namespace common {

enum class SearchPolicy {
	ADJACENT,
	DIAGONAL,
	ALL
};

template<typename T>
struct Neighbor {
	Neighbor(T value, int row, int col) : value(value), row(row), col(col) {}
	T value;
	int row;
	int col;
};

/*
Looks for cell neighbors according to priovided policy

@param container - 2 dimensional array
@param row - index of a center cell row
@param col - index of a center cell column
@param radius - determines radius of the lookup
@param policy - determines whether all, adjacent or diagonal neighbors to return
@returns array of neighbors
*/
template<typename Container>
auto findNeighbors(const Container& container, int row, int col, int radius = 1, SearchPolicy policy = SearchPolicy::ALL) {
	const int rows = container.size();
	const int cols = container[0].size();
	using ContainerVT = typename Container::value_type::value_type;
	std::vector<Neighbor<ContainerVT>> neighbors;
	for (int r = row - radius; r <= row + radius; ++r) {
		for (int c = col - radius; c <= col + radius; ++c) {
			if (r < 0 || r >= rows || c < 0 || c >= cols) {
				continue;
			}
			if (c == col && r == row) {
				continue;
			}
			if (policy == SearchPolicy::ADJACENT && row != r && col != c) {
				continue;
			}
			if (policy == SearchPolicy::DIAGONAL && (row == r || col == c)) {
				continue;
			}
			decltype(auto) value = container[r][c];
			neighbors.emplace_back(container[r][c], r, c);
		}
	}
	return neighbors;
}

struct Dir {
	static const Dir TOP;
	static const Dir TOP_RIGHT;
	static const Dir RIGHT;
	static const Dir BOTTOM_RIGHT;
	static const Dir BOTTOM;
	static const Dir BOTOM_LEFT;
	static const Dir LEFT;
	static const Dir TOP_LEFT;

	const int x;
	const int y;
};

/*
Try to get neighbor cell in the provided direction

@param container - 2 dimensional array
@param row - index of a center cell row
@param col - index of a center cell column
@param dir - direction of the neighbor cell
@returns neighbor cell or std::nullopt if cell does not exist
*/
template<typename Container>
std::optional<typename Container::value_type::value_type> tryGet(const Container& container, int row, int col, Dir dir) {
	return tryGet(container, row + dir.y, col + dir.x);
}

/*
Try to get calue from the container

@param container - 2 dimensional array
@param row - row index of a cell
@param col - column index of a cell
@returns cell or std::nullopt if cell does not exist
*/
template<typename Container>
std::optional<typename Container::value_type::value_type> tryGet(const Container& container, int row, int col) {
	const int rows = container.size();
	const int cols = container[0].size();
	if (row >= 0 && col >= 0 && row < rows && col < cols) {
		return container[row][col];
	}
	return std::nullopt;
}

} // namespace