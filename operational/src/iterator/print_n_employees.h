// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_ITERATOR_PRINT_N_EMPLOYEES_H_
#define OPERATIONAL_ITERATOR_PRINT_N_EMPLOYEES_H_

#include "list_traverser.h"
#include "employee.h"

namespace operational
{
	class PrintNEmployees : public ListTraverser<Employee*>
	{
	public:
		PrintNEmployees(List<Employee*>* aList, int n);
		~PrintNEmployees() override;

		bool Traverse() override;

	protected:
		bool ProcessItem(Employee* const&) override;

	private:
		int total_;
		int count_;
	};
}

#endif
