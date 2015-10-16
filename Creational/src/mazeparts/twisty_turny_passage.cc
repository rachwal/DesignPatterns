// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "twisty_turny_passage.h"

namespace patterns
{
	TwistyTurnyPassage::TwistyTurnyPassage() : Room(0), entered_(false)
	{
	}

	void TwistyTurnyPassage::Enter()
	{
		entered_ = true;
	}

	bool TwistyTurnyPassage::entered() const
	{
		return entered_;
	}
}
