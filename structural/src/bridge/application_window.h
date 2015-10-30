// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_BRIDGE_APPLICATION_WINDOW_H_
#define STRUCTURAL_BRIDGE_APPLICATION_WINDOW_H_

#include "window.h"

namespace structural
{
namespace bridge
{
class ApplicationWindow : public Window
{
	public:
	explicit ApplicationWindow(const std::string& application_title, WindowImp* imp);

	void DrawText(const std::string& text, const foundation::Point<float>&) override;
	void DrawTitle();

	private:
	std::string application_title_;
};
}}

#endif
