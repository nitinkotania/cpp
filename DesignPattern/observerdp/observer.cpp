//observer dp

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Observer{
    public:
        virtual void update(float temp, float humidity, float presure) = 0;
};

class Client : public Observer{
    public:
        void update(float temp, float humidity, float presure)
        {
            cout << "id: " << id << " temp " << temp << " humidity: " << humidity << " presure: " << presure << endl;
        }
        Client(int id): id(id) {}
        
    private:
        int id;
};

class Subject{
    public:
        virtual void registerObersever(Observer * obj) = 0;
        virtual void removeObserver(Observer * obj) = 0;
        virtual void nofityObservers() = 0;
};

class Weather: public Subject{
    public:
        void registerObersever(Observer * obj){ _observer.push_back(obj); }
        void removeObserver(Observer *obj){
            auto it = find(_observer.begin(), _observer.end(), obj);
            if(it != _observer.end()) 
                _observer.erase(it); 
        }
        void nofityObservers()
        {
            for(auto obs : _observer)
                obs->update(temp, humidity, presure);
        }
        
        void setValue(float atemp, float ahumidity, float apresure){
            temp = atemp;
            humidity = ahumidity;
            presure = apresure;
            nofityObservers();
        }
    private:
        float temp = 0.0, humidity = 0.0, presure = 0.0;
        vector<Observer *> _observer;
};

int main()
{
//	Client * c1 = new Client(1);
//	Client * c2 = new Client(2);
//	Client * c3 = new Client(3);
//	Client * c4 = new Client(4);
	Weather * obs = new Weather();
	obs->registerObersever(new Client(1));
	obs->registerObersever(new Client(2));
	obs->registerObersever(new Client(3));
	obs->registerObersever(new Client(4));
	obs->setValue(1,2,3);
	obs->setValue(4,5,6);
		
	return 0;
}
