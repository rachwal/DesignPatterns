// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_ADAPTER_TEXT_SHAPE_CLASS_ADAPTER_H_
#define STRUCTURAL_ADAPTER_TEXT_SHAPE_CLASS_ADAPTER_H_

#include "shape_interface.h"
#include "text_view.h"

namespace structural
{
namespace adapter
{
class TextShapeClassAdapter : public TextView, public ShapeInterface
{
	public:
	explicit TextShapeClassAdapter(const std::string& text);
	TextShapeClassAdapter();

	virtual void BoundingBox(commons::Point<float>& bottom_left, commons::Point<float>& top_right) const override;

	virtual bool IsEmpty() const override;
};
}
}

#endif

