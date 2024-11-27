#include <iostream>
#include <deque>
#include <list>
#include <algorithm>

using namespace std;

struct Radio
{
    double frequency;
    string channel;
    string genre;

    Radio(double f, string ch, string g) : frequency(f), channel(ch), genre(g) {}

    bool operator<(const Radio &other) const
    {
        return frequency < other.frequency;
    }
};

class RadioChannel
{

    list<Radio> radioList;

public:
    void addChannel(Radio newRadio)
    {
        radioList.push_back(newRadio);
    }

    void searchRadio(string genre)
    {
        list<Radio> radios;
        for (auto ele : radioList)
        {
            if (ele.genre == genre)
            {
                radios.push_back(ele);
            }
        }

        if (!radios.empty())
        {
            int index = 1;
            for (auto ele : radios)
            {
                cout << "Avaiable Audios based on Genre: " << endl;
                cout << index << "." << ele.frequency << endl;
                cout << "Channel Name: " << ele.channel << endl;
                cout << "Channel Genre: " << ele.genre << endl;
            }
        }
    }

    void sortChannel()
    {

        radioList.sort();
    }

    void deleteRadio()
    {

        
        if (radioList.empty())
        {
            cout << "There are no radios avaliable!" << endl;
            return;
        }

        int index = 1;
        double choice;

        for (auto ele : radioList)
        {
            cout << "Available Radio Frequencies:" << endl;
            cout << index << "." << ele.frequency << endl;
            index++;
        }

        cout << "Enter the frequency that you want to delete: " << endl;
        cin >> choice;

        for (auto ele : radioList)
        {
            if (choice == ele.frequency)
            {
                radioList.remove(ele);
                cout << "Removed " << ele.channel << endl;
            }
        }
    }
};

int main()
{
    RadioChannel ch;
    ch.addChannel(Radio(234.34, "channel 1", "songs"));
    ch.addChannel(Radio(254.53, "channel 2", "movie talks"));
    ch.addChannel(Radio(224.67, "channel 3", "cricken commentery"));
    ch.addChannel(Radio(224.67, "channel 4", "cricken commentery"));
    ch.addChannel(Radio(224.67, "channel 5", "movie talks"));

    ch.sortChannel();
    ch.searchRadio("movie talks");
    ch.deleteRadio();
    return 0;
}
