// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FLYWEIGHT_FONT_H_
#define STRUCTURAL_FLYWEIGHT_FONT_H_

#include <string>

namespace structural
{
namespace flyweight
{
class Font
{
	public:
	explicit Font(const std::string& name);

	std::string name() const;;

	friend bool operator ==(const Font& left_font, const Font& right_font);

	private:
	std::string name_;
};

inline bool operator==(const Font& left_font, const Font& right_font)
{
	auto left_font_name = left_font.name();
	auto right_font_name = right_font.name();
	return left_font_name.compare(right_font_name) == 0;
}
}
}

#endif

