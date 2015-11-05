// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "sample_application.h"
#include "sample_document.h"

namespace operational
{
namespace templatemethod
{
DocumentInterface *SampleApplication::CreateDocument()
{
	return new SampleDocument();
}

bool SampleApplication::CanOpenDocument(const std::string& path)
{
	if (path.compare("") == 0)
	{
		return false;
	}
	return true;
}

void SampleApplication::AboutToOpenDocument(DocumentInterface* document) {}
}
}

