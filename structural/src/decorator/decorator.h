#ifndef DESIGNPATTERNS_DECORATOR_DECORATOR_H_
#define DESIGNPATTERNS_DECORATOR_DECORATOR_H_

#include "../../../foundation/src/visual_component_interface.h"

namespace structural
{
	class Decorator : public foundation::VisualComponentInterface
	{
	public:
		explicit Decorator(VisualComponentInterface* component_interface);

		virtual void Draw() override;
		virtual void Resize() override;

	private:
		VisualComponentInterface* component_;
	};
}

#endif
