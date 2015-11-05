// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "composition.h"

namespace operational
{
namespace strategy
{
Composition::Composition(CompositorInterface* compositor) : compositor_(compositor), line_width_(1), line_breaks_(2), line_count_(3), break_count_(0) {}

void Composition::Repair()
{
	float* natural;
	float* stretchability;
	float* shrinkability;
	int component_count;
	int* breaks;

	float coords[] = {1, 2, 3};
	int b[] = {1, 2, 2};

	natural = coords;
	stretchability = coords;
	shrinkability = coords;
	component_count = 1;
	breaks = b;

	break_count_ = compositor_->Compose(natural, stretchability, shrinkability, component_count, line_width_, breaks);
}

int Composition::break_count() const
{
	return break_count_;
}
}
}

