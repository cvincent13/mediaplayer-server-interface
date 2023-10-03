#ifndef GROUP_H
#define GROUP_H

/*!
 * \file group.h
 * \brief Liste d'objet Multimedia
 * \author Vincent_Cedric
 */
#include "multimedia.h"
#include <list>
#include <memory>

using MediaPtr = std::shared_ptr<Multimedia>;

/*! \class Group
   * \brief Sous-classe de std::list<>
   *
   *  Classe étendant les listes contenant des smart pointeurs sur des Multimedia
   */
class Group : public std::list<MediaPtr>
{
private:
    std::string name; /*!< Nom du groupe*/

public:
  /*!
   *  \brief Constructeur
   *
   *  Constructeur de la classe Group sans paramètres
   *
   */
    Group(){name="";};

    /*!
     *  \brief Constructeur
     *
     *  Constructeur de la classe Group
     *
     *  \param name : nom du groupe
     */
    Group(std::string name){this->name=name;};

    /*!
     *  \brief Accesseur de name
     *
     *  Accesseur du nom du groupe
     *
     *  \return name
     */
    std::string getName() const {return name;};

    /*!
    *  \brief Afficheur du contenu du groupe
    *
    *  Affiche les objets contenus dans le groupe en faisant appel à leurs
    *  méthodes d'affichage
    *
    *  \param s : flux de sortie
    */
    void display(std::ostream & s) const;


};

#endif // GROUP_H
