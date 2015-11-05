// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_MEMENTO_CONSTRAINT_SOLVER_H_
#define OPERATIONAL_MEMENTO_CONSTRAINT_SOLVER_H_

#include "constraint_solver_interface.h"

namespace operational
{
namespace memento
{
class ConstraintSolver : public ConstraintSolverInterface
{
	public:
	static ConstraintSolver *Instance();

	virtual void Solve() override;

	virtual void AddConstraint(Graphic* startConnection, Graphic* endConnection) override;
	virtual void RemoveConstraint(Graphic* startConnection, Graphic* endConnection) override;

	virtual ConstraintSolverMemento *CreateMemento() override;
	virtual void SetMemento(ConstraintSolverMemento*) override;

	private:
	ConstraintSolver();

	static ConstraintSolver* instance_;
	ConstraintSolverMemento* memento_;
};
}
}

#endif

