#include "pch.h"
#include "stringUtils.h"

namespace common {

void replaceFirst(std::string& str, const std::string& from, const std::string& to) {
	auto pos = str.find(from);
	if (pos == std::string::npos) {
		return;
	}
	str.replace(pos, from.size(), to);
}

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
	size_t pos = 0;
	while ((pos = str.find(from, pos)) != std::string::npos) {
		str.replace(pos, from.length(), to);
		pos += to.length();
	}
}

} // namespace common