#ifndef COACH_H
#define COACH_H

#include <string>

//namespace
using namespace std;

//coach class
class Coach
{
private:
	//class member variables
	string coach_ID;
	int season;
	string first_name;
	string last_name;
	int season_win;
	int season_loss;
	int playoff_win;
	int playoff_loss;
	string team;

public:
	//constructor
	Coach()
	{
		coach_ID = "Coach ID";
		season = -1;
		first_name = "First Name";
		last_name = "Last Name";
		season_win = -1;
		season_loss = -1;
		playoff_win = -1;
		playoff_loss = -1;
		team = "Team";
	}

	//setter function for coach id
	void setID(string arg_ID) {
		coach_ID = arg_ID;
	}
		
	//setter function for season
	void setSeason(int arg_season) {
		season = arg_season;
	}

	//setter function for first name
	void setFirstName(string arg_fname) {
		first_name = arg_fname;
	}

	//setter function for last name
	void setLastName(string arg_lname) {
		last_name = arg_lname;
	}

	//setter function for season wins
	void setSeasonWin(int arg_swin) {
		season_win = arg_swin;
	}

	//setter function for season losses
	void setSeasonLoss(int arg_sloss) {
		season_loss = arg_sloss;
	}
	
	
	//setter function for playoff wins
	void setPlayoffWin(int arg_pwin) {
		playoff_win = arg_pwin;
	}

	//setter function for playoff losses
	void setPlayoffLoss(int arg_ploss) {
		playoff_loss = arg_ploss;
	}

	//setter function for team
	void setTeam(string arg_team) {
		team = arg_team;
	}

	//getter function for coach ID
	string getID() {
		return coach_ID;
	}

	//getter function for season
	int getSeason() {
		return season;
	}

	//getter function for first name
	string getFirstName() {
		return first_name;
	}

	//getter function for last name
	string getLastName() {
		return last_name;
	}

	//getter function for season win
	int getSeasonWin() {
		return season_win;
	}

	//getter function for season loss
	int getSeasonLoss() {
		return season_loss;
	}

	//getter function for playoff win
	int getPlayoffWin() {
		return playoff_win;
	}

	//getter function for playoff loss
	int getPlayoffLoss() {
		return playoff_loss;
	}

	//getter function for team
	string getTeam() {
		return team;
	}
};

#endif // !COACH_H
