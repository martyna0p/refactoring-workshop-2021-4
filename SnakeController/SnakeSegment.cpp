#include "SnakeSegment.hpp"

#include <algorithm>
#include <sstream>

#include "EventT.hpp"
#include "IPort.hpp"



// bool isHorizontal(Direction direction)
// {
//     return Direction_LEFT == direction or Direction_RIGHT == direction;
// }

// bool isVertical(Direction direction)
// {
//     return Direction_UP == direction or Direction_DOWN == direction;
// }

// bool isPositive(Direction direction)
// {
//     return (isVertical(direction) and Direction_DOWN == direction)
//         or (isHorizontal(direction) and Direction_RIGHT == direction);
// } int x, int y, 



// bool SnakeSegment::isSegmentAtPosition(std::list<SnakeSegment> m_segments) const
// {
//     return m_segments.end() !=  std::find_if(m_segments.cbegin(), m_segments.cend(),
//         [x, y](auto const& segment){ return segment.x == x and segment.y == y; });
// }

// SnakeSegment::Segment SnakeSegment::calculateNewHead() const
// {
//     Segment const& currentHead = m_segments.front();

//     Segment newHead;
//     newHead.x = currentHead.x + (isHorizontal(m_currentDirection) ? isPositive(m_currentDirection) ? 1 : -1 : 0);
//     newHead.y = currentHead.y + (isVertical(m_currentDirection) ? isPositive(m_currentDirection) ? 1 : -1 : 0);

//     return newHead;
// }

// void SnakeSegment::updateSegmentsIfSuccessfullMove(Segment const& newHead)
// {
//     if (isSegmentAtPosition(newHead.x, newHead.y) or isPositionOutsideMap(newHead.x, newHead.y)) {
//         m_scorePort.send(std::make_unique<EventT<Snake::LooseInd>>());
//     } else {
//         addHeadSegment(newHead);
//         removeTailSegmentIfNotScored(newHead);
//     }
// }


// void SnakeSegment::addHeadSegment(Segment const& newHead)
// {
//     m_segments.push_front(newHead);

//     Snake::DisplayInd placeNewHead;
//     placeNewHead.x = newHead.x;
//     placeNewHead.y = newHead.y;
//     placeNewHead.value = Cell_SNAKE;

//     m_displayPort.send(std::make_unique<EventT<Snake::DisplayInd>>(placeNewHead));
// }
