#include "group.h"

void Group::display(std::ostream & s) const
{
    for (MediaPtr m : *this) {
        m->display(s);
    }
}
