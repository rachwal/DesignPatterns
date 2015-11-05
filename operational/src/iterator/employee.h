// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_ITERATOR_EMPLOYEE_H_
#define OPERATIONAL_ITERATOR_EMPLOYEE_H_

#include <string>

namespace operational
{
namespace iterator
{
class Employee
{
	public:
	explicit Employee(const std::string& name);
	Employee(const Employee&);

	static void Print();

	private:
	std::string name_;
};
}
}

#endif

