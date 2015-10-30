// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Structural/src/facade/compiler.h"

#include <sstream>
#include <algorithm>
#include <iterator>

namespace structuraltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace structural::facade;

TEST_CLASS(FacadeTest)
{
	public:
	FacadeTest() { }

	~FacadeTest() { }

	TEST_METHOD(ShouldPassExampleBookFacadeTest)
	{
		//GIVEN
		auto expected_stream = "<RISC|variable|items_|variable|RISC>";
		auto output_stream = BytecodeStream();
		auto input_stream = std::istringstream("auto items_ = new operational::List<ProgramNodeInterface*>();");

		auto compiler = new Compiler();

		//WHEN
		compiler->Compile(input_stream, &output_stream);

		//THEN
		auto output = output_stream.Read();
		Assert::AreEqual(expected_stream, output.c_str());
	}
};
}
