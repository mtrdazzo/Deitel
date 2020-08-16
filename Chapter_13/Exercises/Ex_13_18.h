/**
 * @file Ex_13_18.h
 * @author Matthew J Randazzo (mtrdazzo@gmail.com)
 * @brief Function prototypes for showing difference between getline and get
 * @version 0.1
 * @date 2020-08-10
 *
 * Exercise 13-18
 * 
 * Write a program to show that getline and three-argument get istream member functions both end the input
 * string, with a string-terminating, null character. Also, show that get leaves the delimiter character
 * on the input stream, whereas getline extracts the delimiter character and discards it. What happens to
 * the unread characters in the stream?
 *  
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef EX_13_18_H
#define EX_13_18_H

#include <istream>
#include <string>

constexpr size_t MAX_BUFFER_SIZE{100};

class GetCharacters {

    public:
        GetCharacters() = default;

        std::string toString() const;

    protected:
        char buffer[MAX_BUFFER_SIZE];

};

class GetCharactersFromGetline : public GetCharacters {

    friend std::istream& operator>>(std::istream&, GetCharactersFromGetline &);

    public:
        GetCharactersFromGetline() = default;

};

class GetCharactersFromGet : public GetCharacters {

    friend std::istream& operator>>(std::istream&, GetCharactersFromGet &);

    public:
        GetCharactersFromGet() = default;
};

#endif /* EX_13_18_H */