// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../operational/src/state/tcp_connection.h"

namespace operationaltests
{
using namespace operational::state;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(StateTest)
{
	public:
	StateTest() { }

	~StateTest() { }

	TEST_METHOD(ShouldChangeStatesBetweenClosedAndOpen)
	{
		//GIVEN
		std::string expected_initial_info = "TcpState -> Closed";
		std::string expected_active_open_info = "TcpState -> Established";
		std::string expected_closed_from_active_open_info = "TcpState -> Closed";
		std::string expected_passive_info = "TcpState -> Listen";
		std::string expected_closed_from_passive_open_info = "TcpState -> Closed";

		auto connection = TcpConnection::CreateConnection();
		auto initial_info = connection->Info();

		//WHEN
		connection->ActiveOpen();
		auto active_open_info = connection->Info();

		connection->Close();
		auto closed_from_active_open_info = connection->Info();

		connection->PassiveOpen();
		auto passive_info = connection->Info();

		connection->Close();
		auto closed_from_passive_open_info = connection->Info();

		//THEN
		Assert::AreEqual(0, expected_initial_info.compare(initial_info));
		Assert::AreEqual(0, expected_active_open_info.compare(active_open_info));
		Assert::AreEqual(0, expected_closed_from_active_open_info.compare(closed_from_active_open_info));
		Assert::AreEqual(0, expected_passive_info.compare(passive_info));
		Assert::AreEqual(0, expected_closed_from_passive_open_info.compare(closed_from_passive_open_info));
	}
};
}

