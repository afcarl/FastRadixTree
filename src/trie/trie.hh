#pragma once

#include <map>

class Trie:
{
    uint8_t is_word;
    std::map<std::string, *Trie> children;
    std::string characters;

    Trie(uint8_t is_word, std::map<std::string, *Trie> children, std::string characters)
        : is_word(is_word)
        , children(children)
        , characters(characters)
    {}
}

#include "trie.hxx"

