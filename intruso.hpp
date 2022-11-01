#include <string>
#include <vector>

class Intruso{
    private:

    int _numEntradas = 0;
    std::vector<int*> _entradaNumerica;
    std::vector<char*> _entradaLetra;
    std::vector<int> _senha;
    std::vector<int> _descobre;

    public:
        void set_senha_vazada(std::string vazou);
        std::string crack_senha();
};