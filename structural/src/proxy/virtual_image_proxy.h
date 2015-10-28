// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_PROXY_VIRTUAL_IMAGE_PROXY_H_
#define STRUCTURAL_PROXY_VIRTUAL_IMAGE_PROXY_H_

#include "image.h"

namespace structural
{
	class VirtualImageProxy
	{
	public:
		explicit VirtualImageProxy(const std::string& imageFile);
		virtual ~VirtualImageProxy();

		virtual Image* operator->();
		virtual Image& operator*();

	private:
		Image* LoadImage();
		Image* image_;
		std::string image_file_;
	};
}

#endif
