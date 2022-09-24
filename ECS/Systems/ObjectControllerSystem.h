#ifndef GAME_ECS_SYSTEMS_OBJECTCONTROLLERSYSTEM_H_
#define GAME_ECS_SYSTEMS_OBJECTCONTROLLERSYSTEM_H_

#include <memory>
#include <vector>

#include "../../Engine/Input/IController.h"
#include "../../ECSLib/Systems/System.h"

class Transform;

class ObjectControllerSystem : public IController, public System {
public:
    void process(const InputMessage& input_message) override;
    void process() override;

private:
    InputMessage _message{};
};

#endif //GAME_ECS_SYSTEMS_OBJECTCONTROLLERSYSTEM_H_