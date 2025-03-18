# Atelier de Débogage : Edition C

Durant cet atelier, vous allez explorer du code en C, comprendre son fonctionnement et apprendre à corriger les erreurs. 
L'objectif est de parcourir une série de fichiers, identifier les bugs et les corriger. 
Cet atelier est une excellente occasion de vous familiariser avec la programmation en C (str_to_word_array) et les outils de débogage, comme gdb et valgrind.

## Vue d'Ensemble

Dans cet atelier, vous travaillerez sur plusieurs fichiers C qui implémentent des fonctions de manipulation de chaînes de caractères et de listes chaînées. Les fichiers concernés sont :
- **main.c** : Le point d'entrée du programme qui intègre différentes fonctionnalités telles que le traitement des options, les opérations sur les chaînes et la gestion des listes.
- **lib.h** : Le fichier d'en-tête qui déclare les structures de données et les prototypes des fonctions utilisées dans le projet.
- **string.c** : Fichier qui contient des fonctions personnalisées pour la manipulation de chaînes (`my_strlen`, `my_put_str`, `my_strcmp`, `my_strstr`).
- **sort_and_list.c** : Gère la création, le tri et la manipulation d'une liste chaînée. Pas prioritaire en vue du projet cuddle !
- **str_to_word_array.c** : Fournit une fonction pour découper une chaîne en un tableau de mots.
- **my_ls.h** : Définit des constantes de drapeaux utilisées pour la gestion des options en ligne de commande.
- **Makefile** : Automatisation de la compilation du projet.

## Objectifs

À l'issue de cet atelier, vous serez capables de :
- Identifier et corriger des erreurs courantes telles que les mauvais usages des pointeurs, les conditions de boucles incorrectes et les problèmes de gestion de la mémoire.
- Utiliser des outils de débogage (comme GDB et Valgrind) pour suivre l'exécution du programme et résoudre les bugs.
- Comprendre la structure d'un projet C multi-fichiers et comment ses différents composants interagissent.
- Améliorer vos compétences en lecture, analyse et correction de code.

## Instructions d'Installation

1. **Téléchargez les Fichiers**  
   Assurez-vous d'avoir tous les fichiers nécessaires dans votre répertoire de travail. Si vous utilisez un système de contrôle de version (comme Git), clonez le dépôt contenant ces fichiers.

2. **Compilation du Projet**  
   Utilisez le Makefile fourni pour compiler le code :
   ```bash
   make

Pour compiler il faut installer la librairie lasan : `sudo apt-get install libasan8`
