#ifndef FILM_H
#define FILM_H

/*!
 * \file film.h
 * \brief Sous-classe de Video avec des chapitres
 * \author Vincent_Cedric
 */
#include "video.h"

/*! \class Film
   * \brief Sous-classe de Vidéo pour les films
   *
   *  Sous-classe de Video représentant des films avec chapitres
   */
class Film : public Video
{
private:
    int * chapters; /*!< Tableau d'entiers représentants les chapitres*/

    int chapters_number; /*!< Nombre de chapitres*/

public:
  /*!
   *  \brief Constructeur
   *
   *  Constructeur de la classe Film sans paramètres
   *
   */
    Film() : chapters{nullptr}, chapters_number{0}{};

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Film
     *
     *  \param name : nom du film
     *  \param pathname : adresse du film
     *  \param duration : durée du film
     *  \param chapters : tableau des chapitres
     *  \param chapters_number : nombre de chapitres
     */
    Film(std::string name, std::string pathname, int duration,
         int * chapters, int chapters_number) :
        Video(name, pathname, duration),
        chapters{chapters}, chapters_number{chapters_number}{};


    /*!
    *  \brief Modifieur de chapters
    *
    *  Modifie les chapitres et leur nombre
    *
    *  \param chapters : nouveaux chapitres
    *  \param chapters_number : nombre de chapitres
    */
    void setChapters(int * chapters, int chapters_number);

    /*!
     *  \brief Accesseur de chapters
     *
     *  Accesseur des chapitres faisant une copie profonde du tableau
     *
     *  \return une copie profonde de chapters
     */
    int * getChapters() const;

    /*!
     *  \brief Accesseur de chapters_number
     *
     *  Accesseur du nombre de chapitres
     *
     *  \return chapters_number
     */
    int getChaptersNumber() const;

    /*!
    *  \brief Afficheur des chapitres
    *
    *  Affiche les chapitres un par un sur le flux de sortie
    *
    *  \param s : flux de sortie
    */
    void displayChapters(std::ostream & s) const;

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe Flim détruisant le tableau des chapitres
     */
    ~Film(){delete[] chapters;};
};

#endif // FILM_H
