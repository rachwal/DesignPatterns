// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "employee.h"
#include "print_n_employees.h"

namespace operational
{
namespace iterator
{
PrintNEmployees::~PrintNEmployees() { }

bool PrintNEmployees::Traverse()
{
	return false;
}

PrintNEmployees::PrintNEmployees(List<Employee*>* list, int n) :
	ListTraverser<Employee*>(list),
	total_(n), count_(0) { }

bool PrintNEmployees::ProcessItem(Employee* const& e)
{
	count_++;
	e->Print();
	return count_ < total_;
}
}}
