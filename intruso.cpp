#include <string>
#include <vector>
#include <iostream>
#include "intruso.hpp"

void Intruso::set_senha_vazada(std::string vazou){
    _entradaLetra[_numEntradas]= new char[6];
    _entradaNumerica[_numEntradas] = new int[10];
    for(int i=0; i<10; i++){
        _entradaNumerica[_numEntradas][i] = (int)vazou[i];
    }
    int a=0;
    for(int i =10; i<16;i++){
        _entradaLetra[_numEntradas][a] = vazou[i];
        a++;
    }
}

std::string Intruso::crack_senha(){
    _descobre.push_back(-1);
    _descobre.push_back(-1);
    for(int i=0;i<6;i++){
        std::cout << "entrei 1 for crack" << std::endl;
        std::cout << "numero de entradas salvas " << _numEntradas << std::endl;
        int l = 0;
        for(int j=0; j<_numEntradas ;j++){
            std::cout << "entrei 2 for crack" << std::endl;
            char a = _entradaLetra[j][i];
            switch (a){
                case 'A':
                    std::cout << "entrei case A" << std::endl;
                    _descobre[l] = _entradaNumerica[j][0];
                    l++;
                    _descobre[l] = _entradaNumerica[j][1];
                    l++;
                    break;
                
                case 'B':
                    std::cout << "entrei case B" << std::endl;
                    _descobre[l] = _entradaNumerica[j][2];
                    l++;
                    std::cout << _entradaNumerica[j][2] << std::endl;
                    _descobre[l] = _entradaNumerica[j][3];
                    std::cout << _entradaNumerica[j][3] << std::endl;
                    l++;
                    break;

                case 'C':
                    std::cout << "entrei case c" << std::endl;
                    _descobre[l] = _entradaNumerica[j][4];
                    l++;
                    _descobre[l] = _entradaNumerica[j][5];
                    l++;
                    break;

                case 'D':
                    std::cout << "entrei case D" << std::endl;
                    _descobre[l] = _entradaNumerica[j][6];
                    l++;
                    _descobre[l] = _entradaNumerica[j][7];
                    l++;
                    break;

                case 'E':
                    std::cout << "entrei case E" << std::endl;
                    _descobre[l] = _entradaNumerica[j][8];
                    l++;
                    _descobre[l] = _entradaNumerica[j][9];
                    l++;
                    break;
                    }
                    std::cout << "sai do switch" << std::endl;
                    std::cout << _descobre[l-1] << _descobre[l] << std::endl;
        }
        std::cout << "terminei switch" << std::endl;
        for(int n=0; n<10 ;n++){
            int a=0;
            std::cout << "entrei 1 for pos switch " << n << std::endl;
            for(int c=0; c<_numEntradas*2 ;c++){
                std::cout << "entrei 2 for pos switch " << c << std::endl;
                std::cout << _descobre[c] << std::endl;
                if((_descobre[c]) == n){
                    std::cout << "entrei if do for" << std::endl;
                    a++;
                }
            }
            if(a==_numEntradas){
                _senha.push_back(n);
                break;
            }
        }
        apagaDescobre();
    }
    for(int i = 0; i<6; i++){
        std::cout << _senha[i] << std::endl;
    }
    std::string senha={""};
    for(int i=0;i<6;i++){
        senha += std::to_string(_senha[i]);
    }
return senha;
}