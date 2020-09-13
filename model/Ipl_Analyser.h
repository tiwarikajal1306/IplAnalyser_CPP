#include "../utility/csv_reader.h"
#include "IplBatsmanStat.h"
#include "IplBowling.h"
#include "IplAllRounder.h"
#include <algorithm>

using namespace std;

class ipl_analyser
{

    vector<unordered_map<string, string>> csv_data;
    vector<IplBatsmanStat> batsman_records;
    vector<IplBowler> bowler_records;
    vector<IplAllRounder> all_rounder_records;

public:
    void load_csv_file(string file_path_batsman, string file_path_bowler)
    {
        this->csv_data = convert_csv_to_object(file_path_batsman);
        update_batsman_record();
        this->csv_data = convert_csv_to_object(file_path_bowler);
        update_bowler_record();
        update_all_rounder_record();
    }

    void update_batsman_record()
    {
        for (unordered_map<string, string> itr : csv_data)
        {
            IplBatsmanStat most_runs(itr.at("PLAYER"));
            most_runs.set_match(stoi(itr.at("Mat")));
            most_runs.set_innings(stoi(itr.at("Inns")));
            most_runs.set_run(stoi(itr.at("Runs")));
            most_runs.set_high_score(itr.at("HS"));
            most_runs.set_average(stod(itr.at("Avg")));
            most_runs.set_fifty(stoi(itr.at("50")));
            most_runs.set_fours(stoi(itr.at("4s")));
            most_runs.set_hundered(stoi(itr.at("100")));
            most_runs.set_six(stoi(itr.at("6s")));
            most_runs.set_strike_rate(stod(itr.at("SR")));
            batsman_records.push_back(most_runs);
        }
    }

    void update_bowler_record()
    {
        for (std::unordered_map<std::string, std::string> itr : csv_data)
        {
            IplBowler most_wkts(itr.at("PLAYER"));
            most_wkts.set_run(std::stoi(itr.at("Runs")));
            most_wkts.set_wickets(std::stoi(itr.at("Wkts")));
            most_wkts.set_average(std::stod(itr.at("Avg")));
            most_wkts.set_fours_wkts(std::stoi(itr.at("4w")));
            most_wkts.set_five_wkts(std::stoi(itr.at("5w")));
            most_wkts.set_strike_rate(std::stod(itr.at("SR")));
            most_wkts.set_economy_rate(std::stod(itr.at("Econ")));
            bowler_records.push_back(most_wkts);
        }
    }

     void update_all_rounder_record()
    {
        for(IplBatsmanStat batsman_itr : batsman_records)
        {
            for (IplBowler bowler_itr : bowler_records)
            {
                if(batsman_itr.get_player_name() == bowler_itr.get_player_name())
                {
                    IplAllRounder all_rounder(batsman_itr.get_player_name());
                    all_rounder.set_batsman_run(batsman_itr.get_run());
                    all_rounder.set_bowler_run(bowler_itr.get_run());
                    all_rounder.set_bowler_wickets(bowler_itr.get_wickets());
                    all_rounder.set_batting_avg(batsman_itr.get_average());
                    all_rounder.set_bowling_avg(bowler_itr.get_average());
                    all_rounder_records.push_back(all_rounder);
                }
            }
        }
    }   

    IplBatsmanStat find_top_batting_average()
    {
        vector<IplBatsmanStat> player_records = batsman_records;
        sort(player_records.begin(), player_records.end(), [](IplBatsmanStat &first_batsman, IplBatsmanStat &second_batsman) -> bool {
            return (first_batsman.get_average() > second_batsman.get_average());
        });

        return player_records.at(0);
    }

    IplBatsmanStat find_top_striking_rates()
    {
        vector<IplBatsmanStat> player_records = batsman_records;
        sort(player_records.begin(), player_records.end(), [](IplBatsmanStat &first_batsman, IplBatsmanStat &second_batsman) -> bool {
            return (first_batsman.get_strike_rate() > second_batsman.get_strike_rate());
        });

        return player_records.at(0);
    }

    IplBatsmanStat find_max_six_and_four()
    {
        vector<IplBatsmanStat> player_records = batsman_records;
        sort(player_records.begin(), player_records.end(), [](IplBatsmanStat &first_batsman, IplBatsmanStat &second_batsman) -> bool {
            return ((first_batsman.get_four() + first_batsman.get_six() > second_batsman.get_four() + second_batsman.get_six()));
        });

        return player_records.at(0);
    }

    IplBatsmanStat find_best_strike_rate_with_sixs_and_fours()
    {
        vector<IplBatsmanStat> player_records = batsman_records;
        sort(player_records.begin(), player_records.end(), [](IplBatsmanStat &first_batsman, IplBatsmanStat &second_batsman) -> bool {
            return ((first_batsman.get_strike_rate() > second_batsman.get_strike_rate()) &&
                    (first_batsman.get_six() + first_batsman.get_four() > second_batsman.get_six() + second_batsman.get_four()));
        });

        return player_records.at(0);
    }

    IplBatsmanStat find_great_average_with_best_strike_rate()
    {
        vector<IplBatsmanStat> player_records = batsman_records;
        sort(player_records.begin(), player_records.end(), [](IplBatsmanStat &first_batsman, IplBatsmanStat &second_batsman) -> bool {
            return ((first_batsman.get_average() < second_batsman.get_average()) &&
                    (first_batsman.get_strike_rate() < second_batsman.get_strike_rate()));
        });

        return player_records[player_records.size() - 1];
    }

    IplBatsmanStat find_Max_run_with_best_avg()
    {
        vector<IplBatsmanStat> player_records = batsman_records;
        sort(player_records.begin(), player_records.end(), [](IplBatsmanStat &first_batsman, IplBatsmanStat &second_batsman) -> bool {
            return ((first_batsman.get_run() > second_batsman.get_run() &&
                     first_batsman.get_average() > second_batsman.get_average()));
        });

        return player_records.at(0);
    }

