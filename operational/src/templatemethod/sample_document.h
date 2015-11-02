// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_TEMPLATEMETHOD_SAMPLE_DOCUMENT_H_
#define OPERATIONAL_TEMPLATEMETHOD_SAMPLE_DOCUMENT_H_

#include "document_interface.h"

namespace operational
{
namespace templatemethod
{
class SampleDocument :public DocumentInterface
{
	public:
	SampleDocument();

	virtual void Save() override;
	virtual void Open() override;
	virtual void Close() override;
	virtual void Read() override;

	DocumentState state() const override;

	private:
	DocumentState state_;
};
}}

#endif
