// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "image_proxy.h"

namespace structural
{
	ImageProxy::ImageProxy(const std::string& file_name)
	{
		file_name_ = file_name;
		extent_ = kZeroExtent;
		image_ = nullptr;
	}

	ImageProxy::~ImageProxy()
	{
		delete image_;
	}

	Image* ImageProxy::GetImage()
	{
		if (image_ == nullptr)
		{
			image_ = new Image(file_name_);
		}
		return image_;
	}

	const foundation::Point<float>& ImageProxy::GetExtent()
	{
		if (extent_ == kZeroExtent)
		{
			extent_ = GetImage()->GetExtent();
		}
		return extent_;
	}

	void ImageProxy::Draw(const foundation::Point<float>& at)
	{
		GetImage()->Draw(at);
	}

	void ImageProxy::HandleMouse(Event& event)
	{
		GetImage()->HandleMouse(event);
	}

	void ImageProxy::Save(std::ostream& to)
	{
	}

	void ImageProxy::Load(std::istream& from)
	{
	}
}
