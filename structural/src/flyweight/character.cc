// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "character.h"

namespace structural
{
	Character::Character(char code) :charcode_(code)
	{
	}

	void Character::SetFont(Font* font, GlyphContext& context)
	{
		context.SetFont(font);
	}

	Font* Character::GetFont(GlyphContext& context)
	{
		return context.GetFont();
	}

	void Character::First(GlyphContext& context)
	{
		context.First();
	}

	void Character::Next(GlyphContext& context)
	{
		context.Next();
	}

	bool Character::IsDone(GlyphContext& context)
	{
		return context.IsDone();
	}

	GlyphInterface* Character::Current(GlyphContext&)
	{
		return nullptr;
	}

	void Character::Insert(GlyphInterface*, GlyphContext&)
	{
	}

	void Character::Remove(GlyphContext&)
	{
	}

	void Character::Draw(Window*, GlyphContext&)
	{
	}
}
