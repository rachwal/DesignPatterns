// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "text_shape_object_adapter.h"

namespace structural
{
namespace adapter
{
TextShapeObjectAdapter::TextShapeObjectAdapter(TextView* text_view) : text_view_(text_view) { }

void TextShapeObjectAdapter::BoundingBox(commons::Point<float>& bottom_left, commons::Point<float>& top_right) const
{
	float x, y, width, height;

	text_view_->GetOrigin(x, y);
	text_view_->GetExtent(width, height);

	bottom_left = commons::Point<float>(x, y);
	top_right = commons::Point<float>(x + width, y + height);
}

bool TextShapeObjectAdapter::IsEmpty() const
{
	return text_view_->IsEmpty();
}
}}
