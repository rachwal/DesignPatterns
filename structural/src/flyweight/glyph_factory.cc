// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "glyph_factory.h"

namespace structural
{
namespace flyweight
{
GlyphFactory::GlyphFactory()
{
	for (auto i = 0; i < kNumberCharCodes; ++i)
	{
		character_[i] = nullptr;
	}
}

GlyphFactory::~GlyphFactory() { }

Character *GlyphFactory::CreateCharacter(char c)
{
	if (!character_[c])
	{
		character_[c] = new Character(c);
	}

	return character_[c];
}

Row *GlyphFactory::CreateRow()
{
	return new Row;
}

Column *GlyphFactory::CreateColumn()
{
	return new Column;
}
}
}

