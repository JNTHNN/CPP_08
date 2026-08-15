# Module CPP 08

Ce dernier module de la piscine C++ se concentre sur l'utilisation des **Containers** de la STL (Standard Template Library), les **Algorithmes** (comme `std::find`, `std::sort`) et les **Itérateurs**.

## 1. La fonction générique avec la STL (`ex00`)
Dans le premier exercice, on crée une fonction `easyfind` qui utilise `std::find` pour rechercher une valeur dans un container donné (par exemple un `std::vector`, un `std::list`, etc.).
- **Utilisation des itérateurs** : Plutôt que de renvoyer simplement un booléen ou d'afficher un message, la bonne pratique est de renvoyer l'itérateur pointant vers l'élément trouvé (ou de throw une exception en cas d'échec), car cela permet à la fonction appelante de modifier l'élément ou de connaître sa position.

## 2. Le container intelligent (`ex01`)
L'exercice sur le `Span` vise à stocker une quantité de nombres et à calculer la distance minimale et maximale entre ces nombres.
- **Attention aux Overflows** : Si l'on stocke `INT_MIN` et `INT_MAX`, la différence entre les deux est de `4294967295`. Si la méthode `longestSpan` renvoie un `int` (entier signé), cela produira un dépassement de capacité (overflow) causant un Undefined Behavior et une valeur erronée. Le type de retour attendu est donc un `unsigned int`, et le calcul a été sécurisé via des casts.
- **Remplissage par itérateurs** : Au lieu d'utiliser une boucle itérant sur un vecteur pour appeler `addNumber` à chaque fois (ce qui serait pénalisant à la correction), la fonction `addNumbers` a été transformée en un _Template de plage_ exploitant la fonction native et ultra-optimisée `std::vector::insert`.

## 3. Détourner la `std::stack` (`ex02`)
Le type `std::stack` est un _adaptateur de container_ (souvent basé sur `std::deque`) qui fonctionne en mode LIFO (Last In, First Out). Cependant, le C++ standard lui bloque intentionnellement la capacité d'être itéré.
- Le `MutantStack` contourne ce problème en héritant de `std::stack` et en exposant les itérateurs de son container sous-jacent (qui est une variable `protected` s'appelant `c`).
- L'opérateur d'assignation a été corrigé pour comparer correctement les pointeurs d'instances (`this != &base`) au lieu de comparer stupidement l'intégralité du contenu des deux stacks avec `*this != base`.

## Corrections Apportées
- Refonte de `easyfind` pour renvoyer un itérateur `typename T::iterator`.
- Changement de `int` à `unsigned int` pour les calculs de distances dans le `Span`.
- Implémentation du remplissage de plage optimisé (`addNumbers`) avec la méthode native `insert`.
- Correction de la condition d'auto-assignation du `MutantStack`.