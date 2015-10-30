// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "font.h"

namespace structural
{
namespace flyweight
{
Font::Font(const std::string& name) :name_(name) { }

std::string Font::name() const
{
	return name_;
}
}}
