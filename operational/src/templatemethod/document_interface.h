// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_TEMPLATEMETHOD_DOCUMENT_INTERFACE_H_
#define OPERATIONAL_TEMPLATEMETHOD_DOCUMENT_INTERFACE_H_

namespace operational
{
namespace templatemethod
{
enum DocumentState
{
	kNonCreated,
	kCreated,
	kOpened,
	kClosed,
	kSaved,
	kRead
};

class DocumentInterface
{
	public:
	virtual ~DocumentInterface() {}

	virtual void Save() = 0;
	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual void Read() = 0;

	virtual DocumentState state() const = 0;
};
}}

#endif
