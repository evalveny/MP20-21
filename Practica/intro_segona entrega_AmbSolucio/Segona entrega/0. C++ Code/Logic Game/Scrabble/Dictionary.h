//
//  Dictionary.hpp
#pragma once

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

typedef enum {
    CATALAN = 0,
    SPANISH,
    ENGLISH,
    NO_LANGUAGE
} Language;

class Dictionary
{
public:

    Dictionary();
    ~Dictionary();

    void        setLanguage         (Language language);
    Language    getCurrentLanguage  () {return m_eCurrentLanguage;}
    bool        check               (const string& word);
    

private:
	vector<string>  m_aWords;
    string          m_aLanguagesPath[NO_LANGUAGE];
    int             m_iNumWords;
    Language        m_eCurrentLanguage;

private:
    void        Load                (const string& path);
    //To format a new dictionary from https://raw.githubusercontent.com/wooorm/dictionaries
    //void        SaveNewDictionary   (const string& pathFile);
    
};
