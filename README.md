#  MINI-PROJET D’INTRODUCTION A LA PROGRAMMATION : Jeu de Labyrinthe

### Author : QACH Yahya
### Encadrant : DUCASTEL Mathéo

## **But du projet**
Le but du projet est la réalisation d’un générateur de labyrinthe, et de son utilisation dans un jeu
## **Arborescence**
.  
├── headers  
├── minunit  
├── ressources  
│   ├── maps  
│   └── scores  
├── src  
└── tests  

- headers : repertoire contenant les fichier en-tête .h du projet
- minunit : repertoire contenant les fichier en-tête .h de la bibliothèque minunit pour les tests unitaires
- ressources : contient les ressources du fonctionnement du jeu
  - maps : contient les fichiers .cfg qui contiennnt les différents labyrinthes créés
  - scores : contient les fichiers .score qui contiennent les scores des différents joueurs qui ont joué aux labyrinthes
- src : contient l'ensemble des fichiers source .c
- tests : contient les fichiers de test des différentes fonctionnalitées du jeu

TODO.md : toutes les fonctionnalités et taches réalisées.

## **Compilation et execution**

Ce projet a été développé sur une machine linux Ubuntu, et donc la compilation et execution sont fonctionnales et faits pour les machine de type Linux Ubuntu.

- **Pour voir les cybles possibles avec make vous pouvez executer cette commande**:
```
make help
```

- **Pour compiler** : placez vous à la racine du projet et executer la commande:
```
make
```

- **Pour Lance le jeu (programme principal)** : placez vous à la racine du projet et executer la commande:
```
./labyrinthe_game
```

- **Pour lancer les tests** : placez vous à la racine du projet et executer la commande:
```
make test
```

- **Pour générer la documentation** : placez vous à la racine du projet et executer la commande:
```
make doc
```
-la documentation sera générée et mise dans le sous dossier 'doc/' vous pouvez acceder à la documentation depuis un navigateur en utilisant la commande : 
```
make doc-view
```
- ou pour l'afficher manuellement vous devez d'abord générer la documentation puis executer cette commande:
```
firefox --new-window doc/html/index.html
``` 
