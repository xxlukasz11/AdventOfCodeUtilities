#pragma once

#include <vector>
#include <sstream>

namespace common {

constexpr char SPACE = ' ';

/*
Creates aggregates directly from string.
String must contain delimited words that can be converted to specified types

Example:
auto factory = AggregateFactory<MyClass>(delimiter);
auto aggregate = factory.create<int, char, std::string>(line)
*/
template<typename AggregateType>
class AggregateFactory {
private:
	using StreamType = std::istringstream;
	void ignoreDelimiter(StreamType& stream);

	char delimiter;

public:
	AggregateFactory();
	AggregateFactory(char delimiter);

	// Creates Aggregate from given line. Template arguments are fields of the aggregate
	template<typename... Args>
	AggregateType create(const std::string& line);

	template<typename First>
	AggregateType createAggregate(StreamType& stream);

	template<typename First, typename Second>
	AggregateType createAggregate(StreamType& stream);

	template<typename First, typename Second, typename Third>
	AggregateType createAggregate(StreamType& stream);

};

template<typename AggregateType>
template<typename... Args>
inline AggregateType AggregateFactory<AggregateType>::create(const std::string& line) {
	constexpr int parameterPackSize = sizeof...(Args);
	static_assert(parameterPackSize <= 3, "Maximum number of template arguments is 3");
	StreamType stream(line);
	AggregateType aggregate = createAggregate<Args...>(stream);
	return aggregate;
}

template<typename AggregateType>
template<typename First>
inline AggregateType AggregateFactory<AggregateType>::createAggregate(StreamType& stream) {
	First first;
	stream >> first;
	return AggregateType{ first };
}

template<typename AggregateType>
template<typename First, typename Second>
inline AggregateType AggregateFactory<AggregateType>::createAggregate(StreamType& stream) {
	First first;
	stream >> first;
	ignoreDelimiter(stream);
	Second second;
	stream >> second;
	return AggregateType{ first, second };
}

template<typename AggregateType>
template<typename First, typename Second, typename Third>
inline AggregateType AggregateFactory<AggregateType>::createAggregate(StreamType& stream) {
	First first;
	stream >> first;
	ignoreDelimiter(stream);
	Second second;
	stream >> second;
	ignoreDelimiter(stream);
	Third third;
	stream >> third;
	return AggregateType{ first, second, third };
}

template<typename AggregateType>
inline void AggregateFactory<AggregateType>::ignoreDelimiter(StreamType& stream) {
	if (stream.peek() == delimiter) {
		stream.ignore();
	}
}

template<typename AggregateType>
inline AggregateFactory<AggregateType>::AggregateFactory() : delimiter(SPACE) {
}

template<typename AggregateType>
inline AggregateFactory<AggregateType>::AggregateFactory(char delimiter) : delimiter(delimiter) {
}

}