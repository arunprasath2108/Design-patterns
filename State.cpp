#include <iostream>

class PackageState {
    public:
    virtual void updateStatus() = 0;
};

class State {

    PackageState* currentState;

    public:
    State(std::string status) {
        if(status == "Order placed") {
            currentState = new PackedState("packed");
            // currentState->updateStatus();
        } else {
            std::cout << "Can't process Order." << std::endl;
        }
    }
};

class PackedState : public PackageState {

    PackageState* currentState;

    public:
    PackedState(std::string status) {
        if(status == "packed") {
            currentState = new DeliveryState("delivered");
            currentState->updateStatus();
        } 
        else {
            std::cout << "Can't process Order." << std::endl;
        } 
    }

    void updateStatus() {
        std::cout << "Package is ready for shipment." << std::endl;
    }
};

class DeliveryState : public PackageState {

    PackageState* currentState;

    public:
    DeliveryState(std::string status) {
        if(status == "delivered") {
            currentState = new ReceivedState("delivered");
            currentState->updateStatus();
        } 
        else {
            std::cout << "Can't process Order." << std::endl;
        }
    }

    void updateStatus() {
        std::cout << "Package will reach customer within a week." << std::endl;
    }
};

class ReceivedState : public PackageState {

    PackageState* currentState;

    public:
    ReceivedState(std::string status) {
        if(status == "delivered") {
            currentState->updateStatus();
        }
    }

    void updateStatus() {
        std::cout << "Package will reach customer within a week." << std::endl;
    }
};

int main() {

    State* state = new State("Order placed");
}