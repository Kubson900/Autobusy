/** @file */

#ifndef FUN_H
#define FUN_H

#include "struct.h"

/** Funkcja dodaje przystanki do listy
@param pHead Reprezentant listy przystanków
@param StopName Nazwa przystanku
@return WskaŸnik na przystanek
*/
Stop* Add(Stop*& pHead, const std::string& StopName);

/** Funkcja dodaje liniê do konkretnego przystanku
@param pHead Reprezentant listy linii
@param LineIndex Numer linii
@return WksaŸnik na liniê
*/
Line* Add(Line*& pHead, int& LineIndex);

/** Funkcja dodaje godzinê oraz minutê do konkretnej linii
@param pHead Reprezentant listy godzin i minut
@param hour Godzina
@param minute Minuta
@return WksaŸnik na godziny i minuty
*/
Time* Add(Time*& pHead, int hour, int minute);

/** Funkcja wyœwietla przystanek
@param stream Strumieñ wyjœciowy
@param pHead Reprezentant listy przystanków
*/
void ShowStop(std::ostream& stream, Stop*& pHead);

/** Funkcja wczytuje z wejœcia liniê
@param pHeadStop Reprezentant listy przystanków
@param argc Liczba elementów podana w konsoli
@param argv WskaŸnik na tablicê znaków z kosoli
*/
void UploadLine(Stop*& pHeadStop, int argc, char* argv[]);

/** Funkcja zapisuje przystanki do plików tekstowych
@param pHeadStop Reprezentant listy przystanków
*/
void StopToFile(Stop*& pHeadStop);

/** Funkcja usuwa godziny i minuty
@param pHead Reprezentant listy godzin i minut
*/
void DeleteTime(Time*& pHead);

/** Usuwa liniê
@param pHead Reprezentant listy linii
*/
void DeleteLine(Line*& pHead);

/** Funkcja usuwa wszystko
@param pHead Reprezentant listy przystanków
*/
void DeleteAll(Stop*& pHead);

/** Funkcja sprawdza poprawnoœæ wprowadzonych danych w kosoli
@param argc Liczba elementów podana w konsoli
@param argv WskaŸnik na tablicê znaków z kosoli
@return Wartoœæ 1 je¿eli dane zosta³y wprowadzone poprawnie
*/
bool Przelacznik(int argc, char* argv[]);

#endif
