# CPP_08
STL Conteneurs, itérateurs, algorithmes


1. Conteneurs Templatés (STL Containers)
Les conteneurs de la STL (Standard Template Library) sont des classes génériques qui stockent des collections d’objets.
Principaux conteneurs en C++98 :

std::vector<T> : Tableau dynamique.
std::list<T> : Liste doublement chaînée.
std::deque<T> : Double-ended queue.
std::stack<T>, std::queue<T> : Adaptateurs de conteneurs.
std::map<Key, T>, std::set<T> : Associatifs (arbre binaire équilibré).
Exemple :

2. Itérateurs
Un itérateur est un objet qui permet de parcourir les éléments d’un conteneur.

begin() : renvoie un itérateur sur le premier élément.
end() : renvoie un itérateur sur la position après le dernier élément.
Exemple :

3. Algorithmes
La STL fournit des fonctions génériques pour manipuler les conteneurs via itérateurs.

std::sort(begin, end)
std::find(begin, end, value)
std::for_each(begin, end, func)
Exemple :

Points clés
Les conteneurs et algorithmes sont génériques grâce aux templates.
Les itérateurs permettent d’utiliser les algorithmes sur n’importe quel conteneur.
En C++98, utilisez typename pour déclarer les types d’itérateurs dépendants d’un template.