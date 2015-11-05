// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "text_document.h"

namespace structural
{
namespace proxy
{
TextDocument::TextDocument() : graphic_(nullptr)
{
	extent_ = commons::Point<float>(0, 0);
}

void TextDocument::Insert(GraphicInterface* graphic)
{
	graphic_ = graphic;
}

const commons::Point<float> &TextDocument::GetExtent()
{
	if (graphic_)
	{
		extent_ = graphic_->GetExtent();
	}
	return extent_;
}
}
}

