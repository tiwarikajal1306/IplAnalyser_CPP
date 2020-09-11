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
    void display_top_batting_avg();
    void display_top_striking_rates();
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
        CLEAR_SCREEN,
        EXIT
    };

    while (start)
    {
        cout << "1. Find Top Batting Average"
             << "\n2. Find Top Striking Rates"
             << "\n3. Clear Screen\n4. Exit\n"
             << endl;
        switch (view.take_input_as_choice())
        {
        case choice::TOP_BATTING_AVG:
            find_top_batting_average();
            break;
        case choice::TOP_STRIKING_RATES:
            find_top_striking_rates();
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