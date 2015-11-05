// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_STATE_TCP_STATE_H_
#define OPERATIONAL_STATE_TCP_STATE_H_

#include "tcp_connection.h"

namespace operational
{
namespace state
{
class TcpState
{
	public:
	virtual ~TcpState() {}

	virtual void Transmit(TcpConnection*, TcpOctetStream*);
	virtual void ActiveOpen(TcpConnection*);
	virtual void PassiveOpen(TcpConnection*);
	virtual void Close(TcpConnection*);
	virtual void Synchronize(TcpConnection*);
	virtual void Acknowledge(TcpConnection*);
	virtual void Send(TcpConnection*);

	virtual std::string Info() const = 0;

	protected:
	static void ChangeState(TcpConnection*, TcpState*);
};
}
}

#endif

