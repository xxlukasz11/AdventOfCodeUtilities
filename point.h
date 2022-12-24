#pragma once

#include <functional>

namespace common {

template<typename ValueType>
struct Point {
	ValueType x;
	ValueType y;

	bool operator==(const Point& point) const {
		return x == point.x && y == point.y;
	}

	bool operator!=(const Point& point) const {
		return x != point.x || y != point.y;
	}

	bool operator<(const Point& point) const {
		return x == point.x ? y < point.y : x < point.x;
	}

	bool operator<=(const Point& point) const {
		return x == point.x ? y <= point.y : x <= point.x;
	}

	bool operator>(const Point& point) const {
		return x == point.x ? y > point.y : x > point.x;
	}

	bool operator>=(const Point& point) const {
		return x == point.x ? y >= point.y : x >= point.x;
	}
};

} // namespace common

namespace std {
template <typename ValueType>
struct hash<common::Point<ValueType>> {
	size_t operator()(const common::Point<ValueType>& point) const {
		return std::hash<ValueType>()(point.x) ^ std::hash<ValueType>()(point.y);
	}
};
}