/** @file */

#ifndef STRUCT_H
#define STRUCT_H

/**
 Struktura opisuj�ca godzin� i minut� elementu linii
 */
struct Time
{
    /** Godzina */
    int hour;
    /** Minuta */
    int minute;
    /** Wska�nik na kolejny element listy */
    Time* pNextTime;
};

/**
 Struktura opisuj�ca lini�
 */
struct Line
{
    /** numer linii */
    int LineIndex;
    /** wska�nik na list� zawieraj�c� godziny i minuty */
    Time* pHeadTime;
    /** Wska�nik na kolejny element listy */
    Line* pNextLine;
};

struct Stop
{
    /** nazwa przystanku */
    std::string StopName;
    /** wska�nik na list� linii */
    Line* pHeadLine;
    /** wska�nik na nast�pny przystanek */
    Stop* pNextStop;
};

#endif