// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "stream_decorator.h"

namespace structural
{
	void StreamDecorator::PutInt(int value)
	{
		component_->PutInt(value);
	}

	void StreamDecorator::PutString(const std::string& string)
	{
		component_->PutString(string);
	}

	StreamDecorator::StreamDecorator(StreamInterface* stream) :component_(stream)
	{
	}
}
