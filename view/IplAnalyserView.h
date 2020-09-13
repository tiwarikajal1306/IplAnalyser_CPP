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
    void show_top_strike_rate_of_bowler(string cricketer_name, double strike_rate);
    void show_best_economy_rate_of_bowler(string cricketer_name, double economy_rate);
    void show_best_strike_rate_with_5w_4w(string cricketer_name, double strike_rate, int five_wkts, int four_wkts);
    void show_great_bowling_avg_with_best_strike_rate(string cricketer_name, double average, double strike_rate);
    void show_max_wicket_with_best_bowling_average(string cricketer_name, int wickets, double average);
    void show_max_batting_and_bowling_average(string cricketer_name, double batting_avg, double bowling_average);
    void show_most_run_and_wicket(string cricketer_name, int run, int wickets);
    void show_max_hundreds_with_best_average(string cricketer_name, int hundered, double average);
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

void IplAnalyserView::show_top_strike_rate_of_bowler(string cricketer_name, double strike_rate)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nStrike Rate: " << strike_rate << endl;
}

void IplAnalyserView::show_best_economy_rate_of_bowler(string cricketer_name, double economy_rate)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\n Economy Rate: " << economy_rate << endl;
}

void IplAnalyserView::show_best_strike_rate_with_5w_4w(string cricketer_name, double strike_rate, int five_wkts, int four_wkts)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nStrike Rate: " << strike_rate << "\nFive Wickets: " << five_wkts
         << "\nFour Wickets: " << four_wkts << endl;
}

void IplAnalyserView::show_great_bowling_avg_with_best_strike_rate(string cricketer_name, double average, double strike_rate)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nAverage: " << average << "\nStrike Rate: " << strike_rate << endl;
}

void IplAnalyserView::show_max_wicket_with_best_bowling_average(string cricketer_name, int wickets, double average)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nWickets: " << wickets << "\nAverage: " << average << endl;
}

void IplAnalyserView::show_max_batting_and_bowling_average(string cricketer_name, double batting_avg, double bowling_average)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nBatting Average: " << batting_avg << "\nBowling Average: " << bowling_average << endl;
}

void IplAnalyserView::show_most_run_and_wicket(string cricketer_name, int run, int wickets)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nRuns: " << run << "\nWickets: " << wickets << endl;
}

void IplAnalyserView::show_max_hundreds_with_best_average(string cricketer_name, int hundered, double average)
{
    cout << "Name Of Cricketer: " << cricketer_name << "\nHundered: " << hundered << "\nAverage: " << average << endl;
}