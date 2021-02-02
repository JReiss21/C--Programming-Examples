This program is written in C++ and is compiled using G++

To compile using makefile included, simply type "make" and an output file called "output" will be created
in the current directory. To run this file type "./output".

FUNCTIONS, ALL FUNCTIONS MUST FOLLOW FORMAT SPECIFIED BELOW WITH ARGUMENTS

1. add_coach coach_ID season first_name last_name season_wins season_losses playoff_wins playoff_losses team (ex: add_coach TEST123 2021 John Doe 50 20 10 4 LAL)

this function will add a coach to the database

2. add_team team_ID location name league (ex: add_team TEST123 New+York Nets N)

this function will add a team to the database

3. load_coaches filename.txt (ex: load_coaches coaches.txt)

this function will load the coaches in the input file as long as they are of required format (see add coach for format)

4. load_teams filename.txt (ex: load_teams teams.txt)

this function will load the teams in the input file as long as they are of required format (see add teams for format)

5. remove_coach coach_ID (ex: remove_team TEST123)

removes coach from database with specified coach ID

6. remove_team team_ID (ex: remove_team TEST123)

removes team from database with specified team ID

7. print_coaches (ex: print_coaches)

prints coaches stored in database

8. print_teams (ex: print_teams)

prints teams stored in database

9. coaches_by_name first_name (ex: coaches_by_name John)

prints coaches with the specified first name

10. teams_by_city_league city league (ex: teams_by_city_league Los+Angeles N)

prints the teams in the database with the specified location and league

11. best_coach season (ex: best_coach 2021)

prints the best coach in the specified season

12. seach_coaches (can have any arguments SO LONG AS THEY START WITH argument=.... ex first_name=John)

prints the coaches in the database with the specified arguments


