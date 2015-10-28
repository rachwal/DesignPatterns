#ifndef DESIGNPATTERNS_DECORATOR_BORDER_DECORATOR_H_
#define DESIGNPATTERNS_DECORATOR_BORDER_DECORATOR_H_

#include "decorator.h"

#include "../../../foundation/src/visual_component_interface.h"

namespace structural
{
	class BorderDecorator : public Decorator
	{
	public:
		BorderDecorator(VisualComponentInterface*, int borderWidth);

		virtual void Draw() override;

	private:
		void DrawBorder(int);
		int width_;
	};
}

#endif
