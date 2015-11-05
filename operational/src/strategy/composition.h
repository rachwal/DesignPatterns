// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_STRATEGY_COMPOSITION_H_
#define OPERATIONAL_STRATEGY_COMPOSITION_H_

#include "compositor_interface.h"

namespace operational
{
namespace strategy
{
class Composition
{
	public:
	explicit Composition(CompositorInterface* compositor);
	void Repair();

	int break_count() const;

	private:
	CompositorInterface* compositor_;

	int line_width_;
	int line_breaks_;
	int line_count_;
	int break_count_;
};
}
}

#endif

