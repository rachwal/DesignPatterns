// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_PROXY_IMAGE_PROXY_H_
#define STRUCTURAL_PROXY_IMAGE_PROXY_H_

#include "graphic_interface.h"
#include "image.h"

namespace structural
{
	class ImageProxy : public GraphicInterface
	{
	public:
		explicit ImageProxy(const std::string& file_name);
		virtual ~ImageProxy();

		virtual void Draw(const foundation::Point<float>& at) override;
		virtual void HandleMouse(Event& event) override;
		virtual const foundation::Point<float>& GetExtent() override;
		virtual void Load(std::istream& from) override;
		virtual void Save(std::ostream& to) override;

	protected:
		Image* GetImage();

	private:
		const foundation::Point<float> kZeroExtent = foundation::Point<float>(0, 0);
		Image* image_;
		foundation::Point<float> extent_;
		std::string file_name_;
	};
}

#endif
