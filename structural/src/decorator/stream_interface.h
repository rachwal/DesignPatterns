// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_DECORATOR_STREAM_INTERFACE_H_
#define STRUCTURAL_DECORATOR_STREAM_INTERFACE_H_

#include <string>

namespace structural
{
namespace decorator
{
class StreamInterface
{
	public:
	virtual ~StreamInterface() { }

	virtual void PutInt(int) = 0;
	virtual void PutString(const std::string&) = 0;
};
}
}

#endif

