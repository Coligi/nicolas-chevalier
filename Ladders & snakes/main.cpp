#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <new>
using namespace std;

bool verif(int nombre,int *tableDeVerif,int nbSL);
int lanceDe();


class Ladder{
private:
    int numero;
    int debutL;
    int finL;
public:
    void setNumero(int num){
        this -> numero = num;
    }
    void setDebutL(int debut){
        this -> debutL = debut;
    }
    void setFinL(int fin){
        this -> finL = fin;
    }
    int getNumero(){
        return this->numero;
    }
    int getDebutL(){
        return this->debutL;
    }
    int getFinL(){
        return this->finL;
    }
    Ladder(){
    //echelles
        int ran = rand()% 81 + 21; //un haut d'echelle est forcement entre 81 et 2 ici.
        this -> debutL = ran;
        while (ran==this -> debutL || (ran > 99 || ran < 1)){
            int maxi=this -> debutL+35;
            int mini=this -> debutL+10;
            ran = rand()% maxi+mini;
        }
        this -> finL =ran;
    }
};


class Snake{
private:
    int numero;
    int debutS;
    int finS;
public:
    void setNumero(int num){
        this -> numero = num;
    }
    void setDebutS(int debut){
        this -> debutS = debut;
    }
    void setFinS(int fin){
        this -> finS = fin;
    }
    int getNumero(){
        return this->numero;
    }
    int getDebutS(){
        return this->debutS;
    }
    int getFinS(){
        return this->finS;
    }
    Snake(){
    //serpent
        int ran = rand()% 99 + 11; //un haut de serpent est forcement entre 99 et 11 ici.
        this -> debutS = ran;
        while (ran==this -> debutS || (ran > 99 || ran < 1)){
            int maxi=this -> debutS-10;
            int mini=this -> debutS-35;
            ran = rand()% maxi+mini;
        }
        this -> finS =ran;
    }
};

class Joueur{
//DOCUMENTATION
//La classe joueur permet de créer et de faire ce déplacer le joueur.
private:
    int position;
public:
    int getposition(){
        return this->position;
    }
    void setposition(int resultat){
        this -> position+=resultat;
    }
    void deplacement(){
        setposition(lanceDe());
    }
    bool gagne(int result){
        if (result>=100){
            return true;
        }
        else{
            return false;
        }

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


    cout << "combien voulez vous d'echelles ?(si entree negative ou superieure a 24 :5)" << endl;
    int nbL=5;
    cin >> nbL;
    if (nbL<0 || nbL>24){
        nbL=5;
    }

    cout << "combien voulez vous de serpents ?(si entree negative ou superieure a 24 :5)" << endl;
    int nbS=5;
    cin >> nbS;
    if (nbS<0 || nbS>24){
        nbS=5;
    }

    int nbspe=(nbS+nbL)*2;

    int *tabDesSpecial[nbspe];
    for (int o=0;o>nbspe;o++){
        tabDesSpecial[o]==0;
    }
    int nbjoueur = 0;
    cout << "combien il y a t'il de joueurs ?" << endl;
    cin >> nbjoueur;
    Joueur * joueur = new (std::nothrow) Joueur[nbjoueur];
    cout << "le(s) " << nbjoueur << " joueur(s) est/sont bien cree(s)" << endl;

    Ladder * ladders = new (std::nothrow) Ladder[nbL];

    Snake * snakes = new (std::nothrow) Snake[nbS];

    bool victoire=false;

    //jeu
    do{
        for(int i=0;i>nbjoueur;i++){
            joueur[i].deplacement();
        }

        for(int i=0;i>nbS;i++){
            for(int j=0;j>nbjoueur;j++){
                if (snakes[i].getDebutS()==joueur[j].getposition()){
                    joueur[j].setposition(snakes[i].getFinS());
                }
            }
        }

        for(int i=0;i>nbL;i++){
            for(int j=0;j>nbjoueur;j++){
                if (ladders[i].getDebutL()==joueur[j].getposition()){
                    joueur[j].setposition(ladders[i].getFinL());
                }
            }
        }
        for(int i=0;i>nbjoueur;i++){
            if (joueur[i].gagne(joueur[i].getposition()==true)){
                victoire=true;
                break;
            }
        }
    }while(victoire==false);
    cout << "Le joueur"<< endl;
    cout << "Hello world!" << endl;
    return 0;
}

