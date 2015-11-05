// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "employee.h"

namespace operational
{
namespace iterator
{
Employee::Employee(const std::string& name) : name_(name) { }

Employee::Employee(const Employee& employee) : name_(employee.name_) { }

void Employee::Print() { }
}
}

