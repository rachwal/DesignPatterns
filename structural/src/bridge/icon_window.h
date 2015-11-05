// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_BRIDGE_ICON_WINDOW_H_
#define STRUCTURAL_BRIDGE_ICON_WINDOW_H_

#include "window.h"
#include "bitmap.h"

namespace structural
{
namespace bridge
{
class IconWindow : public Window
{
	public:
	IconWindow(const std::string& bitmap_name, WindowImp* imp);
	~IconWindow() override;

	void DrawText(const std::string& text, const commons::Point<float>&) override;
	void DrawIcon() const;

	private:
	Bitmap* bitmap_;
};
}
}

#endif

