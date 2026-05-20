#ifndef DELIMITER_IO_H
#define DELIMITER_IO_H

struct DelimiterIO
{
    char expected;
};
std::istream& operator>>(std::istream& in, DelimiterIO&& dest);

#endif /* DELIMITER_IO_H */
