#ifndef VIDEO_H
#define VIDEO_H

/*!
 * \file video.h
 * \brief Sous-classe de Multimedia pour les vidéos
 * \author Vincent_Cedric
 */
#include "multimedia.h"

/*! \class Video
   * \brief Sous-classe de Multimédia pour les vidéos
   *
   *  Sous-classe de Multimédia représentant des vidéos avec une durée
   */
class Video : public Multimedia
{
private:
    int duration{}; /*!< Entier représentant la durée de la vidéo*/

public:
  /*!
   *  \brief Constructeur
   *
   *  Constructeur de la classe Video sans paramètres
   *
   */
    Video() : duration{0}{};

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Video
     *
     *  \param name : nom de la vidéo
     *  \param pathname : adresse de la vidéo
     *  \param duration : durée de la vidéo
     */
    Video(std::string name, std::string pathname, int duration) :
        Multimedia(name, pathname), duration{duration}{};

    /*!
    *  \brief Modifieur de duration
    *
    *  Modifie la durée de la vidéo
    *
    *  \param duration : nouvelle durée
    */
    void setDuration(int duration);

    /*!
     *  \brief Accesseur de duration
     *
     *  Accesseur de la durée de la vidéo
     *
     *  \return duration
     */
    int getDuration() const;

    /*!
    *  \brief Afficheur de Video
    *
    *  Affiche les variables de l'objet sur un flux de sortie
    *
    *  \param s : flux de sortie
    */
    void display(std::ostream & s) const;

    /*!
     *  \brief Joue l'objet
     *
     *  Méthode jouant l'objet à partir d'un appel système
     *
     */
    void play() const;

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Video
     */
    ~Video(){};


};

#endif // VIDEO_H
