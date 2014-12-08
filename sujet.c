/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sujet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 14:40:19 by hhismans          #+#    #+#             */
/*   Updated: 2014/12/08 16:42:53 by hhismans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

auteur mini rush : hhismans

Titre : Snake en console.
temps imparti : 2h.
dossier de rendu : ex00
fichier a rendre : *.c *.h

Ressource disponible :
-Votre libft
-La fonction "getarrowkey(void)" (ci-joint)
-la fonction system("CLEAR"); (#include <stdlib.h>)
-la fonction exit();

man:
fonction int getarrowkey(void):
	le prototype de cette fonction est : int getarrowkey(void);
	return value:
	0 si l'utilisateur n'appuye sur rien.
	1 si l'utilisateur appuye sur Fleche de gauche.
	2 si l'utilisateur appuye sur Fleche du haut.
	3 si l'utilisateur appuye sur Fleche du bas.
	4 si l'utilisateur appuye sur  fleche de droite.
	(cf : main d'exemple)

(/!\ a < b /!\)
Consigne :
Le but de ce mini rush est de recoder le jeu SNAKE.
Vous devez ecrire un programme qui prendra en parametre :
(1)la largeur du plateau
(2)la hauteur du plateau
(3)la vitesse du serpent (en case par seconde par exemple)
(ex ./snake 36 10 3)
Regle du jeu:
-le terrain est delimite par des #
-le serpent est represente par des s
-la pomme est repesente par un a
-le serpent grandi de 1 quand il mange une pomme.
-une fois la pomme mange, la pomme repop aleatoirement sur la map.
(cf: google pour generer de l'aleatoire)
-le serpent meurt quand il rencontre un #.
ex:
####################################
#                                  #
#       ssssss                     #
#            s                     #
#            s                     #
#                                  #
#                     a            #
#                                  #
#                                  #
####################################

idee bonus:
-Systeme de score.
-Utiliser un tableau depuis un fichier (avec des obstacle au millieu par exemple).
-Bonus qui apparait temporairement (lettre b)
-le serpent peut "traverser" les mur (il se teleporte au mur oppose)
-Ajouteur des couleurs.

ex bonus:
####################################
#                                  #
#       ssssss         ##          #
#            s         ##          #
#            s                     #
#                                  #
#      b              a    ##      #
#                          ##      #
#                                  #
####################################
