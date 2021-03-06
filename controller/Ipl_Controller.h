#include "../view/IplAnalyserView.h"
#include "../model/Ipl_Analyser.h"

using namespace std;

class Ipl_Controller
{
    IplAnalyserView view;
    ipl_analyser analyser;
    IplBatsmanStat batsman;
    IplBowler bowler;
    IplAllRounder all_rounder;
    string file_path_batsman = "../resources/MostRuns.csv";
    string file_path_bowler = "../resources/MostWkts.csv";

public:
    void show_Welcome_Msg();
    void display_screen();
    void get_choice();
    void find_top_batting_average();
    void find_top_striking_rates();
    void find_max_six_and_four();
    void find_best_strike_rate_with_sixs_and_fours();
    void find_great_average_with_best_strike_rate();
    void find_Max_run_with_best_avg();
    void find_top_bowling_avg();
    void find_top_strike_rate_of_bowler();
    void find_best_economy_rate_of_bowler();
    void find_best_strike_rate_with_5w_4w();
    void find_great_bowling_avg_with_best_strike_rate();
    void find_max_wicket_with_best_bowling_average();
    void find_max_batting_and_bowling_average();
    void find_most_run_and_wicket();
    void find_max_hundreds_with_best_average();
    void find_cricketer_who_had_zero_100s_50s_with_best_average();
    void find_zero_hundered_and_fifty_with_best_avg();
};

void Ipl_Controller ::show_Welcome_Msg()
{
    cout << "Welcome to IPL Analyser" << endl;
}

void Ipl_Controller ::display_screen()
{
    analyser.load_csv_file(file_path_batsman, file_path_bowler);

    bool start = true;

    enum choice
    {
        TOP_BATTING_AVG = 1,
        TOP_STRIKING_RATES,
        MAXIMUM_SIX_AND_FOUR,
        SR_WITH_SIX_AND_FOUR,
        AVG_WITH_STRIKE_RATE,
        MAX_RUN_WITH_BEST_AVG,
        TOP_BOWLING_AVERAGE,
        TOP_STRIKE_RATE_OF_BOWLER,
        BEST_ECONOMY_RATE_OF_BOWLER,
        BEST_STRIKE_RATE_WITH_5W_AND_4W,
        GREAT_BOWLING_AVG_WITH_BEST_STRIKE_RATE,
        MAX_WICKET_WITH_BEST_BOWLING_AVG,
        BATTING_AVG_BOWLING_AVG,
        MOST_RUN_AND_WICKET,
        MAX_HUNDRED_WITH_BEST_AVERAGE,
        ZEROS_HUNDREDS_FIFTY,
        CLEAR_SCREEN,
        EXIT
    };

    while (start)
    {
        cout << "1. Find Top Batting Average"
             << "\n2. Find Top Striking Rates"
             << "\n3. Find Cricketer hit maximum 6s and 4s"
             << "\n4. Find Max Strike Rate With Best Six And Four"
             << "\n5. Find Great Batting Average With Strike Rate"
             << "\n6. Find Max Run With Best Average"
             << "\n7. Find Top Bowling Average"
             << "\n8. Find Top Striking Rate Of Bowler"
             << "\n9. Find Best Economy Rate Of Bowler"
             << "\n10. Find Best Strike Rate With 4W and 5W"
             << "\n11. Find Great Bowling Average With Best Strike Rate"
             << "\n12. Find Maximum Wicket With Best Bowling Average"
             << "\n13. Find Cricketer Who Had Best Batting And Bowling Average"
             << "\n14. Find Cricketer Who had Most Run And Wicket"
             << "\n15. Find Cricketer who had maximum hundred And Best Average"
             << "\n16. Find Cricketer Who Had Zero Hundered And Fifty With Best Average"
             << "\n17. Clear Screen\n18. Exit\n"
             << endl;

        switch (view.take_input_as_choice())
        {
        case choice::TOP_BATTING_AVG:
            find_top_batting_average();
            break;
        case choice::TOP_STRIKING_RATES:
            find_top_striking_rates();
            break;
        case choice::MAXIMUM_SIX_AND_FOUR:
            find_max_six_and_four();
            break;
        case choice::SR_WITH_SIX_AND_FOUR:
            find_best_strike_rate_with_sixs_and_fours();
            break;
        case choice::AVG_WITH_STRIKE_RATE:
            find_great_average_with_best_strike_rate();
            break;
        case choice::MAX_RUN_WITH_BEST_AVG:
            find_Max_run_with_best_avg();
            break;
        case choice::TOP_BOWLING_AVERAGE:
            find_top_bowling_avg();
            break;
        case choice::TOP_STRIKE_RATE_OF_BOWLER:
            find_top_strike_rate_of_bowler();
            break;
        case choice::BEST_ECONOMY_RATE_OF_BOWLER:
            find_best_economy_rate_of_bowler();
            break;
        case choice::BEST_STRIKE_RATE_WITH_5W_AND_4W:
            find_best_strike_rate_with_5w_4w();
            break;
        case choice::GREAT_BOWLING_AVG_WITH_BEST_STRIKE_RATE:
            find_great_bowling_avg_with_best_strike_rate();
            break;
        case choice::MAX_WICKET_WITH_BEST_BOWLING_AVG:
            find_max_wicket_with_best_bowling_average();
            break;
        case choice::BATTING_AVG_BOWLING_AVG:
            find_max_batting_and_bowling_average();
            break;  
        case choice::MOST_RUN_AND_WICKET:
            find_most_run_and_wicket();
            break;  
        case choice::MAX_HUNDRED_WITH_BEST_AVERAGE:
            find_max_hundreds_with_best_average();
            break;
        case choice::ZEROS_HUNDREDS_FIFTY:
            find_zero_hundered_and_fifty_with_best_avg(); 
            break;   
        case choice::CLEAR_SCREEN:
            system("cls");
            break;
        case choice::EXIT:
            start = false;
            break;
        default:
            cout << "Enter Valid Choice..." << endl;
            break;
        }
    }
}

