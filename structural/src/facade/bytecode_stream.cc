#include "bytecode_stream.h"

namespace structural
{
namespace facade
{
BytecodeStream::BytecodeStream() :text_("") { }

void BytecodeStream::Write(std::string text)
{
	text_.append(text);
}

std::string BytecodeStream::Read() const
{
	return text_;
}
}}
