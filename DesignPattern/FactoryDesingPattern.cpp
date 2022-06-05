#include <iostream>
#include <string.h>

using namespace std;


class Button{
    public:
        virtual void paint() = 0;
};
class WinButton : public Button{
    public:
        void paint() { cout << "win button " << endl; }
};
class MacButton : public Button{
    public:
        void paint() { cout << "mac button " << endl; }
};

class Factory{
    public:
        virtual Button * createFactory(string) = 0;
};
class WinFactory : public Factory{
    public:
        Button * createFactory(string type){
            if(strcmp("win", type.c_str()) == 0) return new WinButton;
            if(strcmp("mac", type.c_str()) == 0) return new MacButton;
        }
};

int main()
{
    cout<<"Hello World";
    WinFactory * guiFactory;
    Button * btn;
    btn = guiFactory->createFactory("win"); btn->paint();
    btn = guiFactory->createFactory("mac"); btn->paint();

    return 0;
}
