/** @file */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

#include "fun.h"

Stop* Add(Stop*& pHead, const std::string& StopName)
{
    bool exists = false;
    Stop* p;
    if (pHead == nullptr or pHead->StopName >= StopName)
    {
        if (pHead != nullptr && pHead->StopName == StopName)
        {
            exists = true;
        }
        if (!exists)
        {
            pHead = new Stop{ StopName, nullptr, pHead };
        }
        return pHead;
    }
    else
    {
        p = pHead;
        while (p->pNextStop != nullptr
            and p->pNextStop->StopName < StopName)
        {
            p = p->pNextStop;
        }
        if (p->pNextStop != nullptr
            and p->pNextStop->StopName == StopName)
        {
            exists = true;
        }
        if (!exists)
        {
            p->pNextStop = new Stop{ StopName, nullptr, p->pNextStop };
        }
        return p->pNextStop;
    }
}

Line* Add(Line*& pHead, int& LineIndex)
{
    bool exists = false;
    Line* p;
    if (pHead == nullptr or pHead->LineIndex >= LineIndex)
    {
        if (pHead != nullptr && pHead->LineIndex == LineIndex)
        {
            exists = true;
        }
        if (!exists)
        {
            pHead = new Line{ LineIndex,nullptr,pHead };
        }
        return pHead;
    }
    else
    {
        p = pHead;
        while (p->pNextLine != nullptr
            and p->pNextLine->LineIndex < LineIndex)
        {
            p = p->pNextLine;
        }
        if (p->pNextLine != nullptr
            and p->pNextLine->LineIndex == LineIndex)
        {
            exists = true;
        }
        if (!exists)
        {
            p->pNextLine = new Line{ LineIndex,nullptr,p->pNextLine };
        }
        return p->pNextLine;
    }
}

Time* Add(Time*& pHead, int hour, int minute)
{
    Time* p;
    if (pHead == nullptr)
    {
        pHead = new Time{ hour,minute,pHead };
        return pHead;
    }
    else
    {
        auto p = pHead;
        while (p->pNextTime != nullptr)
        {
            p = p->pNextTime;
        }
        p->pNextTime = new Time{ hour,minute,p->pNextTime };
    }
}

void ShowStop(std::ostream& stream, Stop*& pHead)
{
    char character = ':';
    stream << pHead->StopName << std::endl;
    for (int i = 0; i < pHead->StopName.length(); i++)
    {
        stream << '=';
    }
    stream << std::endl << std::endl;
    auto p = pHead->pHeadLine;
    while (p)
    {
        stream << "LINIA " << p->LineIndex << " " << std::endl << std::endl;
        auto k = p->pHeadTime;
        while (k)
        {
            stream << std::setfill('0') << std::setw(2) << k->hour << ':'
                   << std::setfill('0') << std::setw(2) << k->minute;
            if (k->pNextTime != nullptr)
            {
                stream << ", ";
            }
            else
            {
                stream << std::endl << std::endl;

            }
            k = k->pNextTime;
        }
        p = p->pNextLine;
    }
}

void UploadLine(Stop*& pHeadStop, int argc, char* argv[])
{
    for (int i = 2; i < argc; i++)
    {
        std::string temp = argv[i];
        std::ifstream file(temp);
        std::string fileLine;
        int LineIndex;
        while (std::getline(file, fileLine))
        {
            if (fileLine.length() > 6 && fileLine.substr(0, 5) == "LINIA")
            {
                LineIndex = std::stoi(fileLine.substr(6));
            }
            else
            {
                std::istringstream iss(fileLine);
                std::string StopName;
                int hour, minute;
                char character;
                if (iss >> hour >> character >> minute >> StopName)
                {
                    auto pStop = Add(pHeadStop, StopName);
                    auto pLine = Add(pStop->pHeadLine, LineIndex);
                    Add(pLine->pHeadTime, hour, minute);
                }
            }
        }
        file.close();
    }
}

void StopToFile(Stop*& pHeadStop)
{
    if (pHeadStop)
    {
        std::string FileName = pHeadStop->StopName;
        std::ofstream file(FileName, std::ios_base::app);
        if (file)
        {
            ShowStop(file, pHeadStop);
            file.close();
        }
        StopToFile(pHeadStop->pNextStop);
    }
}

void DeleteTime(Time*& pHead)
{
    while (pHead)
    {
        auto p = pHead;
        pHead = pHead->pNextTime;
        delete p;
    }
    pHead = nullptr;
}

void DeleteLine(Line*& pHead)
{
    while (pHead)
    {
        DeleteTime(pHead->pHeadTime);
        auto p = pHead;
        pHead = pHead->pNextLine;
        delete p;
    }
    pHead = nullptr;
}

void DeleteAll(Stop*& pHead)
{
    while (pHead)
    {
        DeleteLine(pHead->pHeadLine);
        auto p = pHead;
        pHead = pHead->pNextStop;
        delete p;
    }
    pHead = nullptr;
}

bool Przelacznik(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cout << "Blad skladniowy! Za malo elementow!" << std::endl;
        return false;
    }
    else
    {
        std::string a = argv[1];
        if (a != "-i")
        {
            std::cout << "Przelacznik -i powinien znajdowac sie od razu za nazwa programu!" << std::endl;
            return false;
        }
        else
        {
            if (argc == 2)
            {
                std::cout << "Nie podano plikow wejsciowych!" << std::endl;
                return false;
            }
            else
            {
                std::string tmp;
                for (int i = 2; i < argc; i++)
                {
                    tmp = argv[i];
                    if (tmp.substr(tmp.size() - 4) != ".txt")
                    {
                        std::cout << "Zly format! Plik powinien byc z rozszerzeniem .txt!" << std::endl;
                        return false;
                    }
                    else
                    {
                        std::cout << "Poprawnie wprowadzono dane!" << std::endl;
                        return true;
                    }
                }
            }
        }
    }
}
