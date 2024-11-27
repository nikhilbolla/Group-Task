#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <string>

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
            cout << "Available Audios based on Genre: " << genre << endl;
            for (auto ele : radios)
            {
                cout << index << ". Frequency: " << ele.frequency << endl;
                cout << "   Channel Name: " << ele.channel << endl;
                cout << "   Channel Genre: " << ele.genre << endl;
                index++;
            }
        }
        else
        {
            cout << "No radios found with genre: " << genre << endl;
        }
    }

    void sortChannel()
    {
        radioList.sort();
        cout << "Channels sorted by frequency!" << endl;
    }

    void deleteRadio()
    {
        if (radioList.empty())
        {
            cout << "There are no radios available!" << endl;
            return;
        }

        int index = 1;
        double choice;

        cout << "Available Radio Frequencies:" << endl;
        for (const auto &ele : radioList)
        {
            cout << index << ") " << ele.frequency << " - " << ele.channel << endl;
            index++;
        }

        cout << "Enter the frequency that you want to delete: ";
        cin >> choice;

        auto it = find_if(radioList.begin(), radioList.end(), [choice](const Radio &radio) {
            return radio.frequency == choice;
        });

        if (it != radioList.end())
        {
            cout << "Removed " << it->channel << " (Frequency: " << it->frequency << ")" << endl;
            radioList.erase(it);
        }
        else
        {
            cout << "No radio found with frequency: " << choice << endl;
        }
    }
};

int main()
{
    RadioChannel ch;
    ch.addChannel(Radio(234.34, "Channel 1", "songs"));
    ch.addChannel(Radio(254.53, "Channel 2", "movie talks"));
    ch.addChannel(Radio(224.67, "Channel 3", "cricket commentary"));
    ch.addChannel(Radio(244.67, "Channel 4", "cricket commentary"));
    ch.addChannel(Radio(214.67, "Channel 5", "movie talks"));

    ch.sortChannel();
    cout << endl;

    ch.searchRadio("movie talks");
    cout << endl;

    ch.deleteRadio();
    return 0;
}
