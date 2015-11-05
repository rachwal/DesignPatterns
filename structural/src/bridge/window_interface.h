// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_BRIDGE_WINDOW_INTERFACE_H_
#define STRUCTURAL_BRIDGE_WINDOW_INTERFACE_H_

#include "../commons/point.h"

namespace structural
{
namespace bridge
{
class WindowInterface
{
	public:
	virtual ~WindowInterface() { }

	virtual void DrawRect(const commons::Point<float>& p1, const commons::Point<float>& p2) = 0;
	virtual void DrawText(const std::string& text, const commons::Point<float>&) = 0;
};
}
}

#endif

