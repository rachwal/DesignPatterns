// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "move_command.h"

namespace operational
{
namespace memento
{
MoveCommand::MoveCommand(ConstraintSolverInterface* solver, Graphic* target, const structural::commons::Point<float>& delta) : solver_(solver), state_(nullptr), delta_(delta), target_(target) {}

void MoveCommand::Execute()
{
	state_ = solver_->CreateMemento();
	target_->Move(delta_);
	solver_->Solve();
}

void MoveCommand::Unexecute()
{
	target_->Move(-delta_);
	solver_->SetMemento(state_);
	solver_->Solve();
}
}
}

