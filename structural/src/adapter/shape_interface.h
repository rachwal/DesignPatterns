// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_ADAPTER_SHAPE_INTERFACE_H_
#define STRUCTURAL_ADAPTER_SHAPE_INTERFACE_H_

#include "../../../foundation/src/point.h"

namespace structural
{
	class ShapeInterface
	{
	public:
		virtual ~ShapeInterface()
		{
		}

		virtual void BoundingBox(foundation::Point<float>& bottom_left, foundation::Point<float>& top_right) const = 0;
	};
}

#endif
