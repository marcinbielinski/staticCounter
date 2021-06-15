#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <vector>
#include <map>

class Entity {
public:
    explicit Entity(bool doCount = true) {
        std::cout << "Entity Constructor" << std::endl;
        if (doCount)
            ++instanceCounter_;
    }

    [[maybe_unused]] virtual void printNameAndCount() = 0;

    virtual std::string getName() {
        return "Entity";
    }

    virtual void printName() = 0;

    static size_t getCount() {
        return instanceCounter_;
    };

    virtual void printCount() = 0;

    virtual ~Entity() { std::cout << "Entity Destructor" << std::endl; }

protected:
    static std::size_t instanceCounter_;
};

class Player : public Entity {
public:
    explicit Player(std::string name, bool doCount = true)
                    : m_Name(std::move(name)), Entity(false) {
        std::cout << "Player Constructor" << std::endl;
        if (doCount)
            ++instanceCounter_;
    }

    void printNameAndCount() override {
        printName();
        printCount();
    }

    std::string getName() override { return m_Name; }

    void printName() override {
        std::cout << getName() << std::endl;
    }

    static size_t getCount() {
        return instanceCounter_;
    }

    void printCount() override {
        std::cout << getCount() << std::endl;
    }

    ~Player() override { std::cout << "Player Destructor" << std::endl; }

private:
    std::string m_Name;
    static std::size_t instanceCounter_;
};

std::size_t Entity::instanceCounter_ = {0};
std::size_t Player::instanceCounter_ = {0};

template<typename datatype>
 std::map<datatype, int> vectorElemCount(const std::vector<datatype>& items) {

    std::map<datatype, int> itemCount;

    for (const datatype& item: items) {
        ++itemCount[item];
    }
    return itemCount;
}

template <typename key, typename value>
void printMap (const std::map<key, value>& input) {
    for (auto& elem : input)
    {
        std::cout << elem.first << " and " << elem.second << std::endl;
    }
}
int main() {
//    Entity* ent1 = new Entity();
    std::string m = "First string";
    std::string m2 = "Second string";
    std::string m3 = "Third string";


    std::vector<std::shared_ptr<Entity>> vec;

//    std::unique_ptr<Entity> ent2 = std::make_unique<Player>(m);
//    std::unique_ptr<Entity> ent3 = std::make_unique<Player>(m2);
//    std::unique_ptr<Entity> ent4 = std::make_unique<Player>(m3);

    printMap(vectorElemCount(vec));
//    vec.emplace_back(std::move(ent2));
//    vec.emplace_back(std::move(ent3));
//    vec.emplace_back(std::move(ent4));
    vec.push_back(std::make_shared<Player>(m));
    vec.push_back(std::make_shared<Player>(m2));
    vec.push_back(std::make_shared<Player>(m3));

    printMap(vectorElemCount(vec));

//    Container::vectorElemCount(vec);


//    for (const auto &elem : vec) {
//        elem->printNameAndCount();
//    }

    return 0;
}