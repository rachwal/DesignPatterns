// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "spell.h"

namespace patterns
{
	Spell::Spell(const std::string& message) :message_(message)
	{
	};

	Spell::Spell(const Spell& spell) :message_(spell.message_)
	{
	};

	std::string Spell::message() const
	{
		return message_;
	};
}
