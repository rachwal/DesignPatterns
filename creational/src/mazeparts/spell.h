// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEPARTS_SPELL_H_
#define CREATIONAL_MAZEPARTS_SPELL_H_

#include <string>

namespace creational
{
namespace commons
{
class Spell
{
	public:
	explicit Spell(const std::string& message);
	Spell(const Spell& spell);

	std::string message() const;

	private:
	const std::string message_;
};
}}

#endif
