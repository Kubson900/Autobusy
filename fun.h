/** @file */

#ifndef FUN_H
#define FUN_H

#include "struct.h"

/** Funkcja dodaje przystanki do listy
@param pHead Reprezentant listy przystank�w
@param StopName Nazwa przystanku
@return Wska�nik na przystanek
*/
Stop* Add(Stop*& pHead, const std::string& StopName);

/** Funkcja dodaje lini� do konkretnego przystanku
@param pHead Reprezentant listy linii
@param LineIndex Numer linii
@return Wksa�nik na lini�
*/
Line* Add(Line*& pHead, int& LineIndex);

/** Funkcja dodaje godzin� oraz minut� do konkretnej linii
@param pHead Reprezentant listy godzin i minut
@param hour Godzina
@param minute Minuta
@return Wksa�nik na godziny i minuty
*/
Time* Add(Time*& pHead, int hour, int minute);

/** Funkcja wy�wietla przystanek
@param stream Strumie� wyj�ciowy
@param pHead Reprezentant listy przystank�w
*/
void ShowStop(std::ostream& stream, Stop*& pHead);

/** Funkcja wczytuje z wej�cia lini�
@param pHeadStop Reprezentant listy przystank�w
@param argc Liczba element�w podana w konsoli
@param argv Wska�nik na tablic� znak�w z kosoli
*/
void UploadLine(Stop*& pHeadStop, int argc, char* argv[]);

/** Funkcja zapisuje przystanki do plik�w tekstowych
@param pHeadStop Reprezentant listy przystank�w
*/
void StopToFile(Stop*& pHeadStop);

/** Funkcja usuwa godziny i minuty
@param pHead Reprezentant listy godzin i minut
*/
void DeleteTime(Time*& pHead);

/** Usuwa lini�
@param pHead Reprezentant listy linii
*/
void DeleteLine(Line*& pHead);

/** Funkcja usuwa wszystko
@param pHead Reprezentant listy przystank�w
*/
void DeleteAll(Stop*& pHead);

/** Funkcja sprawdza poprawno�� wprowadzonych danych w kosoli
@param argc Liczba element�w podana w konsoli
@param argv Wska�nik na tablic� znak�w z kosoli
@return Warto�� 1 je�eli dane zosta�y wprowadzone poprawnie
*/
bool Przelacznik(int argc, char* argv[]);

#endif
