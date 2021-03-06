// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_BRIDGE_X_WINDOW_IMP_H_
#define STRUCTURAL_BRIDGE_X_WINDOW_IMP_H_

#include "window_imp.h"

#include <string>

namespace structural
{
namespace bridge
{
class XWindowImp : public WindowImp
{
	public:
	XWindowImp();

	virtual void DeviceText(const std::string& text, float, float) override;
	virtual void DeviceRect(float, float, float, float) override;

	std::string text() const;

	private:
	std::string text_;
};
}
}

#endif

