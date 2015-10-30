// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FLYWEIGHT_CHARACTER_H_
#define STRUCTURAL_FLYWEIGHT_CHARACTER_H_

#include "glyph_interface.h"

namespace structural
{
namespace flyweight
{
class Character : public GlyphInterface
{
	public:
	explicit Character(char);

	virtual void First(GlyphContext&) override;
	virtual void Next(GlyphContext&) override;
	virtual bool IsDone(GlyphContext&) override;

	virtual void SetFont(Font*, GlyphContext&) override;
	virtual Font *GetFont(GlyphContext&) override;

	virtual GlyphInterface *Current(GlyphContext&) override;

	virtual void Insert(GlyphInterface*, GlyphContext&) override;
	virtual void Remove(GlyphContext&) override;

	virtual void Draw(Window*, GlyphContext&) override;

	private:
	char charcode_;
};
}}

#endif
