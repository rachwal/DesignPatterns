// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEPARTS_TWISTY_TURNY_PASSAGE_H_
#define CREATIONAL_MAZEPARTS_TWISTY_TURNY_PASSAGE_H_

#include "room.h"

namespace creational
{
namespace commons
{
class TwistyTurnyPassage : public Room
{
	public:
	TwistyTurnyPassage();

	virtual void Enter() override;
	virtual bool entered() const override;

	private:
	bool entered_;
};
}}

#endif
