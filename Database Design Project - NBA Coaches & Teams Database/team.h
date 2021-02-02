#ifndef TEAM_H
#define TEAM_H

//namespace
using namespace std;

//team class
class Team
{
private:
	string team_ID;
	string location;
	string name;
	char league;

public:
	//constructor
	Team()
	{
		team_ID = "team_ID";
		location = "location";
		name = "name";
		league = 'Z';
	}

	//setter function for team_ID member value
	void setTeamID(string arg_ID)
	{
		team_ID = arg_ID;
	}

	//setter function for location member value
	void setLocation(string arg_location)
	{
		location = arg_location;
	}

	//setter function for name member value
	void setName(string arg_name)
	{
		name = arg_name;
	}

	//setter function for league member value
	void setLeague(char arg_league)
	{
		league = arg_league;
	}

	//getter function for team_ID member value
	string getTeamID()
	{
		return team_ID;
	}

	//getter function for location member value
	string getLocation()
	{
		return location;
	}

	//getter function for name member value
	string getName()
	{
		return name;
	}

	//getter function for league member value
	char getLeague()
	{
		return league;
	}
};

#endif // !TEAM_H
