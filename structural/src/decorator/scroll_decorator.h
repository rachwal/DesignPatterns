#ifndef DESIGNPATTERNS_DECORATOR_SCROLL_DECORATOR_H_
#define DESIGNPATTERNS_DECORATOR_SCROLL_DECORATOR_H_

#include "decorator.h"

namespace structural
{
	class ScrollDecorator : public Decorator
	{
	public:
		explicit ScrollDecorator(VisualComponentInterface*);
	};
}

#endif
