// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "constraint_solver.h"

#include <mutex>

namespace operational
{
namespace memento
{
ConstraintSolver::ConstraintSolver() : memento_(new ConstraintSolverMemento) {}

void ConstraintSolver::Solve()
{
	for (auto transformation = memento_->constrains_.begin(); transformation != memento_->constrains_.end(); ++transformation)
	{
		auto base_element = (*transformation).first;
		auto depentent_elements = (*transformation).second;

		auto iterator = depentent_elements->CreateIterator();

		for (iterator->First(); !iterator->IsDone(); iterator->Next())
		{
			auto current_item = iterator->CurrentItem();
			auto current_transformation = memento_->transformations_[current_item];
			auto new_point = base_element->point() + current_transformation;

			current_item->point(new_point);
		}
		delete iterator;
	}
}

void ConstraintSolver::AddConstraint(Graphic* start, Graphic* end)
{
	memento_->AddConstraint(start, end);
}

void ConstraintSolver::RemoveConstraint(Graphic* start, Graphic* end)
{
	memento_->RemoveConstraint(start, end);
}

ConstraintSolverMemento *ConstraintSolver::CreateMemento()
{
	return new ConstraintSolverMemento(*memento_);
}

void ConstraintSolver::SetMemento(ConstraintSolverMemento* memento)
{
	memento_ = memento;
}

ConstraintSolver* ConstraintSolver::instance_;

ConstraintSolver *ConstraintSolver::Instance()
{
	if (!instance_)
	{
		std::mutex m;
		m.lock();
		if (!instance_)
		{
			auto solver = new ConstraintSolver();
			instance_ = solver;
		}
		m.unlock();
	}
	return instance_;
}
}
}

