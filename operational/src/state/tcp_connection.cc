// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "tcp_connection.h"
#include "tcp_closed.h"
#include "tcp_established.h"
#include "tcp_listen.h"

namespace operational
{
namespace state
{
TcpConnection::TcpConnection() : state_(nullptr) {}

TcpConnection *TcpConnection::CreateConnection()
{
	auto listen = new TcpListen();
	auto established = new TcpEstablished();
	auto closed = new TcpClosed();

	established->Initialize(listen, closed);
	listen->Initialize(established, closed);
	closed->Initialize(established, listen);

	auto connection = new TcpConnection();
	connection->ChangeState(closed);

	return connection;
}

void TcpConnection::ChangeState(TcpState* state)
{
	state_ = state;
}

void TcpConnection::ActiveOpen()
{
	state_->ActiveOpen(this);
}

void TcpConnection::PassiveOpen()
{
	state_->PassiveOpen(this);
}

void TcpConnection::Close()
{
	state_->Close(this);
}

void TcpConnection::Send()
{
	state_->Send(this);
}

void TcpConnection::Acknowledge()
{
	state_->Acknowledge(this);
}

void TcpConnection::Synchronize()
{
	state_->Synchronize(this);
}

void TcpConnection::ProcessOctet(TcpOctetStream* octet_stream)
{
	state_->Transmit(this, octet_stream);
}

std::string TcpConnection::Info() const
{
	return state_->Info();
}
}
}

