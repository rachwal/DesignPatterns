// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "ascii7_stream.h"

#include <sstream>

namespace structural
{
	ASCII7Stream::ASCII7Stream(StreamInterface* stream) :StreamDecorator(stream), value_(0), text_string_("")
	{
	}

	void ASCII7Stream::PutInt(int value)
	{
		value++;
		component_->PutInt(value);
	}

	void ASCII7Stream::PutString(const std::string& text_string)
	{
		std::ostringstream decorated_stream;
		decorated_stream << "<ASCII7Stream|" << text_string << "|ASCII7Stream>";
		text_string_ = decorated_stream.str();

		component_->PutString(text_string_.c_str());
	}

	int ASCII7Stream::value() const
	{
		return value_;
	}

	std::string& ASCII7Stream::message()
	{
		return text_string_;
	}
}
