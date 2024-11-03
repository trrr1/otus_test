#include "game.h"

#include <fstream>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <string>

 namespace game
{

static const char* high_scores_filename = "high_scores.txt";

static int get_max_value()
{
const int max_value = 100;
return max_value;
}

static int get_target_value(int max_value)
{
	std::srand(std::time(nullptr)); // use current time as seed for random generator
	const int random_value = std::rand() % max_value;
	std::cout << random_value << std::endl;
    return random_value;
}

static std::string get_user_name()
{
std::cout << "Enter your name:" << std::endl;
std::string user_name;
std::cin >> user_name;
return user_name;
}

static int make_user_play(int target_value)
{
	int current_value = 0;
    int attempts = 0;
	std::cout << "Enter your guess:" << std::endl;

	do {
		std::cin >> current_value;
        ++attempts;

		if (current_value < target_value) {
			std::cout << "less than " << current_value << std::endl;
		}
		else if (current_value > target_value) {
			std::cout << "greater than " << current_value << std::endl;
		}
		else {
			std::cout << "you win!" << std::endl;
			break;
		}

	} while(true);
    return attempts;
}

static void write_high_score(const std::string user_name, int attempts_count)
{
	// We should open the output file in the append mode - we don't want
		// to erase previous results.
		std::ofstream out_file{high_scores_filename, std::ios_base::app};
		if (!out_file.is_open()) {
			std::cout << "Failed to open file for write: " << high_scores_filename << "!" << std::endl;
		}

		// Append new results to the table:
		out_file << user_name << ' ';
		out_file << attempts_count;
		out_file << std::endl;
}

static void print_high_score()
{
    std::ifstream in_file{high_scores_filename};
		if (!in_file.is_open()) {
			std::cout << "Failed to open file for read: " << high_scores_filename << "!" << std::endl;
		}

		std::cout << "High scores table:" << std::endl;

		std::string username;
		int high_score = 0;
		while (true) {
			// Read the username first
			in_file >> username;
			// Read the high score next
			in_file >> high_score;
			// Ignore the end of line symbol
			in_file.ignore();

			if (in_file.fail()) {
				break;
			}

			// Print the information to the screen
			std::cout << username << '\t' << high_score << std::endl;
		}
}

void run();
{
  int max_value = get_max_value();
  int target_value = get_target_value(max_value);
  std::string user_name = get_user_name();
  int user_attempts = make_user_play(target_value);
  write_high_score(user_name,user_attempts);
  print_high_score();
}

} //namespace game

