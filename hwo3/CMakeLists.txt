cmake_minimum_required(VERSION 3.5)

project(03.homework)

add_executable(
	check_value
	check_value.cpp
)

add_executable(
	random_value
	random_value.cpp
)

add_executable(
	high_scores
	high_scores.cpp
)

add_executable(
	argument
	argument.cpp
)

add_executable(
	game
	src/game.cpp
	src/main.cpp
)