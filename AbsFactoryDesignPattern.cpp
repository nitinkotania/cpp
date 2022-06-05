#include<iostream>

using namespace std;

class Button{
    public:
        virtual void paint() = 0;
};
class WinButton : public Button{
    public:
        void paint() {     std::cout << "winButton paint" << endl; }
};
class MacButton : public Button{
    public:
        void paint() {     cout << "macButton paint" << endl; }
};
//-----------------------------------------------
class Scrollbar{
    public:
       virtual void paint() = 0;
};
class WinScrollbar : public Scrollbar{
    public:
        void paint() {     cout << "winScrollbar paint" << endl; }
    
};
class MacScrollbar : public Scrollbar{
    public:
        void paint() {     cout << "macScrollbar paint" << endl; }
};
//===============================================
class Factory{
    public: 
        virtual Button * createButton() = 0;
        virtual Scrollbar * createScrollbar() = 0;
};
class winFactory: public Factory{
    public:
        Button * createButton() { return new WinButton; }
        Scrollbar * createScrollbar() { return new WinScrollbar; }
};
class macFactory: public Factory{
    public:
        Button * createButton() { return new MacButton; }
        Scrollbar * createScrollbar() { return new MacScrollbar; }
};


int main()
{
    Factory * guiFactory;
    Button * btn;
    Scrollbar * scr;
    
    guiFactory = new winFactory();
    btn = guiFactory->createButton();
    scr = guiFactory->createScrollbar();
    btn->paint();
    scr->paint();
    
    guiFactory = new macFactory();
    btn = guiFactory->createButton();
    scr = guiFactory->createScrollbar();
    btn->paint();
    scr->paint();
      return 0;
}