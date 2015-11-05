// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "tcp_state.h"

namespace operational
{
namespace state
{
void TcpState::Transmit(TcpConnection*, TcpOctetStream*) {}

void TcpState::ActiveOpen(TcpConnection*) {}

void TcpState::PassiveOpen(TcpConnection*) {}

void TcpState::Close(TcpConnection*) {}

void TcpState::Synchronize(TcpConnection*) {}

void TcpState::Acknowledge(TcpConnection*) {}

void TcpState::Send(TcpConnection*) {}

void TcpState::ChangeState(TcpConnection* connection, TcpState* state)
{
	connection->ChangeState(state);
}
}
}

