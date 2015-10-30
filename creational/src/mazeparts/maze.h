// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_MAZEPARTS_MAZE_H_
#define CREATIONAL_MAZEPARTS_MAZE_H_

#include "room.h"

#include <map>

namespace creational
{
namespace commons
{
class Maze
{
	public:
	Maze();
	Maze(const Maze&);
	virtual ~Maze();

	void AddRoom(Room*);
	virtual Maze *Clone() const;
	Room *GetRoom(const int& room_number) const;

	private:
	std::map<int, Room*> rooms_;
};
}}

#endif
