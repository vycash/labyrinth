**Etape 1** __DONE__

- [X] Réalisation de l'algorithme de génération de labyrinthes parfaits 
   -- [X] Création de la grille de jeu
   -- [X] Implémentation de l'algorithme

- [X] Affichage de la grille/labyrinthe en mode console

**Etape 2** __DONE__

- [X] Réalisation d'un menu qui s'affiche dès l'execution du programme
  -- [X] Le menu attend une entrée de l'utilisateur correspondant à une action à effectuer

- [X] Créer un labyrinthe
  -- [X] l'utilisateur pourra choisir la taille du labyrinthe ainsi que son nom
  -- [X] Création et enregistrement en mémoire au format .cfg
  -- [X] Chargement du labyrinthe en mémoire après création
  -- [X] Retour au menu après création, enregistrement, et chargement

- [X] Charger un labyrinthe
  -- [X] l'utilisateur indique le nom du labyrinthe auquel il souhaite jouer
  -- [X] (Bonus) : une liste des labyrinthes existants pourra lui être proposée
  -- [X] Lecture dans le fichier correspondant au labyrinthe et chargement en mémoire
  -- [X] L'utilisateur est renvoyé eu menu après chargement accompli.

- [X] Jouer
  -- [X] Lancement d'une partie avec un labyrinthe préalablement chargé
  -- [X] déplacement du joueur dans les couloirs du labyrinthe avec z,q,s,d suivie d'entrée
  -- [X] vérification de la fin du jeu (joueur arrive à la fin du labyrinthe)
  -- [X] retour au menu après fin du jeu

**Etape 3**

## 1. **Ajout des objets spéciaux au labyrinthe**

- [X] Définir des constantes pour les nouveaux objets :
    - [X] Valeurs pour la clé (`CLE`), trésor (`TRESOR`), piège (`PIEGE`), etc.
    - [X] Définir les valeurs de bonus (`X`) et de malus (`Y`).

- [ ] Modifier la structure du labyrinthe pour gérer l’état de la clé et des objets si besoin.

- [ ] Créer une fonction pour placer aléatoirement :
    - [X] Une clé (une seule, à ne pas placer sur le joueur, sortie ou mur)
    - [ ] Plusieurs trésors (quantité paramétrable, à ne pas placer sur joueur, clé, sortie, mur)
    - [ ] Plusieurs pièges (quantité paramétrable, même logique)

- [X] Adapter la sauvegarde du labyrinthe pour inclure tous les objets.

- [X] Adapter le chargement pour relire les objets.

## 2. **Gestion de la porte/verrouillage de la sortie**

- [X] Permettre la sortie uniquement si le joueur possède la clé.

- [X] Ajouter un attribut “a_clé” sur le joueur (booléen).

## 3. **Gestion des scores**

- [X] Ajouter une variable “score” dans la structure de jeu.

- [X] Incrémenter/décrémenter le score selon :
    - [X] Bonus ramassé (-X)
    - [X] Malus ramassé (+Y)
    - [X] Nombre de déplacements (score incrémente à chaque déplacement)
    - **le but c'est de faire le moins de mouvements possibles**

- [X] Afficher le score après chaque déplacement.

- [X] Afficher le score final à la fin de la partie.

## 4. **Interaction avec les objets**

- [X] Lorsque le joueur atteint la case clé, la ramasser (mettre “a_clé” à vrai, enlever la clé du labyrinthe)

- [X] Lorsqu’il atteint un trésor, ajouter les points et retirer le trésor du labyrinthe.

- [X] Lorsqu’il atteint un piège, retirer les points et retirer le piège du labyrinthe.

## 5. **Gestion des meilleurs scores (Top 10)**

- [ ] Créer un fichier `nom_labyrinthe.score` pour chaque labyrinthe.

- [ ] À la fin de la partie, lire le top 10 depuis ce fichier.

- [ ] Si le score du joueur est dans le top 10 :
    - [ ] Demander le nom du joueur.
    - [ ] Insérer le score et le nom à la bonne position.
    - [ ] Réécrire le fichier de scores avec les 10 meilleurs.

- [ ] Créer une structure pour stocker un score (nom, score).

## 6. **Affichage des meilleurs scores**

- [ ] Ajouter une nouvelle entrée dans le menu principal ("Afficher le classement des meilleurs scores").

- [ ] Afficher le top 10 pour le labyrinthe actuellement chargé.

## 7. **Interface utilisateur et robustesse**

- [ ] Adapter le menu principal pour intégrer la nouvelle option.
- [ ] Vérifier et gérer tous les cas particuliers (pas de clé, pas de score, fichier inexistant, etc.).
- [ ] Tester la sauvegarde et le rechargement des labyrinthes avec objets.

## 8. **Tests et validation**

- [ ] Vérifier que tous les objets sont placés correctement.
- [ ] Vérifier que le verrouillage/déverrouillage de la sortie fonctionne.
- [ ] Vérifier la gestion du score dans tous les cas.
- [ ] Vérifier la gestion du classement/top 10.
- [ ] Vérifier la robustesse (valeurs invalides, fichiers manquants…).

