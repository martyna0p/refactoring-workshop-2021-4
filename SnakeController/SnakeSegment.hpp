#pragma once

#include <list>
#include <memory>
#include <stdexcept>
#include <functional>

#include "IEventHandler.hpp"
#include "SnakeInterface.hpp"


class SnakeSegment
{
    public:
    SnakeSegment() = default;
    SnakeSegment(int a, int b) : x(a), y(b) {};
            int x;
            int y;

    // bool isSegmentAtPosition(int x, int y, std::list<SnakeSegment> m_segments) const;
    // bool isSegmentAtPosition(std::list<SnakeSegment> m_segments) const;


};