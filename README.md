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

## **Compilation et execution**

Ce projet a été développé sur une machine linux Ubuntu, et donc la compilation et execution sont fonctionnales et faits pour les machine de type Linux Ubuntu.

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
la documentation sera générée et mise dans le sous dossier 'doc/'
vous pouvez acceder à la documentation depuis un navigateur en utilisant la commande : 
```
firefox --new-window doc/html/index.html
```

## **Ce projet se fera en quatre étapes :**

__Etape 1 :__
- Réalisation d'un générateur de labyrinthe parfait
- Affichage du labyrinthe en mode console
  
__Etape 2 :__
- Réalisation d'un menu avec plusieurs options :
- **Création de labyrinthe**  : l'utilisateur pourra choisir la taille du labyrinthe ainsi que son nom, et enregistrement en mémoire eu format .cfg et automatiquement chargé . Ensuite l'utilisateur est renvoyé au menu
- **Chargement de labyrinthe** : lors du chargement, l'utilisateur indique le nom du labyrinthe auquel il souhaite jouer ( une liste des labyrinthes existants pourra lui être proposée). Le programme doit alors lire un fichier pour charger un labyrinthe précedemment créé. L'utilisateur est alors renvoyé au menu.
- **Jouer** : Lance une partie avec un labyrinthe préalablement chargé. L’utilisateur peut alors se déplacer dans les couloirs du labyrinthe avec l’aide des touches z, q, s et d suivie de la touche entrée, Lorsque le joueur arrive à la fin du labyrinthe, le programme lui propose à nouveau le menu de démarrage (créer un labyrinthe, charger un labyrinthe, jouer et quitter).
- **Quitter**


## fonctionnement de la fonction init_maze() : 
### Explication étape par étape de la fonction `init_maze`

### 1. Initialisation : On prépare la liste des murs internes

La grille est initialisée avec la valeur -1, toutes les cases au début sont initialisées à -1 ce qui correspond à un mur,
ensuite on place une valeur sur une cellule sur deux, ce qui genere un ensemble de cellules séparées par des murs

**Exemple de grille 3x3 :**
```
# # # # # 
# 1 # 2 # 
# # # # # 
# 3 # 4 # 
# # # # # 
```
Chaque chiffre est une cellule, les chiffres sont les identifiants des céllules, les `#` sont des murs.

### 2. On crée la liste de tous les murs entre les cellules

On ajoute :
- les murs entre chaque cellule et celle de droite
- les murs entre chaque cellule et celle du bas

**Dans l’exemple ci-dessus :**
- Mur entre (1,1) et (1,3) (horizontal, entre cellule 1 et 2)
- Mur entre (1,1) et (3,1) (vertical, entre cellule 1 et 3)
- Mur entre (1,3) et (3,3) (vertical, entre cellule 2 et 4)
- Mur entre (3,1) et (3,3) (horizontal, entre cellule 3 et 4)

### 3. On mélange la liste des murs au hasard

Cela permet d'obtenir un labyrinthe différent à chaque fois.

### 4. On parcourt chaque mur de la liste mélangée

Pour chaque mur :
- On regarde les deux cellules séparées par ce mur.
- **Si elles ont un numéro différent** (donc ne sont pas déjà reliées) :
    - On ouvre le mur (on met un espace entre elles)
    - On fusionne leurs chemins : toutes les cellules du chemin 2 reçoivent l’identifiant du chemin 1.

**Exemple :**
Supposons qu’on commence par le mur entre cellule 1 et 2 :
- Cellule 1 a id=1, cellule 2 a id=2 → différents
- On ouvre le mur entre 1 et 2
- On remplace toutes les cellules qui avaient id=2 par id=1 :
```
# # # # # 
# 1   1 # 
# # # # # 
# 3 # 4 # 
# # # # # 
```

On continue avec les autres murs, en ouvrant seulement si les cellules n’ont pas déjà le même id.

### 5. À la fin, toutes les cellules sont reliées par un unique chemin

Le labyrinthe est parfait : il n’existe qu’un seul chemin entre chaque paire de cellules, pas de boucle.


# Librairie SDL

# Problèmes et solutions
- affichage des scores: puisque les scores sont enregistrés comme <nom,score> il est plus difficile de les lire et les afficher,
  donc j'ai utilisé une structure score qui stocke le score et le nom du joueur qui a atteint ce score, cette sctructure est utilisée lors du tri pour l'affichage des meilleurs scores
