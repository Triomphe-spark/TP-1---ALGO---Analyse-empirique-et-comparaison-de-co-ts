# Détection de Cycles dans une Liste Chaînée — TP n°1

Projet réalisé en **L2 Informatique** à **Nantes Université** (2026–2027) dans le cadre des travaux pratiques d'algorithmique et d'analyse de complexité.

## Objectif du projet

Implémenter en **C++** trois algorithmes différents pour détecter la présence d'un cycle dans une liste chaînée, puis effectuer une **analyse empirique** de leurs coûts en temps (chronométrage et comptage d'opérations élémentaires) et en mémoire afin de comparer leur efficacité.

## Algorithmes implémentés

1. **Parcours double naïf (`est_cyclique1`)**
   - *Principe :* À chaque maillon visité, un parcours secondaire vérifie s'il a déjà été rencontré parmi les maillons précédents.
   - *Complexité :* Temps quadratique \(O(n^2)\), mémoire supplémentaire \(O(1)\).
2. **Marquage / Coloration des maillons (`est_cyclique2`)**
   - *Principe :* Ajout d'un attribut booléen `colore` dans chaque maillon pour mémoriser s'il a déjà été visité lors du parcours.
   - *Complexité :* Temps linéaire \(O(n)\), mémoire supplémentaire \(O(n)\).
3. **Algorithme du lièvre et de la tortue / Floyd (`est_cyclique3`)**
   - *Principe :* Deux pointeurs parcourent la liste simultanément à des vitesses différentes (1 saut pour Théo, 2 sauts pour Lyam) jusqu'à ce qu'ils se rejoignent ou atteignent la fin de la liste.
   - *Complexité :* Temps linéaire \(O(n)\), mémoire supplémentaire \(O(1)\).

## Structure du projet

```text
.
├── cycles.cpp          # Implémentation des listes chaînées, des 3 algorithmes et des tests
├── matplotlibcpp.h     # En-tête C++ pour l'interface avec Matplotlib
└── example_plot.cpp    # Exemple de génération de graphiques comparatifs
```

## Compilation et exécution

### 1. Compilation standard (sans graphique)
```bash
g++ -Wall -std=c++11 cycles.cpp -o cycles
```

### 2. Compilation avec génération de graphiques (`matplotlibcpp.h`)
Utilisez les options de liaison Python/Matplotlib indiquées en commentaire dans `example_plot.cpp` (exemple sous Linux) :
```bash
g++ -std=c++11 cycles.cpp -I/usr/include/python3.10 -lpython3.10 -o cycles
```

### 3. Exécution et mesure du temps système
```bash
./cycles
# Ou avec chronométrage système :
time ./cycles
```

## Analyse et résultats
- **Mesure des coûts :** Évaluation via `clock()` (`<ctime>`), la commande `time`, et un compteur global d'opérations élémentaires (`nbSauts`).
- **Comparaison graphique :** Génération de courbes illustrant l'évolution du nombre de sauts en fonction de la longueur du cycle $\mu$ (pour $\lambda = 5$ fixé et $\mu$ doublant à chaque itération).

## Technologies utilisées
- **Langage :** C++
- **Bibliothèques :** STL (`<ctime>`, `<vector>`), Matplotlib (`matplotlibcpp.h`)
- **Outils :** GCC (`g++`), Git, GitHub, Visual Studio Code
