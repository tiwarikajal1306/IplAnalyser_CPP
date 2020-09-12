#include <iostream>

using namespace std;

class IplAnalyserView
{
public:
    int take_input_as_choice();
    void display_top_batting_avg_with_name(string cricketer_name, double batting_avg);
    void display_top_striking_rate_with_name(string cricketer_name, double striking_rate);
    void display_max_six_and_four(string cricketer_name, int four, int six);
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