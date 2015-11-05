// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_STATE_TCP_ESTABLISHED_H_
#define OPERATIONAL_STATE_TCP_ESTABLISHED_H_

#include "tcp_state.h"

namespace operational
{
namespace state
{
class TcpEstablished : public TcpState
{
	public:
	TcpEstablished();

	void Initialize(TcpState* listen, TcpState* closed);

	virtual void Transmit(TcpConnection*, TcpOctetStream*) override;
	virtual void Acknowledge(TcpConnection*) override;
	virtual void Close(TcpConnection*) override;

	virtual std::string Info() const override;

	private:
	TcpState* listen_;
	TcpState* closed_;
};
}
}

#endif

