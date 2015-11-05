// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_TEMPLATEMETHOD_TEMPLATE_APPLICATION_H_
#define OPERATIONAL_TEMPLATEMETHOD_TEMPLATE_APPLICATION_H_

#include "document_interface.h"

#include <list>

namespace operational
{
namespace templatemethod
{
class TemplateApplication
{
	public:
	TemplateApplication();
	virtual ~TemplateApplication();

	void OpenDocument(const std::string& path);
	DocumentState GetCurrentDocumentState() const;

	virtual DocumentInterface *CreateDocument() = 0;
	virtual bool CanOpenDocument(const std::string& path) = 0;
	virtual void AboutToOpenDocument(DocumentInterface* document) = 0;

	private:
	void AddDocument(DocumentInterface* document) const;

	std::list<DocumentInterface*>* documents_;
};
}
}

#endif

