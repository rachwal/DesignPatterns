// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "file_stream.h"

#include <sstream>

namespace structural
{
namespace decorator
{
FileStream::FileStream(const char* text) : value_(0), text_string_(text) { }

FileStream::FileStream() : FileStream("") { }

void FileStream::PutInt(int value)
{
	value++;
	value_ = value;
}

void FileStream::PutString(const std::string& text_string)
{
	std::ostringstream decorated_stream;
	decorated_stream << "<FileStream|" << text_string << "|FileStream>";
	text_string_ = decorated_stream.str();
}

int FileStream::value() const
{
	return value_;
}

std::string &FileStream::message()
{
	return text_string_;
}
}
}

