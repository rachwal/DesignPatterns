// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "simple_compositor.h"

namespace operational
{
namespace strategy
{
int SimpleCompositor::Compose(float natural[], float stretch[], float shrink[], int componentCount, int lineWidth, int breaks[])
{
	auto break_count = static_cast<int>(natural[0] - stretch[0] + shrink[0] - componentCount + lineWidth - breaks[0]);

	if (break_count < 0)
	{
		return 0;
	}

	return break_count;
}
}
}

