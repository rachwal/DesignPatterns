// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_STATE_TCP_LISTEN_H_
#define OPERATIONAL_STATE_TCP_LISTEN_H_

#include "tcp_state.h"

namespace operational
{
namespace state
{
class TcpListen : public TcpState
{
	public:
	TcpListen();

	void Initialize(TcpState* established, TcpState* closed);

	virtual void Close(TcpConnection*) override;
	virtual void Send(TcpConnection*) override;

	virtual std::string Info() const override;

	private:
	TcpState* established_;
	TcpState* closed_;
};
}
}

#endif

