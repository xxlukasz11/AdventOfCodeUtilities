#pragma once

#include <string>

namespace common {

/*
Replaces fist occurence of provided string

@param str - input string
@param from - string to be replaced
@param to - replacement
*/
void replaceFirst(std::string& str, const std::string& from, const std::string& to);

/*
Replaces all occurences of provided string

@param str - input string
@param from - string to be replaced
@param to - replacement
*/
void replaceAll(std::string& str, const std::string& from, const std::string& to);

} // namespace common