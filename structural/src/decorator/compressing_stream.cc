// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "compressing_stream.h"

#include <sstream>

namespace structural
{
namespace decorator
{
CompressingStream::CompressingStream(StreamInterface* stream) : StreamDecorator(stream), value_(0), text_string_("") { }

void CompressingStream::PutInt(int value)
{
	value++;
	component_->PutInt(value);
}

void CompressingStream::PutString(const std::string& text_string)
{
	std::ostringstream decorated_stream;
	decorated_stream << "<CompressingStream|" << text_string << "|CompressingStream>";
	auto message = decorated_stream.str();

	component_->PutString(message.c_str());
}

int CompressingStream::value() const
{
	return value_;
}

std::string &CompressingStream::message()
{
	return text_string_;
}
}}
