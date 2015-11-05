// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "text_view.h"

namespace structural
{
namespace adapter
{
TextView::TextView() : TextView("") { }

TextView::TextView(const std::string& text) : content_(text), x_(0), y_(0), width_(10), height_(1) { }

TextView::~TextView() { }

void TextView::Draw() { }

void TextView::Resize() { }

void TextView::GetOrigin(float& x, float& y) const
{
	x = x_;
	y = y_;
}

void TextView::SetOrigin(const float& x, const float& y)
{
	x_ = x;
	y_ = y;
}

void TextView::GetExtent(float& width, float& height) const
{
	width = width_;
	height = height_;
}

void TextView::SetExtent(const float& width, const float& height)
{
	width_ = width;
	height_ = height;
}

bool TextView::IsEmpty() const
{
	return content_ == "";
}

std::string TextView::content() const
{
	return content_;
}

void TextView::content(const std::string& text)
{
	content_ = text;
}
}
}

