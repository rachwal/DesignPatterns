// Based on "Design Patterns: Elements of Reusable Object-Oriented Software"
// book by Erich Gamma, John Vlissides, Ralph Johnson, and Richard Helm 
//
// Created by Bartosz Rachwal. The National Institute of Advanced Industrial Science and Technology, Japan.

#ifndef CREATIONAL_BUILDER_COUNTING_MAZE_BUILDER_H_
#define CREATIONAL_BUILDER_COUNTING_MAZE_BUILDER_H_

#include "maze_builder_interface.h"

namespace creational
{
	class CountingMazeBuilder : public MazeBuilderInterface
	{
	public:
		CountingMazeBuilder();
		~CountingMazeBuilder() override;

		virtual void BuildMaze() override;
		virtual void BuildRoom(const int& room_number) override;
		virtual void BuildDoor(const int& first_room_number, const int& second_room_number) override;

		virtual Maze* GetMaze() override;

		void GetCounts(int* rooms, int* doors) const;

	private:
		virtual Direction CommonWall(const Room& first_room, const Room& second_room) const;

		Maze* current_maze_;
		int doors_;
		int rooms_;
	};
}

#endif
