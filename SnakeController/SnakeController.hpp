#pragma once

#include <list>
#include <memory>
#include <stdexcept>
#include <functional>

#include "IEventHandler.hpp"
#include "SnakeInterface.hpp"
#include "SnakeSegment.hpp"

class Event;
class IPort;

namespace Snake
{
struct ConfigurationError : std::logic_error
{
    ConfigurationError();
};

struct UnexpectedEventException : std::runtime_error
{
    UnexpectedEventException();
};

class Controller : public IEventHandler
{
public:
    Controller(IPort& p_displayPort, IPort& p_foodPort, IPort& p_scorePort, std::string const& p_config);

    Controller(Controller const& p_rhs) = delete;
    Controller& operator=(Controller const& p_rhs) = delete;

    void receive(std::unique_ptr<Event> e) override;

private:
    IPort& m_displayPort;
    IPort& m_foodPort;
    IPort& m_scorePort;

    std::pair<int, int> m_mapDimension;
    std::pair<int, int> m_foodPosition;

    // SEGMENT START
    // struct Segment
    // {
    //     int x;
    //     int y;
    // };

    // std::unique_ptr<SnakeSegment> segment = std::make_unique<SnakeSegment>();

    std::list<SnakeSegment> m_segments;
    Direction m_currentDirection;
    // SEGMENT END

    void handleTimeoutInd();
    void handleDirectionInd(std::unique_ptr<Event>);
    void handleFoodInd(std::unique_ptr<Event>);
    void handleFoodResp(std::unique_ptr<Event>);
    void handlePauseInd(std::unique_ptr<Event>);

    /// SEGMENT START
    bool isSegmentAtPosition(int x, int y) const;
    SnakeSegment calculateNewHead() const;
    void updateSegmentsIfSuccessfullMove(SnakeSegment const& newHead);
    void addHeadSegment(SnakeSegment const& newHead);
    void removeTailSegmentIfNotScored(SnakeSegment const& newHead);
    void removeTailSegment();
    // SEGMENT END

    bool isPositionOutsideMap(int x, int y) const;

    void updateFoodPosition(int x, int y, std::function<void()> clearPolicy);
    void sendClearOldFood();
    void sendPlaceNewFood(int x, int y);

    bool m_paused;
};

} // namespace Snake
