// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef FOUNDATION_FOUNDATION_CURRENCY_H_
#define FOUNDATION_FOUNDATION_CURRENCY_H_

namespace foundation
{
	class Currency
	{
	public:
		explicit Currency(const double&);

		double value() const;
		void value(double);

		friend bool operator==(const Currency& left, const Currency& right);
		friend bool operator!=(const Currency& left, const Currency& right);

	private:
		double value_;
	};

	inline bool operator==(const Currency& left, const Currency& right)
	{
		return left.value() == right.value();
	}

	inline bool operator!=(const Currency& left, const Currency& right)
	{
		return left.value() != right.value();
	}
}

#endif
