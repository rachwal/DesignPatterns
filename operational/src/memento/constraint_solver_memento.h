// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_MEMENTO_CONSTRAINT_SOLVER_MEMENTO_H_
#define OPERATIONAL_MEMENTO_CONSTRAINT_SOLVER_MEMENTO_H_

#include "graphic.h"

#include <map>

#include "../iterator/list.h"

namespace operational
{
namespace memento
{
class ConstraintSolverMemento
{
	public:
	virtual ~ConstraintSolverMemento();

	private:
	friend class ConstraintSolver;
	ConstraintSolverMemento();
	ConstraintSolverMemento(const ConstraintSolverMemento&);

	void AddConstraint(Graphic* start, Graphic* end);
	void RemoveConstraint(Graphic* start, Graphic* end);

	std::map<Graphic*, iterator::List<Graphic*>*> constrains_;
	std::map<Graphic*, structural::commons::Point<float>> transformations_;
};
}
}

#endif

