// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "tcp_established.h"

namespace operational
{
namespace state
{
TcpEstablished::TcpEstablished() : listen_(nullptr), closed_(nullptr) {}

void TcpEstablished::Initialize(TcpState* listen, TcpState* closed)
{
	listen_ = listen;
	closed_ = closed;
}

void TcpEstablished::Close(TcpConnection* connection)
{
	if (!listen_)
	{
		return;
	}
	ChangeState(connection, closed_);
}

std::string TcpEstablished::Info() const
{
	return "TcpState -> Established";
}

void TcpEstablished::Transmit(TcpConnection* connection, TcpOctetStream* stream)
{
	connection->ProcessOctet(stream);
}

void TcpEstablished::Acknowledge(TcpConnection* connection)
{
	ChangeState(connection, listen_);
}
}
}

