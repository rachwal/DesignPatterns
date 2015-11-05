// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include <algorithm>
#include "p_m_window_imp.h"
#include <sstream>

namespace structural
{
namespace bridge
{
PMWindowImp::PMWindowImp() : text_("") { }

void PMWindowImp::DeviceText(const std::string& text, float, float)
{
	std::ostringstream stream;
	stream << "<PM|" << text << "|PM>";
	text_ = stream.str();
}

void PMWindowImp::DeviceRect(float x0, float y0, float x1, float y1) { }

std::string PMWindowImp::text() const
{
	return text_;
}
}
}

