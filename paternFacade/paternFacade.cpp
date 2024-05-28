#include <iostream>
using namespace std;

//Реализовать паттерн "Фасад". Предметная область - использование стиральной машины

class Drum {
public:
    void Start() {
        cout << "Starting drum rotation"<< endl;
    }
    void Stop() {
        cout << "Stopping drum rotation"<<endl;
    }
};

class WaterSupply {
public:

    void Fill() {
        cout << "Filling water" << endl;
    }

    void Drain() {
        cout << "Draining water" << endl;
    }
};


class Detergent {
public:
    void AddDetergent() {
        cout << "Adding detergent"<<endl;
    }
};

class Squeezing {
public:
    void ClothesWringing() {
        cout << "Clothes wringing" << endl;
    }
};


class WashingMachineFacade {

    WaterSupply waterSupply;
    Detergent detergent;
    Drum drum;
    Squeezing squeezing;

public:
    WashingMachineFacade(WaterSupply wS, Detergent det, Drum dm, Squeezing sq) {
        waterSupply = wS;
        detergent = det;
        drum = dm;
        squeezing = sq;
    }

    void StartWashing() {
        waterSupply.Fill();
        detergent.AddDetergent();
        drum.Start();
    }

    void StopWashing() {
        squeezing.ClothesWringing();
        drum.Stop();
        waterSupply.Drain();
    }
};

class User {
public:

    void WashClothes(WashingMachineFacade facade) {

        facade.StartWashing();
        cout << "\nWashing clothes\n\n";
        facade.StopWashing();
    }
};

int main() {
    WaterSupply waterSupply;
    Detergent detergent;
    Drum drum;
    Squeezing squeezing;


    WashingMachineFacade washingMachine(waterSupply, detergent, drum, squeezing);

    User user;
    user.WashClothes(washingMachine);

    return 0;
}