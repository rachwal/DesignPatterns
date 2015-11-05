// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_COMMAND_MY_CLASS_H_
#define OPERATIONAL_COMMAND_MY_CLASS_H_

namespace operational
{
namespace command
{
class MyClass
{
	public:
	MyClass();
	explicit MyClass(bool fired);

	void Action();

	bool fired() const;

	private :
	bool fired_;
};
}
}

#endif

