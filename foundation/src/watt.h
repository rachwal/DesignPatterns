// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef FOUNDATION_FOUNDATION_WATT_H_
#define FOUNDATION_FOUNDATION_WATT_H_

namespace foundation
{
	class Watt
	{
	public:
		explicit Watt(const double& value);

		double value() const;
		void value(double);

	private:
		double value_;
	};
}

#endif
