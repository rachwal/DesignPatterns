// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_BRIDGE_BITMAP_H_
#define STRUCTURAL_BRIDGE_BITMAP_H_

#include <string>

namespace structural
{
namespace bridge
{
class Bitmap
{
	public:
	explicit Bitmap(const std::string& file_name);

	float width() const;
	float height() const;

	private:
	float width_;
	float height_;
};
}}

#endif
