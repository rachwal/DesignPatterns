// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Operational/src/memento/constraint_solver.h"
#include "../../../Operational/src/memento/move_command.h"

namespace operationaltests
{
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace operational::memento;

TEST_CLASS(MementoTest)
{
	public:
	MementoTest() { }

	~MementoTest() { }

	TEST_METHOD(ShouldCreateDefalutGraphic)
	{
		//GIVEN
		auto default_point = new structural::commons::Point<float>();

		//WHEN
		auto graphic = new Graphic();

		//THEN
		auto point = graphic->point();

		Assert::IsTrue(*default_point == point);

		delete graphic;
		delete default_point;
	}

	TEST_METHOD(ShouldMoveGraphictoPoint)
	{
		//GIVEN
		auto expected_point = new structural::commons::Point<float>(10, 12);
		auto graphic = new Graphic("test graphic");

		//WHEN
		graphic->Move(structural::commons::Point<float>(10, 12));

		//THEN
		auto point = graphic->point();

		Assert::IsTrue(*expected_point == point);

		delete graphic;
		delete expected_point;
	}

	TEST_METHOD(ShouldUpdateConnectedPointsAfterTransformation)
	{
		//GIVEN
		auto solver = ConstraintSolver::Instance();

		auto test_graphic = new Graphic("test graphic");
		auto test_graphic_point = structural::commons::Point<float>(1, 2);
		test_graphic->point(test_graphic_point);

		auto connected_graphic = new Graphic("connected graphic");
		auto connected_graphic_point = structural::commons::Point<float>(10, 5);
		connected_graphic->point(connected_graphic_point);

		solver->AddConstraint(test_graphic, connected_graphic);
		auto transformation_point = structural::commons::Point<float>(-1, 1);
		auto command = new MoveCommand(solver, test_graphic, transformation_point);

		//WHEN
		command->Execute();

		//THEN
		auto expected_test_graphic_point = structural::commons::Point<float>(0, 3);
		auto expected_connected_graphic_point = structural::commons::Point<float>(9, 6);

		auto transformed_test_graphic_point = test_graphic->point();
		auto transformed_connected_graphic_point = connected_graphic->point();

		Assert::IsTrue(expected_test_graphic_point == transformed_test_graphic_point);
		Assert::IsTrue(expected_connected_graphic_point == transformed_connected_graphic_point);

		delete command;
	}

	TEST_METHOD(ShouldRestorePositionOfGraphics)
	{
		//GIVEN
		auto solver = ConstraintSolver::Instance();

		auto test_graphic = new Graphic("test graphic");
		auto test_graphic_point = structural::commons::Point<float>(1, 2);
		test_graphic->point(test_graphic_point);

		auto connected_graphic = new Graphic("connected graphic");
		auto connected_graphic_point = structural::commons::Point<float>(10, 5);
		connected_graphic->point(connected_graphic_point);

		solver->AddConstraint(test_graphic, connected_graphic);
		auto transformation_point = structural::commons::Point<float>(-1, 1);
		auto command = new MoveCommand(solver, test_graphic, transformation_point);

		command->Execute();

		//WHEN
		command->Unexecute();

		//THEN
		auto transformed_test_graphic_point = test_graphic->point();
		auto transformed_connected_graphic_point = connected_graphic->point();

		Assert::IsTrue(test_graphic_point == transformed_test_graphic_point);
		Assert::IsTrue(connected_graphic_point == transformed_connected_graphic_point);

		delete command;
	}

	TEST_METHOD(ShouldRemoveConstraint)
	{
		//GIVEN
		auto solver = ConstraintSolver::Instance();

		auto test_graphic = new Graphic("test graphic");
		auto test_graphic_point = structural::commons::Point<float>(1, 2);
		test_graphic->point(test_graphic_point);

		auto connected_graphic = new Graphic("connected graphic");
		auto connected_graphic_point = structural::commons::Point<float>(10, 5);
		connected_graphic->point(connected_graphic_point);

		solver->AddConstraint(test_graphic, connected_graphic);
		auto transformation_point = structural::commons::Point<float>(-1, 1);
		auto command = new MoveCommand(solver, test_graphic, transformation_point);

		//WHEN
		solver->RemoveConstraint(test_graphic, connected_graphic);

		command->Execute();

		//THEN
		auto expected_test_graphic_point = structural::commons::Point<float>(0, 3);

		auto transformed_test_graphic_point = test_graphic->point();
		auto transformed_connected_graphic_point = connected_graphic->point();

		Assert::IsTrue(expected_test_graphic_point == transformed_test_graphic_point);
		Assert::IsTrue(connected_graphic_point == transformed_connected_graphic_point);

		delete command;
	}
};
}

