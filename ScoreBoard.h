#define ScoreBoard_INCLUDED
#ifdef ScoreBoard_INCLUDED

#include <iostream>

class ScoreBoard
{
private:
    int _size = 5;
    int* _scoreTab = new int[_size];
    std::string* _nameTab = new std::string[_size];
    std::string _messageErreur;
    bool _error = false;

public:
    ScoreBoard();
    ~ScoreBoard();

    void RedimTab();
    void AddScore();
    void RemoveScore();
    void DisplayTab();
};

ScoreBoard::~ScoreBoard()
{
    if(_scoreTab != nullptr && _nameTab != nullptr)
    {
        delete[] _scoreTab;
        delete[] _nameTab;
    }
}

ScoreBoard::ScoreBoard()
{
    for (int i = 0; i < _size; i++)
    {
        _nameTab[i] = "Noob";
        _scoreTab[i] = 0;
    }   
}

void ScoreBoard::RedimTab()
{
    int _nouvelleTaille;
    int _choix;
    bool _ajouter;

    std::cout << "\n0- Ajouter"<< "     " << "1- Retirer" << std::endl;
    std::cout << "\n--> ";
    std::cin >> _choix;

    if(_choix == 0)
    {
        _ajouter = true;
    }
    else if(_choix == 1)
    {
        _ajouter = false;
    }
    else
    {
        return;
    }

    std::cout << "Entrer le nombre de scores de la plage : ";
    std::cin >> _nouvelleTaille;

    if(_nouvelleTaille < 0)
    {
        _error = true;
        _messageErreur = "La valeur ne peut etre negative !";
        return;
    }

    if(_ajouter == true)
    {
        _nouvelleTaille = _size + _nouvelleTaille;
    }
    else
    {
        _nouvelleTaille = _nouvelleTaille;
    }
    
    int* _nouveauScoreTab = new int[_nouvelleTaille];
    std::string* _nouveauNameTab = new std::string[_nouvelleTaille];

    if(_nouveauNameTab == nullptr || _nouveauScoreTab == nullptr)
    {
        _error = true;
        _messageErreur = "Erreur au niveau de l'allocation de l'espace !";
        return;
    }

    for (int i = 0; i < _nouvelleTaille; i++)
    {
        _nouveauNameTab[i] = "Noob";
        _nouveauScoreTab[i] = 0;
    }

    if(_ajouter == true)
    {
        for (int i = 0; i < _size; i++)
        {
        _nouveauScoreTab[i] = _scoreTab[i];
        _nouveauNameTab[i] = _nameTab[i];
        }
    }
    else
    {
        for (int i = 0; i < _nouvelleTaille; i++)
        {
        _nouveauScoreTab[i] = _scoreTab[i];
        _nouveauNameTab[i] = _nameTab[i];
        }
    }

    delete[] _scoreTab;
    delete[] _nameTab;

    _scoreTab = _nouveauScoreTab;
    _nameTab = _nouveauNameTab;

    _size = _nouvelleTaille;
}

void ScoreBoard::AddScore()
{
    int _premierIndexVide;
    std::string _name;
    int _score;
    int _choix;
    bool _modifier;

    std::cout << "\n0- Modifier"<< "     " << "1- Remplir" << std::endl;
    std::cout << "\n--> ";
    std::cin >> _choix;

    if(_choix == 0)
    {
        _modifier = true;
    }
    else if(_choix == 1)
    {
        _modifier = false;
    }
    else
    {
        return;
    }
    
    if(_modifier == true)
    {
        if(_size == 0)
        {
            _error = true;
            _messageErreur = "Aucun score a modifier !";
            return;
        }

        int index;

        std::cout << "Entrer l'index du score que vous voullez modifier : ";
        std::cin >> index;

        if(index >= _size || index < 0)
        {
            _error = true;
            _messageErreur = "Index Invalide !";
            return;
        }

        std::cout << "Entrer la nouvelle valeur du score : ";
        std::cin >> _score;

        _scoreTab[index] = _score;
    }
    else
    {
        for (int i = 0; i < _size; i++)
        {
            if(_nameTab[i] == "Noob")
            {
                _premierIndexVide = i;
                break;
            }
        }

    std::cout << "Entrer le nom du Player (Players-- 3lettres) : ";
    std::cin >> _name;

    if(_name == "Noob" || _name.length() > 3)
    {
        _error = true;
        _messageErreur = "Nom invalide ! (doit etre diff de Noob, Verifiez la longueur)";
        return;
    }
    else
    {
        _nameTab[_premierIndexVide] = _name;
    }

    std::cout << "Entrer le score correspondant : ";
    std::cin >> _score;

    _scoreTab[_premierIndexVide] = _score;
    }

}

void ScoreBoard::RemoveScore()
{
    if(_size == 0)
    {
        _error = true;
        _messageErreur = "Aucun score a supprimer !";
        return;
    }

    int index;

    std::cout << "Entrer l'index du score que vous voullez supprimer : ";
    std::cin >> index;

    if(index >= _size || index < 0)
    {
        _error = true;
        _messageErreur = "Index Invalide !";
        return;
    }
    else
    {
        for (int i = index; i < _size - 1; i++)
        {
            _scoreTab[i] = _scoreTab[i + 1];
            _nameTab[i] = _nameTab[i + 1];
        }
        

        _size--;   
    }
}

void ScoreBoard::DisplayTab()
{
    system("CLS");

    if(_error == true)
    {
        std::cout << "\033[31m" << _messageErreur << "\033[0m" << std::endl << std::endl;
    }
    
    std::cout << "      TABLEAU DES SCORES"  << " (" << _size << ")" << std::endl;
    std::cout << "Index     " << " Player   " << "      Score" << std::endl;

    for (int i = 0; i < _size; i++)
    {
        std::cout << i << "-          " << _nameTab[i] << "           " << _scoreTab[i] << std::endl;
    }

    std::cout << "\n1- Ajouter/Retirer une plage de score" << "     " << "2- Remplir/Modifier un score" << "     " << "3- Supprimer un score" << std::endl;
    std::cout << "\n4- Quitter" << "        5- Retour" << std::endl;
    std::cout << "\n--> ";

    _error = false;
}

#endif