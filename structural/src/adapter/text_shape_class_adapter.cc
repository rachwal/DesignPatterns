// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "text_shape_class_adapter.h"

namespace structural
{
namespace adapter
{
TextShapeClassAdapter::TextShapeClassAdapter(const std::string& text) : TextView(text) { }

TextShapeClassAdapter::TextShapeClassAdapter() : TextShapeClassAdapter("") { }

void TextShapeClassAdapter::BoundingBox(commons::Point<float>& bottom_left, commons::Point<float>& top_right) const
{
	float x, y, width, height;

	GetOrigin(x, y);
	GetExtent(width, height);

	bottom_left = commons::Point<float>(x, y);
	top_right = commons::Point<float>(x + width, y + height);
}

bool TextShapeClassAdapter::IsEmpty() const
{
	return TextView::IsEmpty();
}
}}
