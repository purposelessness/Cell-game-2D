#ifndef GAME_OBJECTS_FIELD_FIELD_H_
#define GAME_OBJECTS_FIELD_FIELD_H_

#include <memory>
#include <vector>

#include "Cell.h"
#include "FieldEventMessage.h"
#include "../../Utility/EventHandler.h"

struct Point;

class Field {
public:
    Field();
    explicit Field(int width, int height);

    void getSize(int& width, int& height) const;
    std::vector<Cell>& operator[](int row);
    Cell& getCell(int x, int y);
    Cell& getCell(const Point& point);
    void setCellEvent(int x, int y, std::shared_ptr<IEvent> event);
    void setCellEvent(const Point& point, std::shared_ptr<IEvent> event);

    void onPlayerStepped(const Point& point);
    void onPlayerLeft(const Point& point);

    [[nodiscard]] Point normalizePoint(const Point& point) const;

    [[nodiscard]] bool isPointPassable(const Point& point) const;

    [[nodiscard]] bool isPointValid(int x, int y) const;
    [[nodiscard]] bool isPointValid(const Point& point) const;

    Field(const Field& other);
    Field& operator=(const Field& other);

    Field(Field&& other) noexcept;
    Field& operator=(Field&& other) noexcept;

    bool operator==(const Field& other) const;

    EventHandler<FieldEventMessage> event_handler;

private:
    void swap(Field& other);

    std::vector<std::vector<Cell>> _cells;
    int _width, _height;
    Cell _empty_cell{};
};

#endif //GAME_OBJECTS_FIELD_FIELD_H_
