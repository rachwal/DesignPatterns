// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef STRUCTURAL_FLYWEIGHT_GLYPH_INTERFACE_H_
#define STRUCTURAL_FLYWEIGHT_GLYPH_INTERFACE_H_

#include "window.h"
#include "glyph_context.h"
#include "font.h"

namespace structural
{
	class GlyphInterface
	{
	public:
		virtual ~GlyphInterface()
		{
		};

		virtual void Draw(Window*, GlyphContext&) = 0;

		virtual void First(GlyphContext&) = 0;
		virtual void Next(GlyphContext&) = 0;
		virtual bool IsDone(GlyphContext&) = 0;

		virtual void SetFont(Font*, GlyphContext&) = 0;
		virtual Font* GetFont(GlyphContext&) = 0;

		virtual GlyphInterface* Current(GlyphContext&) = 0;

		virtual void Insert(GlyphInterface*, GlyphContext&) = 0;
		virtual void Remove(GlyphContext&) = 0;
	};
}

#endif
