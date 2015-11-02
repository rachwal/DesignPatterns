// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_PROXY_GRAPHIC_H_
#define STRUCTURAL_PROXY_GRAPHIC_H_

#include "event.h"

#include <iostream>

#include "../commons/point.h"

namespace structural
{
namespace proxy
{
class GraphicInterface
{
	public:
	virtual ~GraphicInterface() { }

	virtual void Draw(const commons::Point<float>& at) = 0;
	virtual void HandleMouse(Event& event) = 0;
	virtual const commons::Point<float> &GetExtent() = 0;
	virtual void Load(std::istream& from) = 0;
	virtual void Save(std::ostream& to) = 0;
};
}}

#endif
