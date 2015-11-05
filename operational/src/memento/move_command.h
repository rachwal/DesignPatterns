// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_MEMENTO_MOVE_COMMAND_H_
#define OPERATIONAL_MEMENTO_MOVE_COMMAND_H_

#include "constraint_solver_interface.h"

namespace operational
{
namespace memento
{
class MoveCommand
{
	public:
	MoveCommand(ConstraintSolverInterface* solver, Graphic* target, const structural::commons::Point<float>& delta);
	void Execute();
	void Unexecute();

	private:
	ConstraintSolverInterface* solver_;
	ConstraintSolverMemento* state_;
	structural::commons::Point<float> delta_;
	Graphic* target_;
};
}
}

#endif

