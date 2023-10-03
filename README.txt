TPs INF224 Cédric VINCENT

Questions traitées:
C++: 1-11
Java: 1-4

Commentaires:
main.cpp contient deux versions du code, la première pour les question 1 à 10 et 
la seconde pour le serveur. On choisit la version à utiliser avec un #define 
VERSION_SERVEUR ou VERSION_SANS_SERVEUR. Pour le serveur, une base de données est
initialisée avec 3 photos, une vidéo, un film et un groupe contenant les photos. 
Les noms respectifs sont 'photo1', 'photo2', 'photo3', 'video1', 'film1', 
'photo_group'. Les images et vidéos se trouvent dans le dossier 'medias'. 

Réponses:
4e étape:
Ce sont des méthodes abstraites que l'on déclare avec 'virtual' et comme égales à 0.
On ne peut plus instancer des objets de cette classe car c'est désormais une classe
abstraite.

5e étape:
C'est le polymorphisme d'héritage qui permet de faire cela.
Dans le cas du C++, il est nécessaire que le tableau contienne des pointeurs vers
les objets.
Ce tableau doit contenir des pointeurs car les pointé sont du type des sous-objets,
ainsi ils n'ont pas tous le même type ce qui n'est pas possible. Les pointeurs ont
tous le même type, celui de pointeurs vers la classe de base. Dans Java, les objets
des tableaux sont toujours stockés sous forme de référence, on peut donc faire des 
listes d'objets.

7e étape:
Film contient un tableau (chapters) dont il faut détruire les pointeurs contenus 
pour éviter les fuites mémoire.
Lorsqu'on copie un objet, les pointeurs de la copie pointent vers les même pointés
que l'original. Ainsi, si on supprime un des deux objets, les pointés de l'autre objet disparaissent. Une solution consiste à faire une copie profonde des objets au
lieu de copies superficielles.

8e étape:
La liste doit être une liste de pointeurs afin qu'ils aient tous le même type. En 
effet, les pointeurs sont de type Multimedia tandis que les pointés sont de type
Video, Photo ou Film. C'est donc nécessaire afin d'utiliser le polymorphisme. Dans
Java, les objets des listes sont toujours stockés sous forme de référence, on peut 
donc faire des listes d'objets.

10e étape:
Pour interdire la création de nouveaux objets avec 'new', on peut rendre les
constructeurs 'private'.  

