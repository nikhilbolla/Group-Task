#include <iostream>
#include <map>

using namespace std;

enum settingsVals {
    DisplaySettings,
    SoundSettings,
    ConnectivitySettings
};

struct User {
    int userID;
    string userName;
};

struct display {
    short brightness;
    bool isBlueLight;
};

struct sound {
    int volume;
    int base;
};

struct bluetoothDevices
{
    string deviceName;
    string version;
    bool isPaired;
};

struct connectivity
{
    bool isBluetoothOn;
    bool isConnected;
};

class settings {
    map<int, settingsVals> settingMap;

};

class DisplaySettings : public settings
{
    display displaySet;

    public:

    void setBrightness(int x)
    {
        displaySet.brightness = x;
    }

    void turnOnBlueLight()
    {
        displaySet.isBlueLight = true;
    }

     void turnOffBlueLight()
    {
        displaySet.isBlueLight = false;
    }

    void showDisplaySettings()
    {
        cout << "Brightness Settings: " << endl;
        cout << "Brightness Level: " << displaySet.brightness << endl;
        cout << "Blue Light Filter" << displaySet.isBlueLight << endl;
    }
};

class SoundSettings : public settings
{
    sound s;

    public:

    void increaseVol(int val)
    {
        if(val < 100 && val < (100 - s.volume))
        {
            s.volume = val;
        }
    }

    void decreaseVol(int val)
    {
        if(val < s.volume)
        {
            s.volume = val;
        }
    }

    void increaseBase(int val)
    {
        if(val < 100 && val < (100 - s.base))
        {
            s.base = val;
        }
    }

    void decreaseBase(int val)
    {
        if(val < s.base)
        {
            s.base = val;
        }
    }

};

class ConnectivitySettings : public settings 
{

    

};

int main()
{

    return 0;
}