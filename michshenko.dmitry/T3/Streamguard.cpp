#include "Streamguard.hpp"

    StreamGuard::StreamGuard(std::basic_ios<char>& c) : s_(c), precision_(c.precision()), fmt_(c.flags()) {}
    StreamGuard::~StreamGuard()
    {
        s_.precision(precision_);
        s_.flags(fmt_);
    }
