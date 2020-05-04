#include "node.hh"

std::ostream &operator<<(std::ostream &out, const Node &c)
{
    out << c.value;
    return out;
}

bool Node::operator<(Node &node) const
{
    node.IncrementOp(1);
    return (value < node.value);
}