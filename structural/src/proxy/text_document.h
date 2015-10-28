// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_PROXY_TEXT_DOCUMENT_H_
#define STRUCTURAL_PROXY_TEXT_DOCUMENT_H_

#include "graphic_interface.h"

namespace structural
{
	class TextDocument
	{
	public:
		TextDocument();

		void Insert(GraphicInterface*);
		const foundation::Point<float>& GetExtent();

	private:
		GraphicInterface* graphic_;
		foundation::Point<float> extent_;
	};
}

#endif
