// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_ADAPTER_TEXT_VIEW_H_
#define STRUCTURAL_ADAPTER_TEXT_VIEW_H_

#include <string>

#include "visual_component_interface.h"

namespace structural
{
	class TextView :public VisualComponentInterface
	{
	public:
		TextView();
		explicit TextView(const std::string& text);
		virtual ~TextView() override;

		void Draw() override;
		void Resize() override;

		void GetOrigin(float& x, float& y) const;
		void SetOrigin(const float& x, const float& y);

		void GetExtent(float& width, float& height) const;
		void SetExtent(const float& width, const float& height);

		virtual bool IsEmpty() const;
		std::string content() const;
		void content(const std::string& text);

	private:
		std::string content_;
		float x_;
		float y_;
		float width_;
		float height_;
	};
}

#endif
