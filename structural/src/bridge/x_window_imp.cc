// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "x_window_imp.h"

#include <sstream>

namespace structural
{
namespace bridge
{
XWindowImp::XWindowImp() : text_("") { }

void XWindowImp::DeviceText(const std::string& text, float, float)
{
	std::ostringstream stream;
	stream << "<X|" << text << "|X>";
	text_ = stream.str();
}

void XWindowImp::DeviceRect(float x0, float y0, float x1, float y1) { }

std::string XWindowImp::text() const
{
	return text_;
}
}}
