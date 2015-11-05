// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_TEMPLATEMETHOD_SAMPLE_APPLICATION_H_
#define OPERATIONAL_TEMPLATEMETHOD_SAMPLE_APPLICATION_H_

#include "template_application.h"
#include "document_interface.h"

#include <list>

namespace operational
{
namespace templatemethod
{
class SampleApplication : public TemplateApplication
{
	public:
	virtual DocumentInterface *CreateDocument() override;
	virtual bool CanOpenDocument(const std::string& path) override;
	virtual void AboutToOpenDocument(DocumentInterface* document) override;
};
}
}

#endif

