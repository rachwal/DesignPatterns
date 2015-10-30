// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "icon_window.h"
#include "bitmap.h"

namespace structural
{
namespace bridge
{
IconWindow::IconWindow(const std::string& bitmap_name, WindowImp* imp) :Window(imp), bitmap_(new Bitmap(bitmap_name)) { }

IconWindow::~IconWindow()
{
	delete bitmap_;
}

void IconWindow::DrawText(const std::string& text, const foundation::Point<float>& point)
{
	auto imp = GetWindowImp();
	imp->DeviceText(text, point.x(), point.y());
}

void IconWindow::DrawIcon()
{
	auto imp = GetWindowImp();
	imp->DeviceRect(0, 0, bitmap_->width(), bitmap_->height());
}
}}
