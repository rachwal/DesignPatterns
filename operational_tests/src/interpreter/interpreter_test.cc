// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Operational/src/interpreter/boolean_exp_interface.h"
#include "../../../Operational/src/interpreter/interpreter_context.h"
#include "../../../Operational/src/interpreter/or_exp.h"
#include "../../../Operational/src/interpreter/and_exp.h"
#include "../../../Operational/src/interpreter/constant.h"
#include "../../../Operational/src/interpreter/not_exp.h"
#include "../../../Operational/src/interpreter/variable_exp.h"

namespace operationaltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace operational::interpreter;

TEST_CLASS(InterpreterTest)
{
	public:
	InterpreterTest() { }

	~InterpreterTest() { }

	TEST_METHOD(ShouldCreateConstantWithFalseValue)
	{
		//GIVEN
		InterpreterContext context;

		//WHEN
		auto x = new Constant(false);

		//THEN
		auto result = x->Evaluate(context);

		Assert::IsFalse(result);

		delete x;
	}

	TEST_METHOD(ShouldCreateConstantWithTrueValue)
	{
		//GIVEN
		InterpreterContext context;

		//WHEN
		auto x = new Constant(true);

		//THEN
		auto result = x->Evaluate(context);

		Assert::IsTrue(result);

		delete x;
	}

	TEST_METHOD(ShouldCreateDefaultVariable)
	{
		//GIVEN
		InterpreterContext context;

		//WHEN
		auto x = new VariableExp("X");

		//THEN
		auto result = x->Evaluate(context);

		Assert::IsFalse(result);

		delete x;
	}

	TEST_METHOD(ShouldAssignTrueValueToVariable)
	{
		//GIVEN
		InterpreterContext context;

		auto x = new VariableExp("X");

		//WHEN
		context.Assign(x, true);

		//THEN
		auto result = x->Evaluate(context);

		Assert::IsTrue(result);

		delete x;
	}

	TEST_METHOD(ShouldAssignFalseValueToVariable)
	{
		//GIVEN
		InterpreterContext context;

		auto x = new VariableExp("X");

		//WHEN
		context.Assign(x, false);

		//THEN
		auto result = x->Evaluate(context);

		Assert::IsFalse(result);

		delete x;
	}

	TEST_METHOD(ShouldEvaluateNotExpressionWithTrueVariableValue)
	{
		//GIVEN
		InterpreterContext context;

		auto x = new VariableExp("X");
		auto not_x = new NotExp(x);

		//WHEN
		context.Assign(x, true);

		//THEN
		auto result = not_x->Evaluate(context);

		Assert::IsFalse(result);

		delete not_x;
	}

	TEST_METHOD(ShouldEvaluateNotExpressionWithFalseVariableValue)
	{
		//GIVEN
		InterpreterContext context;

		auto x = new VariableExp("X");
		auto not_x = new NotExp(x);

		//WHEN
		context.Assign(x, false);

		//THEN
		auto result = not_x->Evaluate(context);

		Assert::IsTrue(result);

		delete not_x;
	}

	TEST_METHOD(ShouldReplaceValueWithNotExpression)
	{
		//GIVEN
		InterpreterContext context;

		auto x = new VariableExp("X");
		context.Assign(x, false);

		auto z = new VariableExp("Z");
		auto not_z = new NotExp(z);

		BooleanExpInterface* expression = new NotExp(x);

		//WHEN
		auto replacement = expression->Replace("X", *not_z);
		context.Assign(z, true);

		//THEN
		auto result = replacement->Evaluate(context);

		Assert::IsTrue(result);

		delete expression;
		delete not_z;
	}

	TEST_METHOD(ShouldPassFirstInterpreterBookTestCase)
	{
		// expression ::= (true && x) || (y && !x)
		// x ::= false
		// y ::= true
		// expression == true

		//GIVEN
		auto x = new VariableExp("X");
		auto y = new VariableExp("Y");

		BooleanExpInterface* expression = new OrExp(new AndExp(new Constant(true), x), new AndExp(y, new NotExp(x)));
		InterpreterContext context;

		//WHEN
		context.Assign(x, false);
		context.Assign(y, true);

		//THEN
		auto result = expression->Evaluate(context);
		Assert::IsTrue(result);

		delete expression;
	}


	TEST_METHOD(ShouldPassSecondInterpreterBookTestCase)
	{
		// expression ::= (true && x) || (!z && !x)
		// x ::= false
		// z ::= true
		// expression == false

		//GIVEN
		auto x = new VariableExp("X");
		auto y = new VariableExp("Y");

		BooleanExpInterface* expression = new OrExp(new AndExp(new Constant(true), x), new AndExp(y, new NotExp(x)));
		InterpreterContext context;

		context.Assign(x, false);
		context.Assign(y, true);

		//WHEN
		auto z = new VariableExp("Z");
		auto not_z = new NotExp(z);

		auto replacement = expression->Replace("Y", *not_z);
		context.Assign(z, true);

		//THEN
		auto result = replacement->Evaluate(context);
		Assert::IsFalse(result);

		delete expression;
		delete not_z;
	}
};
}

