// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FLYWEIGHT_GLYPH_FACTORY_H_
#define STRUCTURAL_FLYWEIGHT_GLYPH_FACTORY_H_

#include "character.h"
#include "column.h"
#include "row.h"

namespace structural
{
namespace flyweight
{
class GlyphFactory
{
	public:
	GlyphFactory();
	virtual ~GlyphFactory();

	virtual Character *CreateCharacter(char);
	virtual Row *CreateRow();
	virtual Column *CreateColumn();

	private:
	static const int kNumberCharCodes = 128;

	Character* character_[kNumberCharCodes];
};
}}

#endif
