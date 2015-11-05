// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "constraint_solver_memento.h"

namespace operational
{
namespace memento
{
ConstraintSolverMemento::ConstraintSolverMemento()
{
	constrains_ = std::map<Graphic*, iterator::List<Graphic*>*>();
	transformations_ = std::map<Graphic*, structural::commons::Point<float>>();
}

ConstraintSolverMemento::ConstraintSolverMemento(const ConstraintSolverMemento& memento) : constrains_(memento.constrains_), transformations_(memento.transformations_) {}

ConstraintSolverMemento::~ConstraintSolverMemento()
{
	constrains_.erase(constrains_.begin(), constrains_.end());
	transformations_.erase(transformations_.begin(), transformations_.end());
}

void ConstraintSolverMemento::AddConstraint(Graphic* start, Graphic* end)
{
	if (!constrains_[start])
	{
		constrains_[start] = new iterator::List<Graphic*>();
	}

	constrains_[start]->Append(end);
	auto transformation = end->point() - start->point();
	transformations_[end] = transformation;
}

void ConstraintSolverMemento::RemoveConstraint(Graphic* start, Graphic* end)
{
	if (!constrains_[start])
	{
		return;
	}

	constrains_[start]->Remove(end);
	transformations_.erase(end);
}
}
}