    IplBowler find_top_bowling_avg()
    {
        vector<IplBowler> player_records = bowler_records;
        sort(player_records.begin(), player_records.end(), [](IplBowler &first_bowler, IplBowler &second_bowler) -> bool {
            return (first_bowler.get_average() > second_bowler.get_average());
        });

        return player_records.at(0);
    }

    IplBowler find_top_strike_rate_of_bowler()
    {
        vector<IplBowler> player_records = bowler_records;
        sort(player_records.begin(), player_records.end(), [](IplBowler &first_bowler, IplBowler &second_bowler) -> bool {
            return (first_bowler.get_strike_rate() > second_bowler.get_strike_rate());
        });
        return player_records.at(0);
    }

    IplBowler find_best_economy_rate_of_bowler()
    {
        vector<IplBowler> player_records = bowler_records;
        sort(player_records.begin(), player_records.end(), [](IplBowler &first_bowler, IplBowler &second_bowler) -> bool {
            return (first_bowler.get_economy_rate() > second_bowler.get_economy_rate());
        });
        return player_records.at(0);
    }

    IplBowler find_best_strike_rate_with_5w_4w()
    {
        vector<IplBowler> player_records = bowler_records;
        sort(player_records.begin(), player_records.end(), [](IplBowler &first_bowler, IplBowler &second_bowler) -> bool {
            return ((first_bowler.get_four_wkts() + first_bowler.get_five_wkts() > second_bowler.get_four_wkts() + second_bowler.get_five_wkts()));
        });

        int max_wickets = player_records.at(0).get_five_wkts() + player_records.at(0).get_four_wkts();
        vector<IplBowler> max_wkts_bowler;
        for (IplBowler itr : player_records)
        {
            if ((itr.get_five_wkts() + itr.get_four_wkts()) == max_wickets)
            {
                max_wkts_bowler.push_back(itr);
            }
        }

        sort(max_wkts_bowler.begin(), max_wkts_bowler.end(), [](IplBowler &first_bowler, IplBowler &second_bowler) -> bool {
            return ((first_bowler.get_strike_rate() > second_bowler.get_strike_rate()));
        });

        return max_wkts_bowler.at(0);
    }

    IplBowler find_great_bowling_avg_with_best_strike_rate()
    {
        vector<IplBowler> player_records = bowler_records;
        sort(player_records.begin(), player_records.end(), [](IplBowler &first_bowler, IplBowler &second_bowler) -> bool {
            return ((first_bowler.get_average() + first_bowler.get_strike_rate() > second_bowler.get_average() + second_bowler.get_strike_rate()));
        });
        return player_records.at(0);
    }

    IplBowler find_max_wicket_with_best_bowling_average()
    {
        vector<IplBowler> player_records = bowler_records;
        sort(player_records.begin(), player_records.end(), [](IplBowler &first_bowler, IplBowler &second_bowler) -> bool {
            return ((first_bowler.get_wickets() > second_bowler.get_wickets()));
        });

        int max_wickets = player_records.at(0).get_wickets();
        vector<IplBowler> max_wkts_bowler;
        for (IplBowler itr : player_records)
        {
            if (itr.get_wickets() == max_wickets)
            {
                max_wkts_bowler.push_back(itr);
            }
        }

        sort(max_wkts_bowler.begin(), max_wkts_bowler.end(), [](IplBowler &first_bowler, IplBowler &second_bowler) -> bool {
            return ((first_bowler.get_average() > second_bowler.get_average()));
        });

        return max_wkts_bowler.at(0);
    }

    IplAllRounder find_max_batting_and_bowling_average()
    {
        vector<IplAllRounder> player_records = all_rounder_records;
        sort(player_records.begin(), player_records.end(), [](IplAllRounder &first_all_rounder, IplAllRounder &second_all_rounder) -> bool {
            return ((first_all_rounder.get_batting_avg() > 
                second_all_rounder.get_batting_avg())
                && (first_all_rounder.get_bowling_avg() >  second_all_rounder.get_bowling_avg()));
        });

        return player_records.at(0);
    }

    IplAllRounder find_most_run_and_wicket()
    {
        vector<IplAllRounder> player_records = all_rounder_records;
        sort(player_records.begin(), player_records.end(), [](IplAllRounder &first_all_rounder, IplAllRounder &second_all_rounder) -> bool {
            return ((first_all_rounder.get_batsman_run() > 
                second_all_rounder.get_batsman_run())
                && (first_all_rounder.get_bowler_wickets() >  second_all_rounder.get_bowler_wickets()));
        });

        return player_records.at(0);
    }

    IplBatsmanStat find_max_hundreds_with_best_average()
    {
        vector<IplBatsmanStat> player_records = batsman_records;
        sort(player_records.begin(), player_records.end(), [](IplBatsmanStat &first_batsman, IplBatsmanStat &second_batsman) -> bool {
            return ((first_batsman.get_hundered() > second_batsman.get_hundered()));
        });

        int max_hundered = player_records.at(0).get_hundered();
        vector<IplBatsmanStat> max_batsman_hundered;
        for (IplBatsmanStat itr : player_records)
        {
            if (itr.get_hundered() == max_hundered)
            {
                max_batsman_hundered.push_back(itr);
            }
        }

        sort(max_batsman_hundered.begin(), max_batsman_hundered.end(), [](IplBatsmanStat &first_batsman, IplBatsmanStat &second_batsman) -> bool {
            return ((first_batsman.get_average() > second_batsman.get_average()));
        });

        return max_batsman_hundered.at(0);
    }
};
