#include "../utility/csv_reader.h"
#include "IplBatsmanStat.h"
#include <algorithm>

using namespace std;

class ipl_analyser
{
    string file_path = "../resources/MostRuns.csv";
    vector<unordered_map<string, string>> csv_data;
    vector<IplBatsmanStat> player_records;

public:
    ipl_analyser()
    {
        this->csv_data = convert_csv_to_object(file_path);
        update_player_record();
    }

    vector<IplBatsmanStat> get_player_record()
    {
        return player_records;
    }

    void update_player_record()
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
            player_records.push_back(most_runs);
        }
    }

    IplBatsmanStat find_top_batting_average()
    {
        sort(player_records.begin(), player_records.end(), [](IplBatsmanStat &first_batsman, IplBatsmanStat &second_batsman) -> bool {
            return (first_batsman.get_average() < second_batsman.get_average());
        });

        return player_records[player_records.size() - 1];
    }

    IplBatsmanStat find_top_striking_rates()
    {
        sort(player_records.begin(), player_records.end(), [](IplBatsmanStat &first_batsman, IplBatsmanStat &second_batsman) -> bool {
            return (first_batsman.get_strike_rate() < second_batsman.get_strike_rate());
        });

        return player_records[player_records.size() - 1];
    }

    IplBatsmanStat find_max_six_and_four()
    {
        sort(player_records.begin(), player_records.end(), [](IplBatsmanStat &first_batsman, IplBatsmanStat &second_batsman) -> bool {
            return ((first_batsman.get_four() < second_batsman.get_four()) && (first_batsman.get_six() < second_batsman.get_six()));
        });

        return player_records[player_records.size() - 1];
    }

    IplBatsmanStat find_best_strike_rate_with_sixs_and_fours()
    {
        sort(player_records.begin(), player_records.end(), [](IplBatsmanStat &first_batsman, IplBatsmanStat &second_batsman) -> bool {
            return ((first_batsman.get_strike_rate() < second_batsman.get_strike_rate()) && (first_batsman.get_four() < second_batsman.get_four()) && (first_batsman.get_six() < second_batsman.get_six()));
        });

        return player_records[player_records.size() - 1];
    }
};
