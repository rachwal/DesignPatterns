// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "virtual_image_proxy.h"

namespace structural
{
namespace proxy
{
VirtualImageProxy::VirtualImageProxy(const std::string& image_file)
{
	image_file_ = image_file;
	image_ = nullptr;
}

VirtualImageProxy::~VirtualImageProxy() { }

extern Image *LoadAnImageFile(const char* image_file)
{
	return new Image(image_file);
};

Image *VirtualImageProxy::LoadImage()
{
	if (image_ == nullptr)
	{
		image_ = LoadAnImageFile(image_file_.c_str());
	}
	return image_;
}

Image *VirtualImageProxy::operator->()
{
	return LoadImage();
}

Image &VirtualImageProxy::operator*()
{
	return *LoadImage();
}
}
}