void Ipl_Controller ::find_top_batting_average()
{
    this->batsman = analyser.find_top_batting_average();
    view.display_top_batting_avg_with_name(batsman.get_player_name(),
                                           batsman.get_average());
}

void Ipl_Controller ::find_top_striking_rates()
{
    this->batsman = analyser.find_top_striking_rates();
    view.display_top_striking_rate_with_name(batsman.get_player_name(),
                                             batsman.get_strike_rate());
}

void Ipl_Controller ::find_max_six_and_four()
{
    this->batsman = analyser.find_max_six_and_four();

    view.display_max_six_and_four(batsman.get_player_name(), batsman.get_four(), batsman.get_six());
}

void Ipl_Controller::find_best_strike_rate_with_sixs_and_fours()
{
    this->batsman = analyser.find_best_strike_rate_with_sixs_and_fours();
    view.display_best_strike_rate_sixs_and_fours(batsman.get_player_name(), batsman.get_strike_rate(),
                                                 batsman.get_six(), batsman.get_four());
}

void Ipl_Controller::find_great_average_with_best_strike_rate()
{
    this->batsman = analyser.find_great_average_with_best_strike_rate();
    view.display_great_average_with_best_strike_rate(batsman.get_player_name(), batsman.get_average(), batsman.get_strike_rate());
}

void Ipl_Controller::find_Max_run_with_best_avg()
{
    this->batsman = analyser.find_Max_run_with_best_avg();
    view.display_Max_run_with_best_avg(batsman.get_player_name(), batsman.get_run(), batsman.get_average());
}

void Ipl_Controller::find_top_bowling_avg()
{
    this->bowler = analyser.find_top_bowling_avg();
    view.show_top_bowling_avg(bowler.get_player_name(), bowler.get_average());
}

void Ipl_Controller::find_top_strike_rate_of_bowler()
{
    this->bowler = analyser.find_top_strike_rate_of_bowler();
    view.show_top_strike_rate_of_bowler(bowler.get_player_name(), bowler.get_strike_rate());
}

void Ipl_Controller::find_best_economy_rate_of_bowler()
{
    this->bowler = analyser.find_best_economy_rate_of_bowler();
    view.show_best_economy_rate_of_bowler(bowler.get_player_name(), bowler.get_economy_rate());
}

void Ipl_Controller::find_best_strike_rate_with_5w_4w()
{
    this->bowler = analyser.find_best_strike_rate_with_5w_4w();
    view.show_best_strike_rate_with_5w_4w(bowler.get_player_name(), bowler.get_strike_rate(), bowler.get_five_wkts(), bowler.get_four_wkts());
}

void Ipl_Controller::find_great_bowling_avg_with_best_strike_rate()
{
    this->bowler = analyser.find_great_bowling_avg_with_best_strike_rate();
    view.show_great_bowling_avg_with_best_strike_rate(bowler.get_player_name(), bowler.get_average(), bowler.get_strike_rate());
}

void Ipl_Controller::find_max_wicket_with_best_bowling_average()
{
    this->bowler = analyser.find_max_wicket_with_best_bowling_average();
    view.show_max_wicket_with_best_bowling_average(bowler.get_player_name(), bowler.get_wickets(), bowler.get_average());
}

void Ipl_Controller::find_max_batting_and_bowling_average()
{
    this -> all_rounder = analyser.find_max_batting_and_bowling_average();
    view.show_max_batting_and_bowling_average(all_rounder.get_player_name(), all_rounder.get_batting_avg(), all_rounder.get_bowling_avg());
}

void Ipl_Controller::find_most_run_and_wicket()
{
    this->all_rounder = analyser.find_most_run_and_wicket();
    view.show_most_run_and_wicket(all_rounder.get_player_name(), all_rounder.get_batsman_run(), all_rounder.get_bowler_wickets());
}

void Ipl_Controller::find_max_hundreds_with_best_average()
{
    this -> batsman = analyser.find_max_hundreds_with_best_average();
    view.show_max_hundreds_with_best_average(batsman.get_player_name(), batsman.get_hundered(), batsman.get_average());
}

void Ipl_Controller::find_zero_hundered_and_fifty_with_best_avg()
{
    this -> batsman = analyser.find_zero_hundered_and_fifty_with_best_avg();
    view.show_zero_hundered_and_fifty_with_best_avg(batsman.get_player_name(), batsman.get_hundered(), batsman.get_fifty(), batsman.get_average());
}