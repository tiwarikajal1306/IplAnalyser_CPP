#include <iostream>

using namespace std;

class IplAnalyserView
{
public:
    int take_input_as_choice();
    void display_top_batting_avg_with_name(string cricketer_name, double batting_avg);    
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
            << batting_avg << std::endl;
}