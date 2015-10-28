// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_DECORATOR_COMPRESSING_STREAM_DECORATOR_H_
#define STRUCTURAL_DECORATOR_COMPRESSING_STREAM_DECORATOR_H_

#include "stream_decorator.h"

namespace structural
{
	class CompressingStream : public StreamDecorator
	{
	public:
		explicit CompressingStream(StreamInterface*);

		void PutInt(int) override;
		void PutString(const std::string&) override;

		int value() const;
		std::string& message();

	private:
		int value_;
		std::string text_string_;
	};
}

#endif
