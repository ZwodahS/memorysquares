/*
 *           DO WHAT THE **** YOU WANT TO PUBLIC LICENSE
 *                   Version 2, December 2004
 *
 * Copyright (C) 2013 ZwodahS(ericnjf@gmail.com)
 * zwodahs.wordpress.com
 *
 * Everyone is permitted to copy and distribute verbatim or modified
 * copies of this license document, and changing it is allowed as long
 * as the name is changed.
 *
 *           DO WHAT THE **** YOU WANT TO PUBLIC LICENSE
 *   TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION
 *
 *  0. You just DO WHAT THE **** YOU WANT TO.
 *
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://sam.zoy.org/wtfpl/COPYING for more details.
 */

#include "Grid.hpp"
namespace zf
{
    Grid::Grid()
    {
        this->row = 0;
        this->col = 0;
    }

    Grid::Grid(int row, int col)
    {
        this->row = row;
        this->col = col;
    }

    Grid::~Grid()
    {
    }

    int Grid::distanceFrom(const Grid& rhs) const
    {
        return std::abs(rhs.row - row) + std::abs(rhs.col - col);
    }
    int distanceBetween(const Grid& lhs, const Grid& rhs)
    {
        return lhs.distanceFrom(rhs);
    }
}

bool zf::Grid::operator==(const zf::Grid& rhs) const
{
    if(row == rhs.row && col == rhs.col)
    {
        return true;
    }
    return false;
}

bool zf::Grid::operator!=(const zf::Grid& rhs) const
{
    return !operator==(rhs);
}

// bool operator==(const zf::Grid &lhs, const zf::Grid &rhs)
// {
//     return lhs.operator==(rhs);
// }
//
// bool operator!=(const zf::Grid &lhs, const zf::Grid &rhs)
// {
//     return !(operator==(lhs,rhs));
// }


zf::Grid& zf::Grid::operator+=(const zf::Grid& rhs)
{
    this->row += rhs.row;
    this->col += rhs.col;
    return *this;
}

zf::Grid& zf::Grid::operator-=(const zf::Grid& rhs)
{
    this->row -= rhs.row;
    this->col -= rhs.col;
    return *this;
}

zf::Grid operator+(zf::Grid lhs, const zf::Grid &rhs)
{
    return lhs += rhs;
}

zf::Grid operator-(zf::Grid lhs, const zf::Grid &rhs)
{
    return lhs -= rhs;
}

std::ostream& operator<<(std::ostream& stream, const zf::Grid& rhs)
{
    stream << "(" << rhs.row << "," << rhs.col << ")";
    return stream;
}
