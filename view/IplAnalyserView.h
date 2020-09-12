#include <iostream>

using namespace std;

class IplAnalyserView
{
public:
    int take_input_as_choice();
    void display_top_batting_avg_with_name(string cricketer_name, double batting_avg);
    void display_top_striking_rate_with_name(string cricketer_name, double striking_rate);
    void display_max_six_and_four(string cricketer_name, int four, int six);
    void display_best_strike_rate_sixs_and_fours(string cricketer_name, double strike_rate, int six, int four);
    void display_great_average_with_best_strike_rate(string cricketer_name, double avg, double strike_rate);
    void display_Max_run_with_best_avg(string cricketer_name, int run, double avg);
    void show_top_bowling_avg(string cricketer_name, double avg);

};

int IplAnalyserView::take_input_as_choice()
{
    int choice;
    cout << "Enter Your Choice: ";
    cin >> choice;
    return choice;
}

void IplAnalyserView::display_top_batting_avg_with_name(string cricketer_name,
                                                        double batting_avg)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nTop Batting Average: "
         << batting_avg << endl;
}

void IplAnalyserView::display_top_striking_rate_with_name(string cricketer_name,
                                                          double striking_rate)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nTop Striking Rates: "
         << striking_rate << endl;
}

void IplAnalyserView::display_max_six_and_four(string cricketer_name, int four, int six)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nFour: " << four << "\nSix: "
         << six << endl;
}

void IplAnalyserView::display_best_strike_rate_sixs_and_fours(string cricketer_name, double strike_rate, int six, int four)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nStrike Rate: " << strike_rate << "\nFour: " << four << "\nSix: "
         << six << endl;
}

void IplAnalyserView::display_great_average_with_best_strike_rate(string cricketer_name, double avg, double strike_rate)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nStrike Rate: " << strike_rate << "\nAverage: " << avg << endl;
}

void IplAnalyserView::display_Max_run_with_best_avg(string cricketer_name, int run, double avg)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nRun: " << run << "\nAverage: " << avg << endl;
}

void IplAnalyserView::show_top_bowling_avg(string cricketer_name, double avg)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nTop Bowling Average: "
         << avg << endl;
}