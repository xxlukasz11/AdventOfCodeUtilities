#pragma once

#include <string>

namespace common {

/*
Replaces fist occurence of provided string

@param str - input string
@param from - string to be replaced
@param to - replacement
*/
std::string replaceFirst(const std::string& str, const std::string& from, const std::string& to);

/*
Replaces all occurences of provided string

@param str - input string
@param from - string to be replaced
@param to - replacement
*/
std::string replaceAll(const std::string& str, const std::string& from, const std::string& to);

} // namespace common