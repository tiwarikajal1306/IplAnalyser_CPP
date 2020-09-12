#include "../view/IplAnalyserView.h"
#include "../model/Ipl_Analyser.h"

using namespace std;

class Ipl_Controller
{
    IplAnalyserView view;
    ipl_analyser analyser;
    IplBatsmanStat batsman;

public:
    void show_Welcome_Msg();
    void display_screen();
    void get_choice();
    void find_top_batting_average();
    void find_top_striking_rates();
    void find_max_six_and_four();
    void find_best_strike_rate_with_sixs_and_fours();
    void display_top_batting_avg();
    void display_top_striking_rates();
    void display_max_six_and_four();
    void display_best_strike_rate_with_sixs_and_fours();
};

void Ipl_Controller ::show_Welcome_Msg()
{
    cout << "Welcome to IPL Analyser" << endl;
}

void Ipl_Controller ::display_screen()
{
    bool start = true;

    enum choice
    {
        TOP_BATTING_AVG = 1,
        TOP_STRIKING_RATES,
        MAXIMUM_SIX_AND_FOUR,
        SR_WITH_SIX_AND_FOUR,
        CLEAR_SCREEN,
        EXIT
    };

    while (start)
    {
        cout << "1. Find Top Batting Average"
             << "\n2. Find Top Striking Rates"
             << "\n3. Find Cricketer hit maximum 6s and 4s"
             << "\n4. Find Max Strike Rate With Best Six And Four"
             << "\n5. Clear Screen\n6. Exit\n"
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

void Ipl_Controller ::get_choice()
{
    view.take_input_as_choice();
}

void Ipl_Controller ::find_top_batting_average()
{
    this->batsman = analyser.find_top_batting_average();
    display_top_batting_avg();
}

void Ipl_Controller ::display_top_batting_avg()
{
    view.display_top_batting_avg_with_name(batsman.get_player_name(),
                                           batsman.get_average());
}

void Ipl_Controller ::find_top_striking_rates()
{
    this->batsman = analyser.find_top_striking_rates();
    display_top_striking_rates();
}

void Ipl_Controller ::display_top_striking_rates()
{
    view.display_top_striking_rate_with_name(batsman.get_player_name(),
                                             batsman.get_strike_rate());
}

void Ipl_Controller ::find_max_six_and_four()
{
    this->batsman = analyser.find_max_six_and_four();
    display_max_six_and_four();
}

void Ipl_Controller ::display_max_six_and_four()
{
    view.display_max_six_and_four(batsman.get_player_name(), batsman.get_four(), batsman.get_six());
}

void Ipl_Controller::find_best_strike_rate_with_sixs_and_fours()
{
    this->batsman = analyser.find_best_strike_rate_with_sixs_and_fours();
    display_best_strike_rate_with_sixs_and_fours();
}

void Ipl_Controller::display_best_strike_rate_with_sixs_and_fours()
{
    view.display_best_strike_rate_sixs_and_fours(batsman.get_player_name(), batsman.get_strike_rate(),
                                                 batsman.get_six(), batsman.get_four());
}