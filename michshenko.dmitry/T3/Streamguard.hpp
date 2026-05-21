#ifndef STREAMGUARD_H
#define STREAMGUARD_H
#include <iostream>

    class StreamGuard
    {
    public:
        StreamGuard(std::basic_ios<char>& c);
        ~StreamGuard();
    private:
        std::basic_ios<char>& s_;
        std::streamsize precision_;
        std::basic_ios<char>::fmtflags fmt_;
    };


#endif
