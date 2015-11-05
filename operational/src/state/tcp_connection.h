// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef OPERATIONAL_STATE_TCP_CONNECTION_H_
#define OPERATIONAL_STATE_TCP_CONNECTION_H_

#include "tcp_octet_stream.h"

#include <string>

namespace operational
{
namespace state
{
class TcpConnection
{
	public:
	static TcpConnection *CreateConnection();

	void ActiveOpen();
	void PassiveOpen();
	void Close();

	void Send();
	void Acknowledge();
	void Synchronize();

	void ProcessOctet(TcpOctetStream*);

	std::string Info() const;

	private:
	TcpConnection();

	friend class TcpState;
	void ChangeState(TcpState*);

	TcpState* state_;
};
}
}

#endif

