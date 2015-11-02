// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#include "sample_document.h"

namespace operational
{
namespace templatemethod
{
SampleDocument::SampleDocument() :state_(kCreated) {}

void SampleDocument::Save()
{
	state_ = kSaved;
}

void SampleDocument::Open()
{
	state_ = kOpened;
}

void SampleDocument::Close()
{
	state_ = kClosed;
}

void SampleDocument::Read()
{
	state_ = kRead;
}

DocumentState SampleDocument::state() const
{
	return state_;
}
}}
