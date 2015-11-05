// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "tcp_closed.h"

namespace operational
{
namespace state
{
TcpClosed::TcpClosed() : established_(nullptr), listen_(nullptr) {}

void TcpClosed::Initialize(TcpState* established, TcpState* listen)
{
	established_ = established;
	listen_ = listen;
}

void TcpClosed::ActiveOpen(TcpConnection* connection)
{
	// send SYN, receive SYN, ACK, etc.
	ChangeState(connection, established_);
}

void TcpClosed::PassiveOpen(TcpConnection* connection)
{
	ChangeState(connection, listen_);
}

std::string TcpClosed::Info() const
{
	return "TcpState -> Closed";
}
}
}

