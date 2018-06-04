#include <iostream>

/**
 * Strategy
 */

class Strategy {
public:
    virtual void execute() = 0;
};

/**
 * Concrete Strategy
 */

class Strategy1 : public Strategy {
public:
    void execute() {
        std::cout << "Strategy1" << std::endl;
    }
};

class Strategy2 : public Strategy {
public:
    void execute() {
        std::cout << "Strategy2" << std::endl;
    }
};

/**
 * Context, Client
 */

class StrategyClient {
private:
    Strategy *strategy;
public:
    void setStrategy(Strategy *strategy) {
        StrategyClient::strategy = strategy;
    }

    void executeStrategy() {
        strategy->execute();
    }
};

int main() {
    StrategyClient *strategyClient = new StrategyClient();

    strategyClient->setStrategy(new Strategy1());
    strategyClient->executeStrategy();

    strategyClient->setStrategy(new Strategy2());
    strategyClient->executeStrategy();

    return 0;
}