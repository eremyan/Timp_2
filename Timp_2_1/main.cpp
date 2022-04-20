#include <iostream>
#include "modalphacipher.h"
#include <locale>
#include <cctype>
#include <string>
using namespace std;
int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring key;
    wstring text;
    unsigned op;
    do {
        wcout<<L"Установите режим работы: 1-шифрование, 2-расшифрование, 0-выход: ";
        wcin>>op;
        if(op==1) {
            wcout<<L"Введите ключ: ";
            wcin.get();
            getline(wcin,key);
            try {
                modAlphaCipher cipher(key);
                wcout<<L"Ключ установлен\n";
                wcout<<L"Введите текст для шифрования:";
                wcin>>text;
                wstring ciphertext=cipher.encrypt(text);
                wcout<<ciphertext<<endl;

            }
            catch(cipher_error& e) {
                wcout<<e.what()<<endl;
            }

        }
        if(op==2) {
            wcout<<L"Введите ключ: ";
            wcin.get();
            getline(wcin,key);
            try {
                modAlphaCipher cipher(key);
                wcout<<L"Ключ установлен\n";
                wcout<<L"Введите текст для расщифрования:";
                wcin>>text;
                wstring decryptedtext=cipher.decrypt(text);
                wcout<<decryptedtext<<endl;

            } catch(cipher_error& e) {
                wcout<<e.what()<<endl;
            }
        }
        if(op==0) {
            wcout<<L"Завершение программы..."<<endl;
            exit(0);
        } else if((op>2) or (op<0)) {
            wcout<<L"Неверная команда"<<endl;
            exit(1);

        }

    }   while (op!=0);
    return 0;

}