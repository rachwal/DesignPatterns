// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "scanner.h"

#include <vector>

namespace structural
{
namespace facade
{
Scanner::Scanner(std::istringstream& stream) :input_stream_(stream) { }

Scanner::~Scanner() { }

std::vector<Token*> Scanner::Scan()
{
	std::vector<std::string> words
		{
			std::istream_iterator<std::string>{input_stream_},
			std::istream_iterator<std::string>{}
		};

	auto tokens = std::vector<Token*>();
	for (auto word = words.begin(); word != words.end(); ++word)
	{
		auto token = new Token(*word);
		tokens.push_back(token);
	}

	return tokens;
};
}}
