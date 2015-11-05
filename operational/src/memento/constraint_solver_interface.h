// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_MEMENTO_CONSTRAINT_SOLVER_INTERFACE_H_
#define OPERATIONAL_MEMENTO_CONSTRAINT_SOLVER_INTERFACE_H_

#include "constraint_solver_memento.h"
#include "graphic.h"

namespace operational
{
namespace memento
{
class ConstraintSolverInterface
{
	public:
	virtual ~ConstraintSolverInterface() { }

	virtual void Solve() = 0;
	virtual void AddConstraint(Graphic* startConnection, Graphic* endConnection) = 0;
	virtual void RemoveConstraint(Graphic* startConnection, Graphic* endConnection) = 0;
	virtual ConstraintSolverMemento *CreateMemento() = 0;
	virtual void SetMemento(ConstraintSolverMemento*) = 0;
};
}
}

#endif

