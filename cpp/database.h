#ifndef DATABASE_H
#define DATABASE_H

/*!
 * \file database.h
 * \brief Tables de gestion des données
 * \author Vincent_Cedric
 */
#include "film.h"
#include "group.h"
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include <string>
#include <memory>
#include <map>

using MediaPtr = std::shared_ptr<Multimedia>;
using PhotoPtr = std::shared_ptr<Photo>;
using VideoPtr = std::shared_ptr<Video>;
using FilmPtr = std::shared_ptr<Film>;
using GroupPtr = std::shared_ptr<Group>;

/*! \class Database
   * \brief Classe de gestion des données
   *
   *  Classe de gestion des données avec deux tables contenant
   *  les objets Multimedia et les groupes
   */
class Database
{
private:
    std::map<std::string, MediaPtr> mediaTable; /*!< Table des objets Multimedia*/

    std::map<std::string, GroupPtr> groupTable; /*!< Table des groupes*/

public:
  /*!
   *  \brief Database
   *
   *  Constructeur de la classe Database
   *
   */
    Database();

    /*!
     *  \brief Création d'une photo
     *
     *  Crée une nouvelle photo et l'ajoute à la table des
     *  Multimedia
     *
     *  \param name : nom de la photo
     *  \param pathname : adresse de la photo
     *  \param latitude : hauteur de la photo
     *  \param longitude : longeur de la photo
     *  \return la photo créé
     */
    PhotoPtr createPhoto(std::string name, std::string path,
                         float latitude, float longitude);

    /*!
     *  \brief Création d'une video
     *
     *  Crée une nouvelle video et l'ajoute à la table des
     *  Multimedia
     *
     *  \param name : nom de la vidéo
     *  \param pathname : adresse de la vidéo
     *  \param duration : durée de la vidéo
     *  \return la vidéo créé
     */
    VideoPtr createVideo(std::string name, std::string path,
                         int duration);

    /*!
     *  \brief Création d'un film
     *
     *  Crée un nouveau film et l'ajoute à la table des
     *  Multimedia
     *
     *  \param name : nom du film
     *  \param pathname : adresse du film
     *  \param duration : durée du film
     *  \param chapters : tableau des chapitres
     *  \param chapters_number : nombre de chapitres
     *  \return le film créé
     */
    FilmPtr createFilm(std::string name, std::string path,
                       int duration, int * chapters, int chapters_number);

    /*!
     *  \brief Création d'un groupe
     *
     *  Crée un nouveau groupe et l'ajoute à la table des
     *  groupes
     *
     *  \param name : nom du groupe
     *  \return le groupe créé
     */
    GroupPtr createGroup(std::string name);

    /*!
     *  \brief Affichage d'un média
     *
     *  Appelle la méthode d'affichage du média identifié par son nom
     *
     *  \param s : flux de sortie
     *  \param name : nom du média
     */
    void displayMedia(std::ostream & s, std::string name);

    /*!
     *  \brief Joue un média
     *
     *  Appelle la méthode pour jouer le média identifié par son nom
     *
     *  \param s : flux de sortie
     *  \param name : nom du média
     */
    void playMedia(std::ostream & s, std::string name);

    /*!
     *  \brief Affichage d'un groupe
     *
     *  Appelle la méthode d'affichage du groupe identifié par son nom
     *
     *  \param s : flux de sortie
     *  \param name : nom du groupe
     */
    void displayGroup(std::ostream & s, std::string name);
};

#endif // DATABASE_H
