// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_OBSERVER_OBSERVER_WIDGET_INTERFACE_H_
#define OPERATIONAL_OBSERVER_OBSERVER_WIDGET_INTERFACE_H_

namespace operational
{
namespace observer
{
class ObserverWidgetInterface
{
	public:
	virtual ~ObserverWidgetInterface() { }

	virtual void Draw() = 0;
};
}}

#endif
