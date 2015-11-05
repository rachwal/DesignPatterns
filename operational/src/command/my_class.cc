// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "my_class.h"

namespace operational
{
namespace command
{
MyClass::MyClass() : fired_(false) { }

MyClass::MyClass(bool fired) : fired_(fired) { }

void MyClass::Action()
{
	fired_ = true;
}

bool MyClass::fired() const
{
	return fired_;
}
}
}

