// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_STATE_EVENT_H_
#define OPERATIONAL_STATE_EVENT_H_

#include "tcp_state.h"

namespace operational
{
namespace state
{
class TcpClosed : public TcpState
{
	public:
	TcpClosed();

	void Initialize(TcpState* established, TcpState* listen);

	virtual void ActiveOpen(TcpConnection*) override;
	virtual void PassiveOpen(TcpConnection*) override;

	std::string Info() const override;

	private:
	TcpState* established_;
	TcpState* listen_;
};
}
}

#endif

