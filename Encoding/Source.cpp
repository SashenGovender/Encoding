#include <iostream>
#include <Windows.h>

char* ASCII_to_UTF8(char* ansciiString);
char* UTF8_to_ASCII(char* utf8String);

int main()
{
   char ascii[] = "sashená";
   char* utf8Result = ASCII_to_UTF8(ascii);
   std::cout << "Ascii: "<< ascii << std::endl;
   std::cout << "utf8: "<< utf8Result << std::endl;

   char utf8[] = "sashenÃ¡";
   char* ansciiResult = UTF8_to_ASCII(utf8);
   std::cout << "utf8: " << utf8 << std::endl;
   std::cout << "Ascii: " << ansciiResult << std::endl;

   system("pause");
   return 0;
}

char* ASCII_to_UTF8(char* ansciiString)
{
   int wcsLen = ::MultiByteToWideChar(CP_ACP, NULL, ansciiString, -1, NULL, 0);//CP_ACP - CodePage - what conversion is to be done. ie convert to wide char using the ansii code page
   wchar_t* ansciiWideString = new wchar_t[wcsLen];
   ::MultiByteToWideChar(CP_ACP, NULL, ansciiString, -1, ansciiWideString, wcsLen);


   int utf8Len = ::WideCharToMultiByte(CP_UTF8, NULL, ansciiWideString, -1, NULL, 0, NULL, NULL);//CP_UTF8 - CodePage - what conversion is to be done. ie convert to multibyte char using the utf8 code page
   char* utf8 = new char[utf8Len];
   ::WideCharToMultiByte(CP_UTF8, NULL, ansciiWideString, -1, utf8, utf8Len, NULL, NULL);

   delete[] ansciiWideString;
   return utf8;
}

char* UTF8_to_ASCII(char* utf8String)
{
   int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, utf8String, -1, NULL, 0);//CP_ACP - CodePage - what conversion is to be done. ie convert to wide char using the ansii code page
   wchar_t* utf8WideString = new wchar_t[wcsLen];
   ::MultiByteToWideChar(CP_UTF8, NULL, utf8String, -1, utf8WideString, wcsLen);


   int utf8Len = ::WideCharToMultiByte(CP_ACP, NULL, utf8WideString, -1, NULL, 0, NULL, NULL);//CP_UTF8 - CodePage - what conversion is to be done. ie convert to multibyte char using the utf8 code page
   char* anscii = new char[utf8Len];
   ::WideCharToMultiByte(CP_ACP, NULL, utf8WideString, -1, anscii, utf8Len, NULL, NULL);

   delete[] utf8WideString;
   return anscii;
}
