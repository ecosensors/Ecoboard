/*
* That file is underdevelopment. Do not use it for now
*/

#ifndef Ecoboard_h
#define Ecoboard_h

 #include <SdFat.h>			// For SD Card
 #include <SdFatUtil.h>		// For SD Card

#include "Arduino.h"

#define FILESIZE 12
#define SD_PATHSIZE 20

class Ecoboard{
 	protected:
 		

 	private:
 		/*
 		* SD Card
 		*/
 		SdFat _sd;
 		bool _isSdEnable;
 		bool _isSdReady;
 		int _carddetect;
		int _chipselect;
		char _sd_pathLog[SD_PATHSIZE];
		char _logFile[SD_PATHSIZE+FILESIZE];
		bool _sd_begin();
		void _sd_showCwd();
		bool _sd_checkCard();
		int _sd_writeln(char * fileName, char const * text);
		int _sd_write(const char * fileName, char const * text);
		int _sd_write(char * fileName, const __FlashStringHelper * text);
		int _sd_writeln(char * fileName, const __FlashStringHelper * text);
		int _sd_write(const char * fileName, const __FlashStringHelper * text, bool ln);
		int _sd_write(const char * fileName, char const * text, bool ln);
	

	public:
		Ecoboard(bool isSdEnable);
		int begin();

		/*
		* SD Card
		*/
		void listFiles(const char * folder);
		int sd_init_logFile(int16_t y, int16_t m, int16_t d, int16_t h, int16_t mn, int16_t s);
		int sd_writeln(char const * text);
		int sd_write(char const * text);
		int sd_write(int16_t text);


 };
 #endif