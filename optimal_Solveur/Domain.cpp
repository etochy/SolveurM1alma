#include "Domain.hpp"

Domain::Domain() {
    
}

Domain::~Domain() {
    
}

/**
 * @brief Ajoute un entier au domaine.
 * @param element L'entier à ajouter à integerSet.
 * @note Avec cette méthode d'ajout, la liste d'entiers du domaine est automatiquement triée.
 **/
void Domain::add(int element) {
    if (!contains(element)) {
        integerSet.push_back(element);
        sort();
    }
}

/**
 * @brief Copie le domaine passé en paramètre (plus précisément sa liste d'entiers).
 * @param domain Le domaine devant être copié.
 * @note L'opérateur "=" de la classe "vector" est utilisé pour copier la liste d'entiers integerSet.
 **/
void Domain::copy(Domain domain) {
    integerSet = domain.getIntegerSet();
}

/**
 * @brief Remplace la liste des entiers du domaine par un entier passé en paramètre.
 * @param element L'entier devant remplacer la liste.
 **/
void Domain::replace(int element) {
    integerSet.clear();
    integerSet.push_back(element);
}

/**
 * @brief Supprime un entier de la liste d'entiers du domaine.
 * @param element L'entier à supprimer.
 * @return Vrai si un élément a en effet été supprimé, faux sinon.
 * @note Une recherche dichotomique est utilisée pour améliorer les performances.
 **/
bool Domain::suppress(int element) {
    
    bool found = false;
    int begin = 0;
    int end = integerSet.size() - 1;
    int mid = 0;
    
    while ( (!found) && (end - begin >= 0) ) {
        mid = begin + ceil((end - begin) / 2);
        if(element < integerSet[mid]) {
            end = mid - 1;
        }
        else if (element > integerSet[mid]) {
            begin = mid + 1;
        }
        else {
            found = true;
            integerSet.erase(integerSet.begin()+mid);
        }
    }
    
    return found;
    
}

/**
 * @brief Renvoie le premier entier du domaine et le supprime de la liste.
 * @return Le premier entier de integerSet.
 * @note Méthode non utilisée à l'heure actuelle.
 **/
int Domain::pop() {
    int ret = front();
    suppress(ret);
    return ret;
}

/**
 * @brief Renvoie le dernier entier du domaine et le supprime de la liste.
 * @return Le dernier entier de integerSet.
 * @note Méthode non utilisée à l'heure actuelle.
 **/
int Domain::pop_back() {
    int ret = back();
    suppress(ret);
    return ret;
}

/**
 * @brief Renvoie le premier élément de la liste d'entiers du domaine.
 * @return Le premier entier de integerSet.
 * @note Méthode non utilisée à l'heure actuelle.
 **/
int Domain::front() {
    return integerSet.front();
}

/**
 * @brief Renvoie le dernier élément de la liste d'entiers du domaine.
 * @return Le dernier entier de integerSet.
 * @note Méthode non utilisée à l'heure actuelle.
 **/
int Domain::back() {
    return integerSet.back();
}

/**
 * @brief Renvoie la taille de la liste d'entiers du domaine.
 * @return La taille de integerSet.
 * @note Utile pour rendre le code plus lisible.
 **/
int Domain::size() {
    return integerSet.size();
}

/**
 * @brief Accesseur pour la liste d'entiers integerSet.
 * @return Liste d'entiers integerSet.
 **/
vector<int> Domain::getIntegerSet() {
    return integerSet;
}

/**
 * @brief Trie la liste d'entiers du domaine dans l'ordre croissant.
 **/
void Domain::sort() {
    std::sort(integerSet.begin(), integerSet.end());
}

/**
 * @brief Détermine si un entier est présent dans la liste d'entiers du domaine.
 * @return Vrai si l'élément est présent dans integerSet, faux sinon.
 * @note Cette méthode utilise une recherche dichotomique pour de meilleures performances.
 **/
bool Domain::contains(int element){
    
    bool found = false;
    int begin = 0;
    int end = integerSet.size() - 1;
    int mid = 0;
    
    while ( (!found) && (end - begin >= 0) ) {
        mid = begin + ceil((end - begin) / 2);
        if(element < integerSet[mid]) {
            end = mid - 1;
        }
        else if (element > integerSet[mid]) {
            begin = mid + 1;
        }
        else {
            found = true;
        }
    }
    
    return found;
}

/**
 * @brief Ajoute un entier à la liste d'entiers sans restrictions.
 * @note Des doublons sont alors autorisés. Méthode utilisée pour certaines contraintes.
 **/
void Domain::push(int element) {
    integerSet.push_back(element);
    sort();
}

/**
 * @brief Affiche dans la console la liste des entiers d'integerSet.
 **/
void Domain::print() {
    cout << "{";
    for (int i = 0; i < integerSet.size(); ++i) {
        cout << integerSet[i];
    }
    cout << "}";
}

