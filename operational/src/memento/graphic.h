// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_MEMENTO_GRAPHIC_H_
#define OPERATIONAL_MEMENTO_GRAPHIC_H_

#include "../../../Structural/src/commons/point.h"

namespace operational
{
namespace memento
{
class Graphic
{
	public:
	Graphic();
	explicit Graphic(std::string id);

	void Move(const structural::commons::Point<float>&);
	std::string id() const;

	const structural::commons::Point<float> &point() const;
	void point(const structural::commons::Point<float>& point);

	private:
	std::string id_;
	structural::commons::Point<float> point_;
};
}
}

#endif

