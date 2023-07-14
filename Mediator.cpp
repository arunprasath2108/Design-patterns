#include <iostream>
#include <vector>

class Mediator {

    std::vector<User*> userList;

    public:
    void addUser(User* user) {
        userList.push_back(user);
    }

    void sendMessage(std::string message, std::string sender, std::string receiver) {
        for(User* recv : userList) {
            if(recv->getName() == receiver) {
                recv->receiveMessage(message, sender);
            }
        }
    }
};

class User {

    std::string name;
    Mediator* mediator;

    public:
    User(std::string name) {
        this->name = name;
    }
    
    void sendMessage(std::string message, std::string sender, std::string receiver) {
        mediator->sendMessage(message, sender, receiver);
    }
    
    void receiveMessage(std::string message, std::string sender) {
        std::cout << "Message from " << sender << "\n";
        std::cout << "message :" << message << std::endl;
    }

    std::string getName() {
        return name;
    }
};

int main() {

    User* user1 = new User("Arun");
    User* user2 = new User("Harish");

                        // message,  sender,  receiver
    user1->sendMessage("Hii", user1->getName(), user2->getName());
}