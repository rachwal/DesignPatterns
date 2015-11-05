// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Structural/src/decorator/compressing_stream.h"
#include "../../../Structural/src/decorator/ascii7_stream.h"
#include "../../../Structural/src/decorator/file_stream.h"

namespace structuraltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace structural::decorator;

TEST_CLASS(DecoratorTest)
{
	public:
	DecoratorTest() { }

	~DecoratorTest() { }

	TEST_METHOD(ShouldReturnGivenValueIncreasedByNumberOfDecoratorsUsed)
	{
		//GIVEN
		auto expected_value = 3;
		auto file_stream = new FileStream();

		//WHEN
		StreamInterface* stream = new CompressingStream(new ASCII7Stream(file_stream));

		stream->PutInt(0);

		//THEN
		auto value = file_stream->value();

		Assert::AreEqual(expected_value, value);

		delete stream;
	}

	TEST_METHOD(ShouldReturnDecoratedText)
	{
		//GIVEN
		auto expected_message = "<FileStream|test|FileStream>";
		auto file_stream = new FileStream();

		//WHEN
		file_stream->PutString("test");

		//THEN
		auto text = file_stream->message();

		Assert::AreEqual(expected_message, text.c_str());

		delete file_stream;
	}

	TEST_METHOD(ShouldReturnTextDecoratedByThreeObjectsDecorated)
	{
		//GIVEN
		auto expected_message = "<FileStream|<ASCII7Stream|<CompressingStream|test|CompressingStream>|ASCII7Stream>|FileStream>";
		auto file_stream = new FileStream();

		//WHEN
		StreamInterface* stream = new CompressingStream(new ASCII7Stream(file_stream));

		stream->PutString("test");

		//THEN
		auto text = file_stream->message();

		Assert::AreEqual(expected_message, text.c_str());

		delete stream;
	}
};
}

