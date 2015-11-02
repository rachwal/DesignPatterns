// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_PROXY_IMAGE_H_
#define STRUCTURAL_PROXY_IMAGE_H_

#include "event.h"
#include "graphic_interface.h"

#include "../commons/point.h"

namespace structural
{
namespace proxy
{
class Image : public GraphicInterface
{
	public:
	explicit Image(const std::string& file_name);
	virtual ~Image();

	virtual void Draw(const commons::Point<float>& at) override;
	virtual void HandleMouse(Event& event) override;
	virtual void Load(std::istream& from) override;
	virtual void Save(std::ostream& to) override;
	const commons::Point<float> &GetExtent() override;

	private:
	commons::Point<float> extent_;
};
}}

#endif
