// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "tcp_listen.h"

namespace operational
{
namespace state
{
TcpListen::TcpListen() : established_(nullptr), closed_(nullptr) {}

void TcpListen::Initialize(TcpState* established, TcpState* closed)
{
	established_ = established;
	closed_ = closed;
}

void TcpListen::Close(TcpConnection* connection)
{
	ChangeState(connection, closed_);
}

void TcpListen::Send(TcpConnection* connection)
{
	// send SYN, receive SYN, ACK, etc.
	ChangeState(connection, established_);
}

std::string TcpListen::Info() const
{
	return "TcpState -> Listen";
}
}
}

