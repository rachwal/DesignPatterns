// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "application_window.h"

namespace structural
{
namespace bridge
{
ApplicationWindow::ApplicationWindow(const std::string& application_title, WindowImp* imp) : Window(imp), application_title_(application_title) { }

void ApplicationWindow::DrawText(const std::string& text, const commons::Point<float>& point)
{
	auto imp = GetWindowImp();
	imp->DeviceText(text, point.x(), point.y());
}

void ApplicationWindow::DrawTitle()
{
	DrawText(application_title_, commons::Point<float>(0, 0));
}
}}
