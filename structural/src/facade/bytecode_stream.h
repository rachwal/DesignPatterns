// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FACADE_BYTECODE_STREAM_H_
#define STRUCTURAL_FACADE_BYTECODE_STREAM_H_

#include <string>

namespace structural
{
namespace facade
{
class BytecodeStream
{
	public:
	BytecodeStream();

	void Write(std::string text);
	std::string Read() const;

	private:
	std::string text_;
};
}
}

#endif

