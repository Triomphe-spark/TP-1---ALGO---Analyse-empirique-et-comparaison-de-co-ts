#include <iostream> // E/S
#include <unistd.h>
#include <vector>

using namespace std;

// type maillon (ne pas modifier)
struct t_maillon
{
    size_t data; // indice du maillon
    bool color = false;
    t_maillon *succ = nullptr; // fin de liste par défaut
};

// type liste chaînée (ne pas modifier)
struct t_liste
{
    t_maillon* tete = nullptr; // liste vide par défaut
};

// genere une liste sans cycle, de longueur n
t_liste genererAcyclique(int n)
{
    t_liste acyclique;

    // premier maillon
    t_maillon *debut = new t_maillon;
    debut->data = 0;
    t_maillon *fin = debut;
    for(size_t i=1; i<n; i++)
    {
        t_maillon *courant = new t_maillon;
        courant->data = i;
        fin->succ = courant;
        fin = courant;
    }
    // s'assurer que la fin pointe bien sur null
    fin->succ = nullptr;

    // créer la liste complète
    acyclique.tete = debut;

    return acyclique;
}

// genere une liste avec lambda maillons avant le cycle
// suivi d'un cycle de longeur mu
// pre: lambda>=1, mu>=1
t_liste genererCyclique(int lambda, int mu)
{
    t_liste cyclique;

    // partie hors du cycle
    t_maillon *debutHC = new t_maillon;
    debutHC->data = 0;
    t_maillon *finHC = debutHC;
    for(size_t i=1; i<lambda; i++)
    {
        t_maillon *courant = new t_maillon;
        courant->data = i;
        finHC->succ = courant;
        finHC = courant;
    }
    // le cycle
    t_maillon *debutCycle = new t_maillon;
    debutCycle->data = lambda;
    t_maillon *finCycle = debutCycle;
    for(size_t i=1; i<mu; i++)
    {
        t_maillon *courant = new t_maillon;
        courant->data = lambda+i;
        finCycle->succ = courant;
        finCycle = courant;
    }
    finCycle->succ = debutCycle; // on ferme le cycle

    // coller les 2 parties pour créer la liste complète
    finHC->succ = debutCycle;
    cyclique.tete = debutHC;

    return cyclique;
}

// affiche une liste chaînée
// pre: liste est bien formée
void afficher(t_liste& liste)
{
    t_maillon* courant = liste.tete;
    while(courant)
    {
        cout << courant->data << endl;
        sleep(1);
        courant = courant->succ;
    }
}

//pre: liste non vide et ne contenat pas de doublons
bool est_cyclique1(t_liste& liste){
    std::vector<size_t> liste_parcourue;
    t_maillon* courant = liste.tete;
    liste_parcourue.push_back(courant->data);
    
    while(courant->succ){
        courant = courant->succ;
        for(size_t i=0; i<liste_parcourue.size(); i++){
            if(courant->data == liste_parcourue.at(i)){
                return true;
            }
        }
        liste_parcourue.push_back(courant->data);
    }
    return false;    
}

bool est_cyclique2(t_liste& liste){
    t_maillon* courant = liste.tete;
    courant->color = true;
    while(courant->succ){
        courant = courant->succ;
        if(courant->color == true){
            return true;
        }
        courant->color = true;
    }
    return false;
}

bool est_cyclique3(t_liste& liste){
    t_maillon* courant1 = liste.tete; // Parcours la liste normalement (un saut) avec i
    t_maillon* courant2 = liste.tete; // Parcours la liste en deux sauts avec j
    size_t i = 0;
    size_t j = 0;

    while(courant2 != nullptr && courant2->succ != nullptr){
        size_t i = courant1->data;
        courant2 = courant2->succ;    // Premiér saut pour j
        size_t j = courant2->data;
        courant2 = courant2->succ;    // Deuxième saut pour j 
        courant1 = courant1->succ;    // Un seul saut pour i 

        if(i >= j){                   // Si j rattrape i ou revient en arrière de i alors qu'il était devant alors il y a cycle
            return true;
        }
    }
    return false;
}

int main()
{
    // Affichage d'une liste acyclique    
    t_liste* listeAcyclique = new t_liste;
    *listeAcyclique = genererAcyclique(5);
    if(!est_cyclique3(*listeAcyclique)){
        cout << "La liste est acyclique. Affichage des elements : " << endl;
    }
    afficher(*listeAcyclique);

    // Affichage d'une liste cyclique    
    t_liste* listeCyclique = new t_liste;
    *listeCyclique = genererCyclique(2, 5);
    if(est_cyclique3(*listeCyclique)){
        cout << "Attention : La liste contient un cycle ! Affichage impossible (sans fin)." << endl;
    }
    afficher(*listeCyclique);

    return 0; // pas d'erreur
}

