// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_BRIDGE_WINDOW_INTERFACE_H_
#define STRUCTURAL_BRIDGE_WINDOW_INTERFACE_H_

#include "../../../Foundation/src/point.h"

namespace structural
{
	class WindowInterface
	{
	public:
		virtual ~WindowInterface()
		{
		}

		virtual void DrawRect(const foundation::Point<float>& p1, const foundation::Point<float>& p2) = 0;
		virtual void DrawText(const std::string& text, const foundation::Point<float>&) = 0;
	};
}

#endif
