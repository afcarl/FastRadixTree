#pragma once

#include <vector>
#include <string>
#include <fstream>

#include "../word/word.hh"


class Trie
{
public:
    uint32_t frequency;
    std::string value;
    std::vector<std::shared_ptr<Trie>> *children;
    unsigned long offset;

    Trie() {}
/** 
 *   @brief Trie node's constructor 
 *
 *   @param value the word's content
 *   @param frequency the word's frequency
 *   @param children the list of children 
 *   @return The node 
 */  
    Trie(uint32_t frequency, std::string value)
        : frequency(frequency)
        , value(value)
    {
        children = new std::vector<std::shared_ptr<Trie>>();
    }

    ~Trie()
    {
        children->clear();
        delete(children);
    }

    void add_word_compressed(std::string, uint32_t);

    void save_trie(std::string);
    void walk(std::ofstream&, std::shared_ptr<unsigned long>&);

    void write_offset(std::ofstream&, unsigned long, unsigned long);
    size_t write_trie(std::ofstream&);
};

# include "trie.hxx"

