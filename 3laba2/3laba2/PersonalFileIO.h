#pragma once
#include<locale.h>
#include<string>
#include <iostream>
#include<fstream>
#include"Personal.h"
#include"Barman.h"
#include"Concierge.h"

template<typename T>
class PersonalFileIO
{
public:
    static void save(T person);
    static void load(const std::string& filename);
    friend std::ostream& operator<<(std::ostream& out, const T& personal);
    friend std::istream& operator>>(std::istream& is, T& personal);
};
template class PersonalFileIO<Barman>;
template class PersonalFileIO<Concierge>;