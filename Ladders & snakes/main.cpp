#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <new>
using namespace std;

class Ladder{
private:
    int debutL;
    int finL;
public:
    void setDebutL(int debut){
        this -> debutL = debut;
    }
    void setFinL(int fin){
        this -> finL = fin;
    }
    int getDebutL(){
        return this->debutL;
    }
    int getFinL(){
        return this->finL;
    }
    Ladder(){
    //echelles
    //un haut d'echelle est forcement entre 81 et 2 ici.
        int ran = rand()% 81 + 1;
        this -> debutL = ran;
        while (ran==this -> debutL || (ran > 99 || ran<this->debutL) || this->debutL+10>ran || ran>this->debutL+35){
            ran = rand()% 99+1;
        }
        this -> finL =ran;
    }
};


class Snake{
private:
    int debutS;
    int finS;
public:
    void setDebutS(int debut){
        this -> debutS = debut;
    }
    void setFinS(int fin){
        this -> finS = fin;
    }
    int getDebutS(){
        return this->debutS;
    }
    int getFinS(){
        return this->finS;
    }
    Snake(){
    //serpent
    //un haut de serpent est forcement entre 99 et 11 ici.
        int ran=0;
        while(ran==0 || ran >99 || ran < 11)
            ran = rand()% 99 + 1;
        this -> debutS = ran;
        while (ran==this -> debutS || (ran>this->debutS || ran < 1) || this->debutS-10<ran || ran<this->debutS-35){
            ran = rand()% 89+1;
        }
        this -> finS =ran;
    }
};

class Joueur{
//DOCUMENTATION
//La classe joueur permet de créer, de donner un nom, de faire gagner et se déplacer le joueur.
private:
    int position;
public:
    int getposition(){
        return this->position;
    }
    void setposition(int resultat){
        this -> position=resultat;
    }
    void deplacement(){
        this-> position+=lanceDe();
    }
    bool gagne(int result){
        bool rep=false;
        if (result>=100){
            rep=true;
        }
        return rep;
    }
    int lanceDe(){
    //DOCUMENTATION
    //La fonction de renvoie une valeur aléatoire entre 1 et 6.
    return rand()% 6 + 1;
    }
    Joueur(){
        this -> position = 0;
    }
};

int main()
{

    //Création des échelles
    cout << "combien voulez vous d'echelles ?(si votre choix est negatif ou superieure a 24, la valeur par defaut sera :7)" << endl;
    int nbL=7;
    cin >> nbL;
    if (nbL<0 || nbL>24){
        cout << "!! erreur !! ->7 echelles" << endl;
        nbL=7;
    }

    //Création des serpents
    cout << "combien voulez vous de serpents ?(si votre choix est negatif ou superieure a 24, la valeur par defaut sera :9)" << endl;
    int nbS=9;
    cin >> nbS;
    if (nbS<0 || nbS>24){
        cout << "!! erreur !! ->9 serpents" << endl;
        nbS=9;
    }

    //Création des joueurs
    int nbjoueur = 0;
    cout << "combien il y a t'il de joueurs ?" << endl;
    cin >> nbjoueur;
    Joueur * joueur = new (std::nothrow) Joueur[nbjoueur];
    cout << "le(s) " << nbjoueur << " joueur(s) est/sont bien cree(s)" << endl;

    Ladder * ladders = new (std::nothrow) Ladder[nbL];

    Snake * snakes = new (std::nothrow) Snake[nbS];

    bool victoire=false;

    //jeu
    int tour =0;
    do{
        tour+=1;

        cout << "tour de jeu n " << tour << endl;
        for(int i=0;i<nbjoueur;i++){
            joueur[i].deplacement();
        }
        for(int i=0;i<nbS;i++){
            for(int j=0;j<nbjoueur;j++){
                if (snakes[i].getDebutS()==joueur[j].getposition()){
                    joueur[j].setposition(snakes[i].getFinS());
                    cout << "le joueur n " << j+1 << " tombe a cause d'un serpent.."<<endl;
                }
            }
        }

        for(int i=0;i<nbL;i++){
            for(int j=0;j<nbjoueur;j++){
                if (ladders[i].getDebutL()==joueur[j].getposition()){
                    joueur[j].setposition(ladders[i].getFinL());
                    cout << "le joueur n " << j+1 << " monte tout en haut d'une echelle !"<<endl;
                }
            }
        }
        for (int i=0;i<nbjoueur;i++){
            cout << "le Joueur n " << i+1 << " est a la case :" << joueur[i].getposition()<<endl;
        }
        for(int i=0;i<nbjoueur;i++){
                int place=joueur[i].getposition();
            if ((joueur[i].gagne(place))==true){
                victoire=true;
                cout << "Le joueur n "<< i+1 << " a gagne !" << endl;
                break;
            }
        }
    }while(victoire==false);
    return 0;
}

