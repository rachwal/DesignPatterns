// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_ADAPTER_TEXT_SHAPE_OBJECT_ADAPTER_H_
#define STRUCTURAL_ADAPTER_TEXT_SHAPE_OBJECT_ADAPTER_H_

#include "shape_interface.h"
#include "text_view.h"

namespace structural
{
	class TextShapeObjectAdapter : public ShapeInterface
	{
	public:
		explicit TextShapeObjectAdapter(TextView*);

		virtual void BoundingBox(foundation::Point<float>& bottom_left, foundation::Point<float>& top_right) const override;

		virtual bool IsEmpty() const;

	private:
		TextView* text_view_;
	};
}

#endif
