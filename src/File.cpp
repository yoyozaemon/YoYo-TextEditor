#include "File.h"
#include "RawMode.h"

// Python Keywords

char *PY_HL_extensions[]={(char*)".py",(char*)".pyc",(char*)"python",NULL};
char *PY_HL_keywords[]={(char*)"from","def","if","while","for","break","return","continue","else","elif","import","try","except","in","or","and","is","not","with","as","True","False","None","class" /* python Types*/ "int|","str|","unicode|","dict|","float|","repr|","long|","eval|","tuple|","list|","set|","frozenset|","chr|","unichr|","ord|","hex|",NULL};