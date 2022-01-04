/*
 Programme : Le jeu des multiples
 But :  Jeu qui consiste à saisir une liste de multiples respectant la contrainte suivante : chaque multiple saisi doit être un multiple supérieur à la valeur précédente
 Date de dernière modification : 02/10/2021
 Auteur : Cédric ETCHEPARE, Samuel HENTRICS LOISTINE
*/
 
#include <iostream>
using namespace std;
 
int main(void)
{
    // VARIABLES ***************************************************************************************************************************************************************
    // *************************************************************************************************************************************************************************
    int difficulteJeu; // Permet à l'utilisateur de saisir la difficulté du jeu
    unsigned int scoreJoueur;      // Contient le nombre de bonnes réponses durant la partie
    unsigned long int multipleDemande;  // Multiple qui sera demandé au joueur
    unsigned long int multipleClavier;  // Multiple qui sera saisi par l'utilisateur sur le clavier
    bool erreurMultiple;           // Permet de reconnaitre l'erreur si le joueur inscrit un nombre incorrect
 
    // TRAITEMENTS**************************************************************************************************************************************************************
    // *************************************************************************************************************************************************************************

    // () >> initialisationPartie >> scoreJoueur, multipleDemande, erreurMultiple **********************************************************************************************
 
    // scoreJoueur, multipleDemande, erreurMultiple >> initialisationValeurs >> scoreJoueur, multipleDemande, erreurMultiple ***************************************************
    scoreJoueur = 0;
    multipleDemande = 2;
    erreurMultiple = false;
 
    // () >> saisirBonneDifficulte >> difficulteJeu ****************************************************************************************************************************
    do
    {
        // (clavier) >> saisirDifficulte >> difficulteJeu **********************************************************************************************************************
        cout << "Choisissez la difficulte du jeu (nombre de reponses correctes pour gagner) : ";
        cin >> difficulteJeu;
        cout << endl;

        // difficulteJeu >> verifDifficulteCorrecte >> () **********************************************************************************************************************
        if (difficulteJeu < 1)
        {
            cout << "La valeur attendue doit etre superieure ou egale a 1. Recommencez." << endl << endl;
        }
    } while (difficulteJeu < 1);
 


    // scoreJoueur, multipleDemande, erreurMultiple, difficulteJeu >> jouerPartie >> [scoreJoueur], [erreurDifficulte] *********************************************************
    while (difficulteJeu > 0)
    {
        // multipleDemande, (clavier) >> saisirMultipleClavier >> multipleClavier **********************************************************************************************
        cout << "Proposez un multiple de " << multipleDemande << " superieur a " << multipleDemande << " : ";
        cin >> multipleClavier;

        // multipleClavier, multipleDemande, difficulteJeu, erreurMultiple >> verifMultipleExistant >> [difficulteJeu], [scoreJoueur], [multipleDemande], [erreurMultiple]
        if (multipleClavier > multipleDemande && multipleClavier % multipleDemande == 0)
        {
            // multipleClavier, scoreJoueur, difficulteJeu >> modifValeursJeu >> multipleDemande, scoreJoueur, difficulteJeu ***************************************************
            multipleDemande = multipleClavier;
            scoreJoueur++;
            difficulteJeu--;

            cout << "Bonne reponse !" << endl << endl;
        }
 
        else
        {
            // () >> erreurDesMultiples >> erreurMultiple *********************************************************************************************************
            cout << "Mauvaise reponse !" << endl << endl;
            erreurMultiple = true;
            break;
        }
    }

    // [erreurMultiple], [scoreJoueur] >> finaliserPartie >> () ***************************************************************************************************************
    if (erreurMultiple)
    {
        // erreurMultiple, scoreJoueur >> partiePerdue >> (écran) *************************************************************************************************************
        cout << "Vous perdez cette partie car votre derniere reponse n'est pas un multiple et/ou n'est pas superieure a " << multipleDemande << "." << endl
         << "Nombre de bonnes reponses: " << scoreJoueur << "." << endl;
    }
    else
    {
        // () >> partieGagnee >> (écran) **************************************************************************************************************************************
        cout << "Bravo vous avez gagne cette partie." << endl;
    }
 
    return 0;
}