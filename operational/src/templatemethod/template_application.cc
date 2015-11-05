// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "template_application.h"

namespace operational
{
namespace templatemethod
{
TemplateApplication::TemplateApplication()
{
	documents_ = new std::list<DocumentInterface*>();
}

TemplateApplication::~TemplateApplication()
{
	delete documents_;
}

void TemplateApplication::OpenDocument(const std::string& path)
{
	if (!CanOpenDocument(path))
	{
		return;
	}

	auto doc = CreateDocument();

	if (doc)
	{
		AddDocument(doc);
		AboutToOpenDocument(doc);
		doc->Open();
		doc->Read();
	}
}

DocumentState TemplateApplication::GetCurrentDocumentState() const
{
	if (documents_->size() == 0)
	{
		return kNonCreated;
	}
	auto document = documents_->back();
	return document->state();
}

void TemplateApplication::AddDocument(DocumentInterface* document) const
{
	documents_->push_front(document);
}
}
}

