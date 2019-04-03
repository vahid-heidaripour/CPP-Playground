#include <iostream>
#include <string>

using namespace std;

class GameSetting
{
    static GameSetting* _instance;
    int _brightness;
    int _width;
    int _height;
    GameSetting() : _width(786), _height(1024), _brightness(75) {}

public:
    static GameSetting* getInstance()
    {
        if (_instance == nullptr)
            _instance = new GameSetting();

        return _instance;
    }

    void setWidth(int width) { _width = width; }
    void setHeight(int height) { _height = height; }
    void setBrightness(int brightness) { _brightness = brightness; }

    int getWidth() const { return _width; }
    int getHeight() const { return _height; }
    int getBrightness() const { return _brightness; }

    void displaySettings()
    {
        cout << "brightness: " << _brightness << endl;
        cout << "height: " << _height << endl;
        cout << "width: " << _width << endl << endl;
    }
};

GameSetting * GameSetting::_instance = nullptr;

void someFunction()
{
    GameSetting *setting = GameSetting::getInstance();
    setting->displaySettings();
}

int main()
{
    GameSetting *setting = GameSetting::getInstance();
    setting->displaySettings();
    setting->setBrightness(100);
    someFunction();
    return 0;
}