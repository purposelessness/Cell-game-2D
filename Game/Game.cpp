#include "Game.h"

#include "../Utility/Log.h"
#include "Events/InvertControlEvent.h"

class TestEvent : public IEvent {
public:
    void invoke() override {
        Log::instance()("Player stepped", Log::Info);
    }
};

class TestEvent2 : public IEvent {
public:
    void invoke() override {
        Log::instance()("Second event", Log::Info);
    }
};

Game::Game(std::shared_ptr<World> world) {
    _field_generator = std::make_shared<FieldGenerator>();
    _event_factory = std::make_shared<EventFactory>(std::move(world), _field_generator);

    auto field = std::make_shared<Field>();
    for (int i = 0; i < 20; ++i) {
        field->setCellEvent({5, i}, _event_factory->get<TestEvent>());
        field->setCellEvent({3, i}, _event_factory->get<TestEvent2>());
        field->setCellEvent({10, i}, _event_factory->get<InvertControlEvent>());
    }
    for (int i = 0; i < 20; ++i) {
        field->setCellPassability({17, i}, false);
    }
    _fields = {field};
}

const std::vector<std::shared_ptr<Field>>& Game::fields() {
    return _fields;
}
