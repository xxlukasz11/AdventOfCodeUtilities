#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

namespace common {

/*
Reads values from space-delimited string

@param T - type of values
@param str - input string
@returns array of values
*/
template<typename T>
std::vector<T> parseArray(const std::string& str) {
	std::istringstream stream(str);
	std::vector<T> data;
	for (T value; stream >> value;) {
		data.push_back(value);
	}
	return data;
}

/*
Reads wrappers from space-delimited string

@param T - type of values
@param Wrapper - type of wrapper class with single arg constructor or aggregate with 1 member of type T
@param str - input string
@returns array of wrappers
*/
template<typename T, typename Wrapper>
std::vector<Wrapper> parseArray(const std::string& str) {
	std::istringstream stream(str);
	std::vector<Wrapper> data;
	for (T value; stream >> value;) {
		data.push_back(Wrapper{value});
	}
	return data;
}

/*
Reads values from string delimited with specified delimiter

@param T - type of values
@param str - input string
@param delimiter - delimiter character
@returns array of values
*/
template<typename T>
std::vector<T> parseArray(const std::string& str, char delimiter) {
	std::istringstream stream(str);
	std::vector<T> data;
	for (T value; stream >> value;) {
		data.push_back(value);
		if (stream.peek() == delimiter) {
			stream.ignore();
		}
	}
	return data;
}

/*
Reads wrappers from string delimited with specified delimiter

@param T - type of values
@param Wrapper - type of wrapper class with single arg constructor or aggregate with 1 member of type T
@param str - input string
@param delimiter - delimiter character
@returns array of wrappers
*/
template<typename T, typename Wrapper>
std::vector<Wrapper> parseArray(const std::string& str, char delimiter) {
	std::istringstream stream(str);
	std::vector<Wrapper> data;
	for (T value; stream >> value;) {
		data.push_back(Wrapper{ value });
		if (stream.peek() == delimiter) {
			stream.ignore();
		}
	}
	return data;
}

/*
Reads digits from contiguous string

@param T - type of digit
@param str - input string
@returns array of digits
*/
template<typename T>
std::vector<T> parseDigits(const std::string& str) {
	std::vector<T> data;
	std::transform(str.begin(), str.end(), std::back_inserter(data), [](const char value) {
		return value - '0';
	});
	return data;
}

}