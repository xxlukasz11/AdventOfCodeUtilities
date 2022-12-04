#pragma once

#include <string>
#include <fstream>

namespace common {

class FileReader {
public:
	FileReader(const std::string& fileName);

	/*
	Reads next line from file

	@returns line as string
	*/
	std::string nextLine();

	/*
	Reads next line from file

	@param line - reference to string that will be filled
	@returns true if line was read
	*/
	bool nextLine(std::string& line);

	/*
	Reads next word from file

	@returns next word in a file
	*/
	std::string nextWord();

	/*
	Reads next word from file

	@param word - reference to string that will be filled
	@returns true if word was read
	*/
	bool nextWord(std::string& word);

private:
	const std::string mFileName;
	std::ifstream mStream;
};

}