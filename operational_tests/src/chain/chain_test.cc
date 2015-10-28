// Created by Bartosz Rachwal. 
// Copyright (c) 2015 Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan. All rights reserved.

#include <CppUnitTest.h>

#include "../../../Operational/src/chain/chain_button.h"
#include "../../../Operational/src/chain/dialog.h"
#include "../../../Operational/src/chain/chain_application.h"

namespace operationaltests
{
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;
	using namespace operational;

	TEST_CLASS(ChainTest)
	{
	public:
		ChainTest()
		{
		}

		~ChainTest()
		{
		}

		TEST_METHOD(ShouldFail_ChainTest)
		{
			//GIVEN
			const auto PRINT_TOPIC = 1;
			const auto PAPER_ORIENTATION_TOPIC = 2;
			const auto APPLICATION_TOPIC = 3;

			auto application = new ChainApplication(APPLICATION_TOPIC);
			auto dialog = new Dialog(application, PRINT_TOPIC);
			auto button = new ChainButton(dialog, PAPER_ORIENTATION_TOPIC);

			//WHEN
			auto before_help = button->HasHelp();

			button->HandleHelp();

			auto has_help = button->HasHelp();
		

			//THEN
			Assert::Fail();
		}
	};
}
