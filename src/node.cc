#include "node.hh"

std::ostream &operator<<(std::ostream &out, const Node &c)
{
    out << c.value;
    return out;
}