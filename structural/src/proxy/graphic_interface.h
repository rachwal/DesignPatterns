// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_PROXY_GRAPHIC_H_
#define STRUCTURAL_PROXY_GRAPHIC_H_

#include "event.h"

#include <iostream>

#include "../../../foundation/src/point.h"

namespace structural
{
	class GraphicInterface
	{
	public:
		virtual ~GraphicInterface()
		{
		}

		virtual void Draw(const foundation::Point<float>& at) = 0;
		virtual void HandleMouse(Event& event) = 0;
		virtual const foundation::Point<float>& GetExtent() = 0;
		virtual void Load(std::istream& from) = 0;
		virtual void Save(std::ostream& to) = 0;
	};
}

#endif
