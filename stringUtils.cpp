#include "pch.h"
#include "stringUtils.h"

namespace common {

std::string replaceFirst(const std::string& str, const std::string& from, const std::string& to) {
	auto pos = str.find(from);
	if (pos == std::string::npos) {
		return str;
	}
	std::string newStr = str;
	newStr.replace(pos, from.size(), to);
	return newStr;
}

std::string replaceAll(const std::string& str, const std::string& from, const std::string& to) {
	size_t pos = 0;
	std::string newStr = str;
	while ((pos = newStr.find(from, pos)) != std::string::npos) {
		newStr.replace(pos, from.length(), to);
		pos += to.length();
	}
	return newStr;
}

} // namespace common