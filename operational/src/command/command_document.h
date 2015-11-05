// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_COMMAND_COMMAND_DOCUMENT_H_
#define OPERATIONAL_COMMAND_COMMAND_DOCUMENT_H_

#include <string>

namespace operational
{
namespace command
{
class CommandDocument
{
	public:
	explicit CommandDocument(const std::string& name);

	void Open();
	void Paste();

	std::string name() const;

	private:
	std::string name_;
};
}
}

#endif

