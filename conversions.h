#pragma once

#include "traits.h"
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <iomanip>

namespace common {

/*
Converts hex character to decimal value

@param hex - hex character
@returns decimal value
*/
int hexToDec(const char hex);

/*
Converts hex array to decimal value with type ResultT

@param hex - array of hex characters
@returns decimal value
*/
template<typename ResultT, typename ContainerT, typename = EnableIntegral<ResultT>>
ResultT hexToDec(const ContainerT& hexArray) {
	std::stringstream ss;
	for (const char hex : hexArray) {
		ss << std::hex << hex;
	}
	ResultT result{};
	ss >> result;
	return result;
}

/*
Converts hex character to binary string

@param hex - hex character
@returns string with zeros and ones
*/
std::string hexToBinString(const char hex);

/*
Converts array of hex characters to binary string

@param hex - array of hex characters
@returns string with zeros and ones
*/
template<typename ContainerT>
std::string hexToBinString(const ContainerT& hexArray) {
	std::ostringstream outputString;
	for (const char hex : hexArray) {
		outputString << hexToBinString(hex);
	}
	return outputString.str();
}

/*
Converts array of hex characters to bool array

@param hex - array of hex characters
@returns array of bool values
*/
template<typename ContainerT>
std::vector<bool> hexToBinArray(const ContainerT& hexArray) {
	std::vector<bool> binaryArray;
	for (const char hex : hexArray) {
		const std::string binaryString = hexToBinString(hex);
		std::transform(binaryString.begin(), binaryString.end(), std::back_inserter(binaryArray), [](const char bit) {
			return bit > '0';
		});
	}
	return binaryArray;
}

/*
Converts decimal value to binary string

@param value - integral value
@returns string with zeros and ones
*/
template<typename IntegralT, typename = EnableIntegral<IntegralT>>
std::string decToBinString(const IntegralT value) {
	constexpr auto noOfBits = std::numeric_limits<IntegralT>::digits;
	return std::bitset<noOfBits>(value).to_string();
}

/*
Converts decimal value to hex string

@param value - integral value
@returns string with hex characters
*/
template<typename IntegralT, typename = EnableIntegral<IntegralT>>
std::string decToHexString(const IntegralT value) {
	std::ostringstream ss;
	ss << std::setfill('0') << std::setw(sizeof(IntegralT) * 2) << std::hex << value;
	return ss.str();
}

}