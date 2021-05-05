/** @file */

#ifndef STRUCT_H
#define STRUCT_H

/**
 Struktura opisuj¹ca godzinê i minutê elementu linii
 */
struct Time
{
    /** Godzina */
    int hour;
    /** Minuta */
    int minute;
    /** WskaŸnik na kolejny element listy */
    Time* pNextTime;
};

/**
 Struktura opisuj¹ca liniê
 */
struct Line
{
    /** numer linii */
    int LineIndex;
    /** wskaŸnik na listê zawieraj¹c¹ godziny i minuty */
    Time* pHeadTime;
    /** WskaŸnik na kolejny element listy */
    Line* pNextLine;
};

struct Stop
{
    /** nazwa przystanku */
    std::string StopName;
    /** wskaŸnik na listê linii */
    Line* pHeadLine;
    /** wskaŸnik na nastêpny przystanek */
    Stop* pNextStop;
};

#endif