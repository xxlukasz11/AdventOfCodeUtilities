#pragma once

#include "neighborUtils.h"

namespace common {

template<typename Container>
class MatrixIterator {
public:
	using ValueType = typename Container::value_type::value_type;

	MatrixIterator(const Container& matrix, int row, int col, Dir dir);
	bool hasValue() const;
	int getCol() const;
	int getRow() const;
	ValueType next();

private:
	const Container& matrix;
	int row;
	int col;
	Dir dir;
};

template<typename Container>
inline MatrixIterator<Container>::MatrixIterator(const Container& matrix, int row, int col, Dir dir) :
	matrix(matrix), row(row), col(col), dir(dir) {
}

template<typename Container>
inline bool MatrixIterator<Container>::hasValue() const {
	auto currentValue = tryGet(matrix, row, col);
	return currentValue.has_value();
}

template<typename Container>
inline int MatrixIterator<Container>::getCol() const {
	return col;
}

template<typename Container>
inline int MatrixIterator<Container>::getRow() const {
	return row;
}

template<typename Container>
inline MatrixIterator<Container>::ValueType MatrixIterator<Container>::next() {
	auto currentValue = tryGet(matrix, row, col);
	row += dir.y;
	col += dir.x;
	return currentValue.value();
}

} // namespace common