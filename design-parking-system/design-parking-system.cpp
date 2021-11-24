class ParkingSystem {
public:
    int parking[4] = {0,0,0,0};
    ParkingSystem(int big, int medium, int small) {
        this->parking[1]=big;
        this->parking[2]=medium;
        this->parking[3]=small;
    }
    
    bool addCar(int carType) {
        if(this->parking[carType]>0){
            this->parking[carType]--;
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */