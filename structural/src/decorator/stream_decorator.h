// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_DECORATOR_STREAM_DECORATOR_H_
#define STRUCTURAL_DECORATOR_STREAM_DECORATOR_H_

#include "stream_interface.h"

namespace structural
{
namespace decorator
{
class StreamDecorator : public StreamInterface
{
	public:
	explicit StreamDecorator(StreamInterface*);

	void PutInt(int) override;
	void PutString(const std::string&) override;

	protected:
	StreamInterface* component_;
};
}
}

#endif

