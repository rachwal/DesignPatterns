// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_ADAPTER_VISUAL_COMPONENT_INTERFACE_H_
#define STRUCTURAL_ADAPTER_VISUAL_COMPONENT_INTERFACE_H_

namespace structural
{
	class VisualComponentInterface
	{
	public:
		virtual ~VisualComponentInterface()
		{
		}

		virtual void Draw() = 0;
		virtual void Resize() = 0;
	};
}

#endif
