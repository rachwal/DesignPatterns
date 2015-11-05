// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "graphic.h"

namespace operational
{
namespace memento
{
Graphic::Graphic() : Graphic("") {}

Graphic::Graphic(std::string id) : id_(id)
{
	point_ = structural::commons::Point<float>();
}

void Graphic::Move(const structural::commons::Point<float>& point)
{
	point_ += point;
}

std::string Graphic::id() const
{
	return id_;
}

const structural::commons::Point<float> &Graphic::point() const
{
	return point_;
}

void Graphic::point(const structural::commons::Point<float>& point)
{
	point_ = structural::commons::Point<float>(point);
}
}
}

