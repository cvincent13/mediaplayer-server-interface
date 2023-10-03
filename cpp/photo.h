#ifndef PHOTO_H
#define PHOTO_H

/*!
 * \file photo.h
 * \brief Sous-classe de Multimedia pour les photos
 * \author Vincent_Cedric
 */
#include "multimedia.h"

/*! \class Photo
   * \brief Sous-classe de Multimédia pour les photos
   *
   *  Sous-classe de Multimédia représentant des photos avec des dimensions
   */
class Photo : public Multimedia
{
private:
    float latitude{}, longitude{}; /*!< Flottants représentants les dimensions de la photo*/

public:
  /*!
   *  \brief Constructeur
   *
   *  Constructeur de la classe Photo sans paramètres
   *
   */
    Photo() : latitude{0}, longitude{0}{};

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Photo
     *
     *  \param name : nom de la photo
     *  \param pathname : adresse de la photo
     *  \param latitude : hauteur de la photo
     *  \param longitude : longeur de la photo
     */
    Photo(std::string name, std::string pathname, float latitude, float longitude) :
        Multimedia(name, pathname), latitude{latitude}, longitude{longitude}{};

    /*!
    *  \brief Modifieur de latitude
    *
    *  Modifie la latitude de la photo
    *
    *  \param latitude : nouvelle latitude
    */
    void setLatitude(float latitude);

    /*!
    *  \brief Modifieur de longitude
    *
    *  Modifie la longitude de la photo
    *
    *  \param longitude : nouvelle longitude
    */
    void setLongitude(float longitude);

    /*!
     *  \brief Accesseur de latitude
     *
     *  Accesseur de la latitude de la photo
     *
     *  \return latitude
     */
    float getLatitude() const;

    /*!
     *  \brief Accesseur de longitude
     *
     *  Accesseur de la longitude de la photo
     *
     *  \return longitude
     */
    float getLongitude() const;

    /*!
    *  \brief Afficheur de Photo
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



};

#endif // PHOTO_H
