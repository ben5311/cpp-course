#include <stdio.h>
#include <string.h>
#include <iostream>
#include "ident.h"

int main(int argc, char *argv[]) {
  char file[200], *p=file;
  char cmd[200];

  strcpy(file,""); // Leerstring
  strcpy(cmd, "");

  // Baue Dateinamen
  // ===============
  // Kopiere Kommandozeilenparameter
  if (argc>1) strcat(file, argv[1]);
  // Kopiere MatrNr
  strcat(file, matse_matrnr.c_str());
  strcat(file, "-");
  // Kopiere Namen
  strcat(file, matse_name.c_str());
  // Wandle blank in _
  while(*p++) { if(*p==' ') *p='_'; }
  // Dateiendung
  strcat(file, ".zip");
  
  // Baue Shell-Command
  // zip-Befehl
  // strcat(cmd, "zip ");
  strcat(cmd, "7z a ");
  // Ausgabe-Dateinamen
  strcat(cmd, file);
  // Dateien, die zu zippen sind (alle ohne dozip)
  // strcat(cmd, " * -x dozip");
  strcat(cmd, " * -x!dozip* -x!*.zip");
  std::cout << cmd << std::endl;
  // Erzeuge ZIP-Datei
  system(cmd);
}
