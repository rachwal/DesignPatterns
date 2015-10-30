// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "bitmap.h"

namespace structural
{
namespace bridge
{
Bitmap::Bitmap(const std::string& file_name)
{
	width_ = 100;
	height_ = 20;
}

float Bitmap::width() const
{
	return width_;
}

float Bitmap::height() const
{
	return height_;
}
}}
