#include "Node.hpp"

Node::Node() {
    
}

Node::~Node() {
    
}

/**
 * @brief Ajoute un domaine à ce Noeud.
 * @param domain Le domaine à ajouter.
 **/
void Node::add(Domain domain) {
    domainList.push_back(domain);
}

/**
 * @brief Copie la liste des domaines d'un autre Noeud.
 * @param node Le Noeud à copier.
 * @note Utilise l'opérateur "=" de la classe "vector" pour effectuer la copie de Noeud.
 **/
void Node::copy(Node node) {
    domainList = node.getDomainList();
}

/**
 * @brief Vérifie que le Noeud ne soit pas vide.
 * @return Vrai si le Noeud est vide, faux sinon.
 **/
bool Node::isEmpty() {
    return domainList.empty();
}

/**
 * @brief Vérifie que toutes les variables soient affectées.
 * @detail Vérifie que la taille des domaines du Noeud soit égale à 1.
 * @return Vrai si toutes les variables sont affectées, faux sinon.
 **/
bool Node::areAllVariablesAffected() {

    for (Domain d : domainList) {
        if (d.size() != 1) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Renvoie l'indice où se situe le plus petit domaine du Noeud.
 * @return Un entier correspondant à l'indice où se situe le plus petit domaine dans domainList.
 **/
int Node::getSmallerDomain() {
    
    int res = 0;
    for (int i = 0; i < domainList.size(); ++i) {
        if( !(domainList[res].size() > 1) &&  domainList[i].size() > 1) {
            res = i;
        }
        
        if ( (domainList[i].size() < domainList[res].size()) && domainList[i].size() > 1) {
            res = i;
        }
    }
    return res;
}

/**
 * @brief Accesseur pour l'attribut domainList.
 * @return La liste des domaines du Noeud.
 **/
vector<Domain> Node::getDomainList() {
    return domainList;
}

/**
 * @brief Supprime un élément de tous les domaines du Noeud.
 * @param element L'entier à supprimer de tous les domaines.
 * @return Un booléen indiquant si une suppression s'est en effet déroulée.
 **/
bool Node::supElementFromEveryDomain(int element) {
    
    bool ret = false;
    
    for (vector<Domain>::iterator it = domainList.begin(); it != domainList.end(); ++it) {
        if (it->size() > 1) {
            if (it->suppress(element)) {
                ret = true;
            }
        }
    }
    
    return ret;
}

/**
 * @brief Remplace un domaine du Noeud par un unique entier.
 * @param domainNumber L'indice du domaine devant être modifié.
 * @param element L'entier devant remplacer la liste des valeurs du domaine spécifié.
 **/
void Node::replace(int domainNumber, int element) {
    domainList[domainNumber].replace(element);
}

/**
 * @brief Supprime un entier d'un domaine du Noeud.
 * @param domainNumber L'indice du domaine devant subir une suppression.
 * @param element L'entier à supprimer de la liste des valeurs du domaine spécifié.
 **/
void Node::suppress(int domainNumber, int element) {
    domainList[domainNumber].suppress(element);
}

/**
 * @brief Affiche dans la console les différents domaines du Noeud.
 **/
void Node::print() {
    cout << " Noeud : { ";
    for (int i = 0; i < domainList.size(); ++i) {
        domainList[i].print();
    }
    cout << " }" << endl;
}
