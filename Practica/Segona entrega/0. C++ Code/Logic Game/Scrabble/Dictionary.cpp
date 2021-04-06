//
//  Dictionary.cpp


#include "Dictionary.h"

#include <fstream>
#include <string>

using namespace std;

Dictionary::Dictionary () {
    m_eCurrentLanguage = NO_LANGUAGE;
	m_iNumWords = 0;
}

Dictionary::~Dictionary () {
}


void Dictionary::setLanguage (Language language) {
    m_eCurrentLanguage = language;
    switch (m_eCurrentLanguage){
        case CATALAN:
            Load("data/Dictionaries/Catalan.dic");
            break;
        case SPANISH:
            Load("data/Dictionaries/Spanish.dic");
            break;
        case ENGLISH:
            Load("data/Dictionaries/English.dic");
            break;
        case NO_LANGUAGE:

            break;
    }
}

void Dictionary::Load (const string& path) {

    m_aWords.clear();
    
    m_iNumWords = 0;
    ifstream file;
    file.open (path);
    if (file.is_open())
    {
        string word;
        file >> word;
		m_aWords.push_back(word);
        m_iNumWords++;
        while (!file.eof())
        {
            file >> word;
			m_aWords.push_back(word);
            //m_aWords[m_iNumWords] = word;
            m_iNumWords++;
        }
        cout << "Num of words: " << m_iNumWords << endl;
        file.close();
    }
}


bool Dictionary::check (const string& word){

    std::vector<string>::iterator it = m_aWords.begin();
	std::vector<string>::iterator itEnd = m_aWords.end();
    for (; it != itEnd; it++) {
        if ((*it).compare(word) == 0) {
            return true;
        }
    }
    return false;
}

/*
//-- Auxiliar function to format dictionary from 
void Dictionary::SaveNewDictionary (const string& pathFile){
    //Save File:
    ofstream fitxer;
    fitxer.open(pathFile);
    for (int i = 0; i < m_iNumWords; i++)
    {
        string word = m_aWords[i];
        std::string::size_type position = word.find('/');
        if (position != std::string::npos)
        {
            word = word.substr(0, position);
        }

        std::transform(word.begin(), word.end(), word.begin(),
                       [](unsigned char c){ return tolower(c); });

        size_t pos = word.find( "á" );
        if ( pos != string::npos ) {
            word.replace( pos, string("á").length(), "a" );
        }
        pos = word.find( "à" );
        if ( pos != string::npos ) {
            word.replace( pos, string("à").length(), "a" );
        }
        pos = word.find( "í" );
        if ( pos != string::npos ) {
            word.replace( pos, string("í").length(), "i" );
        }
        pos = word.find( "ú" );
        if ( pos != string::npos ) {
            word.replace( pos, string("ú").length(), "u" );
        }
        pos = word.find( "ò" );
        if ( pos != string::npos ) {
            word.replace( pos, string("ò").length(), "o" );
        }
        pos = word.find( "ó" );
        if ( pos != string::npos ) {
            word.replace( pos, string("ó").length(), "o" );
        }
        pos = word.find( "é" );
        if ( pos != string::npos ) {
            word.replace( pos, string("é").length(), "e" );
        }
        pos = word.find( "è" );
        if ( pos != string::npos ) {
            word.replace( pos, string("è").length(), "e" );
        }
        pos = word.find( "ü" );
        if ( pos != string::npos ) {
            word.replace( pos, string("ü").length(), "u" );
        }
        pos = word.find( "ï" );
        if ( pos != string::npos ) {
            word.replace( pos, string("ï").length(), "i" );
        }


        fitxer << word << endl;
    }
    fitxer.close();
}

*/
