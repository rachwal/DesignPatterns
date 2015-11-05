// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "window.h"
#include "window_imp.h"

namespace structural
{
namespace bridge
{
Window::Window(WindowImp* imp) : imp_(imp) { }

Window::~Window()
{
	delete imp_;
}

void Window::DrawRect(const commons::Point<float>& p1, const commons::Point<float>& p2)
{
	auto imp = GetWindowImp();
	imp->DeviceRect(p1.x(), p1.y(), p2.x(), p2.y());
}

WindowImp *Window::GetWindowImp() const
{
	return imp_;
}
}
}

