#ifndef GAME_CORE_MAINAPPLICATION_H_
#define GAME_CORE_MAINAPPLICATION_H_

#include <vector>
#include <memory>

#include "../Engine/Core/Application.h"
#include "../Utility/IDisposable.h"
#include "View/IMainApplication.h"

class ITickable;
class World;

class MainApplication : public Application, public IMainApplication {
public:
    MainApplication();

    void update() override;

    void addTickable(const std::shared_ptr<ITickable>& tickable) override;
    void addDisposable(const std::shared_ptr<IDisposable>& disposable) override;

private:
    std::shared_ptr<World> _world;
    std::vector<std::shared_ptr<ITickable>> _tickables;
    std::vector<std::shared_ptr<IDisposable>> _disposables;
};

#endif //GAME_CORE_MAINAPPLICATION_H_